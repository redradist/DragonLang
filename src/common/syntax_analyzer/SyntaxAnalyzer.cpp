/**
 * @file SyntaxAnalyzer.hpp
 * @author Denis Kotov
 * @date 15 Sep 2018
 * @brief Syntax Analyzer for DragonLanguage
 * @copyright Denis Kotov, MIT License
 */

#include <future>
#include <thread>
#include <string>
#include <functional>
#include <memory>
#include <common/syntax_analyzer/ast/Expression.hpp>
#include <common/syntax_analyzer/ast/matchers/ExpressionMatcher.hpp>
#include <common/syntax_analyzer/ast/Letter.hpp>
#include <common/syntax_analyzer/ast/matchers/LetterMatcher.hpp>
#include "SyntaxAnalyzer.hpp"

namespace dragonlang::common {

SyntaxAnalyzer::SyntaxAnalyzer(const std::unordered_set<std::string> & _files) {
  for (const auto & kFile : _files) {
    lexical_analyzers_[kFile] = std::make_unique<LexicalAnalyzer>(kFile);
    auto task = std::packaged_task<void(const std::string &)>(
        std::bind(&SyntaxAnalyzer::parseFile, this, kFile));
    task_statuses_[kFile] = std::move(task.get_future());
    tasks_[kFile] = std::move(task);
    std::thread([this, kFile] {
      auto & task = tasks_[kFile];
      task(kFile);
    }).detach();
  }
}

SyntaxAnalyzer::~SyntaxAnalyzer() {
  for (auto & taskStatus : task_statuses_) {
    taskStatus.second.wait();
  }
}

bool isAmbigious(bool *boolAry, int size) {
  bool areAnyTrue = false;
  bool areTwoTrue = false;
  for(int i = 0; (!areTwoTrue) && (i < size); i++) {
    areTwoTrue = (areAnyTrue && boolAry[i]);
    areAnyTrue |= boolAry[i];
  }
  return ((areAnyTrue) && (!areTwoTrue));
}

template<typename TO, typename FROM>
std::unique_ptr<TO> static_pointer_cast (std::unique_ptr<FROM>&& old){
  return std::unique_ptr<TO>{static_cast<TO*>(old.release())};
}

template<typename TO, typename FROM>
std::unique_ptr<TO> dynamic_pointer_cast (std::unique_ptr<FROM>&& old) {
  return std::unique_ptr<TO>{dynamic_cast<TO*>(old.release())};
}

void SyntaxAnalyzer::parseFile(const std::string & _file) {
  using dragonlang::common::ast::Matchers::IMatcher;
  using dragonlang::common::ast::Matchers::MatcherBuilderBase;
  using dragonlang::common::ast::Matchers::ExpressionMatcher;
  using dragonlang::common::ast::Expression;
  using dragonlang::common::ast::Matchers::LetterMatcher;
  using dragonlang::common::ast::Letter;

  if (lexical_analyzers_.count(_file) > 0) {
    auto & lexicalAnalyzer = lexical_analyzers_[_file];

    std::vector<std::unique_ptr<IMatcher>> prevPartMatches;
    std::vector<std::unique_ptr<IMatcher>> prevFullMatches;
    while (auto token = lexicalAnalyzer->getNextToken()) {
      token_buffer_.push_back(token);

      std::vector<std::unique_ptr<IMatcher>> partMatches;
      std::vector<std::unique_ptr<IMatcher>> fullMatches;
      std::vector<std::unique_ptr<IMatcher>> matchers;
      matchers.push_back(std::make_unique<LetterMatcher>(token_buffer_, 0));
//      matchers.push_back(std::make_unique<ExpressionMatcher>(token_buffer_, 0));

      uint16_t numMatches = 0;
      for (auto& matcher : matchers) {
        if (matcher->isMatch()) {
          numMatches += 1;
          if (matcher->isFullMatch()) {
            fullMatches.push_back(std::move(matcher));
          } else {
            partMatches.push_back(std::move(matcher));
          }
        }
      }
      assert(fullMatches.size() <= 1);

      if (fullMatches.empty() && !prevFullMatches.empty()) {
        switch (prevFullMatches.front()->getId()) {
          case ASTId::Expression:break;
          case ASTId::Letter: {
            auto matcher = dynamic_pointer_cast<MatcherBuilderBase<Letter>>(std::move(prevFullMatches.front()));
            auto letter = matcher->build();
            break;
          }
          case ASTId::ConstNumber:break;
          case ASTId::Function:break;
        }
        token_buffer_.erase(token_buffer_.begin(), token_buffer_.end()-1);
      }
    }
  }
}

// <fun> ::= <keyword:"fun"> <symbol> <special:"("> <special:")"> <special:"{"> <fun_body> <special:"}">

}
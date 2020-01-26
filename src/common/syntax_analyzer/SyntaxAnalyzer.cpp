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

#include "SyntaxAnalyzer.hpp"

namespace DragonLang::Common {

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

void SyntaxAnalyzer::parseFile(const std::string & _file) {
  if (lexical_analyzers_.count(_file) > 0) {
    auto & lexicalAnalyzer = lexical_analyzers_[_file];
    while (auto token = lexicalAnalyzer->getNextToken()) {
      token_buffer_.push_back(token);
      if (auto matchRes = matchWithLetter(token)) {

      }
    }
  }
}

SyntaxAnalyzer::MatchResult
SyntaxAnalyzer::matchWithExpression(
    std::optional<LexicalAnalyzer::Token> anOptional) {
  return MatchResult{true, true};
}

SyntaxAnalyzer::MatchResult
SyntaxAnalyzer::matchWithFunction() {
  return MatchResult{};
}

// <var> ::= < keyword: let > < symbol > < special: = > <expr>;
SyntaxAnalyzer::MatchResult
SyntaxAnalyzer::matchWithLetter(
    std::optional<LexicalAnalyzer::Token> _token) {
  MatchResult result{true, false};
  do {
    auto firstToken = token_buffer_[0];
    if (TokenId::Keyword != firstToken.value().id_ ||
        "let" != firstToken.value().item_) {
      result.is_matched_ = false;
      break;
    }
    {
      if (token_buffer_.size() <= 1) break;
      auto token = token_buffer_[1];
      if (TokenId::SymbolId != token.value().id_) {
        result.is_matched_ = false;
        break;
      }
    }
    {
      if (token_buffer_.size() <= 2) break;
      auto token = token_buffer_[2];
      if (TokenId::SpecialSymbol != token.value().id_ ||
          "=" != token.value().item_) {
        result.is_matched_ = false;
        break;
      }
    }
    result.is_finished_ = true;
  } while (false);
  return result;
}

}
/**
 * @file SyntaxAnalyzer.cpp
 * @author Denis Kotov
 * @date 15 Sep 2018
 * @brief Syntax Analyzer for DragonLanguage
 * @copyright Denis Kotov, MIT License
 */

#ifndef DRAGONLANGUAGE_SYNTAXANALYZER_HPP
#define DRAGONLANGUAGE_SYNTAXANALYZER_HPP

#include <unordered_map>
#include <future>

#include <common/lexical_analyzer/LexicalAnalyzer.hpp>
#include "AST.hpp"

namespace DragonLang::Common {

class SyntaxAnalyzer {
 public:
  SyntaxAnalyzer(const std::unordered_set<std::string> & _files);
  virtual ~SyntaxAnalyzer();

  void parseFile(const std::string & _file);

 protected:
  struct MatchResult {
    bool is_matched_ = false;
    bool is_finished_ = false;

    explicit operator bool () const {
      return is_matched_;
    }
  };

  MatchResult matchWithExpression(std::optional<LexicalAnalyzer::Token> anOptional);
  MatchResult matchWithFunction();
  MatchResult matchWithLetter(std::optional<LexicalAnalyzer::Token> _token);

  std::optional<AST::Id> prev_matched_ast_item_;
  std::vector<LexicalAnalyzer::OptionalToken> token_buffer_;
  std::unordered_map<std::string,
                     std::shared_ptr<LexicalAnalyzer>> lexical_analyzers_;
  std::unordered_map<std::string,
                     std::packaged_task<void(const std::string &)>> tasks_;
  std::unordered_map<std::string,
                     std::future<void>> task_statuses_;

};

using Parser = SyntaxAnalyzer;

}

#endif  // DRAGONLANGUAGE_SYNTAXANALYZER_HPP

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
#include "common/syntax_analyzer/SyntaxDefinitions.hpp"

namespace DragonLang::Common {

class SyntaxAnalyzer {
 public:
  SyntaxAnalyzer(const std::unordered_set<std::string> & _files);
  virtual ~SyntaxAnalyzer();

  void parseFile(const std::string & _file);

 protected:
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

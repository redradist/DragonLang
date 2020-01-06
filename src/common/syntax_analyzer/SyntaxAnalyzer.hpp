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

#include <common/lexical_analyzer/LexicalAnalyzer.hpp>

namespace DragonLang::Common {

class SyntaxAnalyzer {
 public:
  SyntaxAnalyzer(const std::string & _file);
  virtual ~SyntaxAnalyzer() = default;

  void parseFile(const std::string & _file);

 protected:
  std::unordered_map<std::string,
                     std::shared_ptr<LexicalAnalyzer>> lexical_analyzers_;
};

using Parser = SyntaxAnalyzer;

}

#endif  // DRAGONLANGUAGE_SYNTAXANALYZER_HPP

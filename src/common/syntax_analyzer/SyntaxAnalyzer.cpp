/**
 * @file SyntaxAnalyzer.hpp
 * @author Denis Kotov
 * @date 15 Sep 2018
 * @brief Syntax Analyzer for DragonLanguage
 * @copyright Denis Kotov, MIT License
 */

#include <future>
#include <thread>
#include "SyntaxAnalyzer.hpp"

namespace DragonLang::Common {

SyntaxAnalyzer::SyntaxAnalyzer(const std::string & _file) {
  lexical_analyzers_[_file] = std::make_unique<LexicalAnalyzer>(_file);
  auto task = std::packaged_task<void(const std::string &)>(
      std::bind(&SyntaxAnalyzer::parseFile, this, _file));
  auto taskStatus = task.get_future();
}

void SyntaxAnalyzer::parseFile(const std::string & _file) {
  if (lexical_analyzers_.count(_file) > 0) {
    auto lexicalAnalyzer = std::make_shared<LexicalAnalyzer>(_file);
    lexical_analyzers_[_file] = lexicalAnalyzer;
    while (auto token = lexicalAnalyzer->getNextToken()) {

    }
  }
}

}
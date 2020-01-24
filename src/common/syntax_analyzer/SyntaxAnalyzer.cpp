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

    }
  }
}

}
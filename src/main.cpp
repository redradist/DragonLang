/**
 * @file main.cpp
 * @author Denis Kotov
 * @date 26 Aug 2018
 * @brief Main file for starting Dragon tool
 * @copyright Denis Kotov, MIT License
 */

#include <iostream>
#include <fstream>      // std::filebuf
#include <string>
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Dragon.hpp"
#include "common/lexical_analyzer/LexicalAnalyzer.hpp"
#include <iterator>

using DragonLang::Dragon;
using DragonLang::Common::LexicalAnalyzer;

int main(int _argc, char ** _argv) {
//  Dragon dragon;
//  dragon.processFile(std::string("/home/redra/Projects/DragonLanguage/Kingdom/tests"
//                                 "/common/lexical_analyzer/files/VarNumbers.me"));
  LexicalAnalyzer analyzer(std::string("/home/redra/Projects/DragonLanguage/Kingdom/tests"
                                       "/common/lexical_analyzer/files/Strings.me"));
  auto tokens = analyzer.getAllTokens();
  return 0;
}

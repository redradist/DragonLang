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
#include "common/syntax_analyzer/SyntaxAnalyzer.hpp"
#include <iterator>

using dragonlang::Dragon;
using dragonlang::common::SyntaxAnalyzer;

int main(int _argc, char ** _argv) {
//  Dragon dragon;
//  dragon.processFile(std::string("/home/redra/Projects/DragonLanguage/Kingdom/test"
//                                 "/common/lexical_analyzer/files/VarNumbers.me"));
  SyntaxAnalyzer parser({std::string("/home/redra/Projects/DragonLanguage/Kingdom/test"
                                       "/common/lexical_analyzer/files/VarNumbers.me")});
  return 0;
}

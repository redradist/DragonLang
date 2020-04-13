/**
 * @file Dragon.hpp
 * @author Denis Kotov
 * @date 26 Aug 2018
 * @brief Header file for Dragon class that is the main entry point for Dragon Language
 * @copyright Denis Kotov, MIT License
 */

#ifndef DRAGON2_DRAGON_HPP
#define DRAGON2_DRAGON_HPP

#include <string>
#include <vector>

namespace dragonlang {

class Dragon {
 public:
  // [Ctor/Dtor]
  Dragon();
  ~Dragon();

 public:
  // API of Dragon class
  void processFile(const std::string & _file,
                   const std::vector<std::string> & _options = {});
};

}

#endif  // DRAGON2_DRAGON_HPP

//
// Created by redra on 03.09.18.
//

#ifndef DRAGONLANGUAGE_ISTREAMRANGE_HPP
#define DRAGONLANGUAGE_ISTREAMRANGE_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

namespace DragonLang::Common {

class InStreamRange {
 public:
  InStreamRange(const std::string & _istream)
      : stream_buffer_{_istream} {
  }

  InStreamRange(std::string && _istream)
      : stream_buffer_{std::move(_istream)} {
  }

  std::string::const_iterator begin() const {
    return stream_buffer_.begin() + pos_;
  }

  std::string::const_iterator end() const {
    return stream_buffer_.end();
  }

  char getNextChar() const {
    return *begin();
  }

  void moveNext(const int _pos = 1) {
    pos_ += _pos;
  }

  void moveBack(const int _pos = 1) {
    pos_ -= _pos;
  }

  operator bool () {
    return !stream_buffer_.empty() && begin() != end();
  }

  std::string toString() const {
    return stream_buffer_.substr(pos_);
  }

 private:
  std::string stream_buffer_;
  int pos_ = 0;
};

}

#endif //DRAGONLANGUAGE_ISTREAMRANGE_HPP

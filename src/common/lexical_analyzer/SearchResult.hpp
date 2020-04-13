//
// Created by redra on 03.09.18.
//

#ifndef DRAGONLANGUAGE_SEARCHRESULT_HPP
#define DRAGONLANGUAGE_SEARCHRESULT_HPP

#include <regex>

#include "LexicalDefinitions.hpp"

namespace dragonlang::common {

struct SearchResult {
  bool is_found_ = false;
  TokenId id_;
  std::smatch match_;

  bool operator ==(SearchResult const & _result) const {
    return (match_.size() >= 2 && _result.match_.size() >= 2) &&
            match_[2].str().size() == _result.match_[2].str().size();
  }

  bool operator >(SearchResult const & _result) const {
    return (is_found_ && !_result.is_found_) ||
           ((match_.size() >= 2 && _result.match_.size() >= 2) &&
             match_[2].str().size() > _result.match_[2].str().size());
  }

  bool operator <(SearchResult const & _result) const {
    return (!is_found_ && _result.is_found_) ||
           ((match_.size() >= 2 && _result.match_.size() >= 2) &&
             match_[2].str().size() > _result.match_[2].str().size());
  }

  operator bool () const {
    return is_found_;
  }
};

}

#endif //DRAGONLANGUAGE_SEARCHRESULT_HPP

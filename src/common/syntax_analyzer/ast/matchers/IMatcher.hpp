//
// Created by redra on 04.04.20.
//

#ifndef DRAGONLANGUAGE_IMATCHER_HPP
#define DRAGONLANGUAGE_IMATCHER_HPP

#include <common/syntax_analyzer/ast/Id.hpp>

namespace DragonLang::Common::AST::Matchers {

class IMatcher {
 public:
  virtual ~IMatcher() = 0;
  virtual ASTId getId() const = 0;
  bool isMatch() const;
  bool isFullMatch() const;

 protected:
  bool is_matched_ = true;
  bool is_finished_ = false;
};

inline
IMatcher::~IMatcher() {
}

inline
bool IMatcher::isMatch() const {
  return is_matched_;
}

inline
bool IMatcher::isFullMatch() const {
  return is_finished_;
}

}

#endif //DRAGONLANGUAGE_IMATCHER_HPP

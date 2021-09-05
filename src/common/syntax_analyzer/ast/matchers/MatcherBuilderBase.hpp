//
// Created by redra on 04.04.20.
//

#ifndef DRAGONLANGUAGE_MATCHERBUILDERBASE_HPP
#define DRAGONLANGUAGE_MATCHERBUILDERBASE_HPP

#include <common/syntax_analyzer/SyntaxDefinitions.hpp>
#include "IMatcher.hpp"

namespace dragonlang::common::ast::Matchers {

template <typename T>
class MatcherBuilderBase : public IMatcher {
 public:
  virtual std::unique_ptr<T> build() const = 0;
};

}

#endif //DRAGONLANGUAGE_MATCHERBUILDERBASE_HPP

//
// Created by redra on 04.04.20.
//

#ifndef DRAGONLANGUAGE_EXPRESSIONMATCHER_HPP
#define DRAGONLANGUAGE_EXPRESSIONMATCHER_HPP

#include <common/lexical_analyzer/LexicalAnalyzer.hpp>
#include <common/syntax_analyzer/ast/Expression.hpp>
#include "MatcherBuilderBase.hpp"

namespace dragonlang::common::ast::Matchers {

class ExpressionMatcher : public MatcherBuilderBase<Expression> {
 public:
  // <var> ::= <let>
  //         | <const_number>
  ExpressionMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos);
  [[nodiscard]]
  ASTId getId() const override;
  [[nodiscard]]
  std::unique_ptr<Expression> build() const override;
};

inline
ASTId ExpressionMatcher::getId() const {
  return ASTId::Expression;
}

}

#endif //DRAGONLANGUAGE_EXPRESSIONMATCHER_HPP

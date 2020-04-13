//
// Created by redra on 04.04.20.
//

#include "ExpressionMatcher.hpp"

namespace dragonlang::common::ast::Matchers {

/*
 * <expression> ::= <symbol>
 *                | <const_number>
 */
ExpressionMatcher::ExpressionMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos) {
  is_matched_ = true;
  is_finished_ = true;
  do {
    std::optional<uint64_t> successExpressionMatchEndPos;
    std::optional<ExpressionMatcher> successExpressionMatch;
    std::vector<LexicalAnalyzer::OptionalToken> exprTokenBuffer;
    for (uint64_t pos = 0; pos < _tokenBuffer.size(); ++pos) {
      exprTokenBuffer.push_back(_tokenBuffer[pos]);
      auto matcher = ExpressionMatcher{exprTokenBuffer, 0};
      if (matcher.isFullMatch()) {
        successExpressionMatchEndPos = pos + 1;
        successExpressionMatch = matcher;
      } else if (!matcher.isMatch()) {
        is_matched_ = false;
        break;
      }
    }
  } while (false);
}

Expression
ExpressionMatcher::build() const {
  return Expression{};
}

}
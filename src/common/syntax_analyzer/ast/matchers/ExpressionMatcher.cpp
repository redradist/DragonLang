//
// Created by redra on 04.04.20.
//

#include "ExpressionMatcher.hpp"

namespace DragonLang::Common::AST::Matchers {

ExpressionMatcher::ExpressionMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos) {
  is_matched_ = true;
  is_finished_ = true;
}

Expression
ExpressionMatcher::build() const {
  return Expression{};
}

}
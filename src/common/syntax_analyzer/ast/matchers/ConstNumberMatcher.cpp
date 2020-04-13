//
// Created by redra on 04.04.20.
//

#include "ConstNumberMatcher.hpp"

namespace dragonlang::common::ast::Matchers {

/*
 * <const_number> ::= <number> <token:special:"."> <const_number>
 *                  | <const_number> <token:symbol:"e"> <const_number>
 *                  | <const_number> <token:special:"*"> <token:special:"*"> <const_number>
 */
ConstNumberMatcher::ConstNumberMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos) {

}

ConstNumber
ConstNumberMatcher::build() const {
  return ConstNumber{};
}

}

//
// Created by redra on 04.04.20.
//

#include "NumberConstMatcher.hpp"

namespace dragonlang::common::ast::Matchers {

/*
 * number_const
 * ::= <number_const>
 * ::= <special_symbol:"+"> <number_const>
 * ::= <special_symbol:"-"> <number_const>
 * ::= number_const <special_symbol:"e"> number_const
 * ::= number_const <special_symbol:"*"> <special_symbol:"*"> number_const
 */
NumberConstMatcher::NumberConstMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos) {
  do {
    std::string name;
    uint64_t nextPos = _startPos;
    {
      auto firstToken = _tokenBuffer[nextPos++];
      if (TokenId::NumberConst != firstToken.value().id_) {
        is_matched_ = false;
        break;
      }
    }
    {
      if (_tokenBuffer.size() <= (nextPos)) break;
      auto token = _tokenBuffer[nextPos++];
      if (TokenId::SymbolId != token.value().id_) {
        is_matched_ = false;
        break;
      }
      name = token.value().item_;
    }
    {
      if (_tokenBuffer.size() <= (nextPos)) break;
      auto token = _tokenBuffer[nextPos++];
      if (TokenId::SpecialSymbol != token.value().id_ ||
          "=" != token.value().item_) {
        is_matched_ = false;
        break;
      }
    }
    auto size = _tokenBuffer.size();
    is_finished_ = _tokenBuffer.size() <= nextPos;
    if (is_finished_) {
      name_ = name;
    }
  } while (false);
}

std::unique_ptr<NumberConst>
NumberConstMatcher::build() const {
  return std::make_unique<NumberConst>();
}

}

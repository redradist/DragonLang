//
// Created by redra on 04.04.20.
//

#include "LetterMatcher.hpp"
#include "ExpressionMatcher.hpp"

namespace dragonlang::common::ast::Matchers {

// <letter> ::= <keyword:"let"> <symbol> <special:"="> <expr> [special:";"]
LetterMatcher::LetterMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos) {
  do {
    std::string name;
    uint64_t nextPos = _startPos;
    {
      auto firstToken = _tokenBuffer[nextPos++];
      if (TokenId::Keyword != firstToken.value().id_ ||
          "let" != firstToken.value().item_) {
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
    std::optional<uint64_t> successExpressionMatchEndPos;
    std::optional<ExpressionMatcher> successExpressionMatch;
    std::vector<LexicalAnalyzer::OptionalToken> exprTokenBuffer;
    for (uint64_t pos = nextPos; pos < _tokenBuffer.size(); ++pos) {
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
    if (!successExpressionMatchEndPos) break;
    nextPos = *successExpressionMatchEndPos;
    if (_tokenBuffer.size() > (nextPos)) {
      auto token = _tokenBuffer[nextPos++];
      if (TokenId::SpecialSymbol != token.value().id_ ||
          ";" != token.value().item_) {
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

Letter
LetterMatcher::build() const {
  return Letter{*name_};
}

}

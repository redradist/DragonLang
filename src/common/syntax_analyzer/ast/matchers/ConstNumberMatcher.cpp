//
// Created by redra on 04.04.20.
//

#include "ConstNumberMatcher.hpp"

namespace DragonLang::Common::AST::Matchers {

ConstNumberMatcher::ConstNumberMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos) {

}

ConstNumber
ConstNumberMatcher::build() const {
  return ConstNumber{};
}

}

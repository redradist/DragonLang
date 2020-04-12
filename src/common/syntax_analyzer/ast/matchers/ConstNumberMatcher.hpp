//
// Created by redra on 04.04.20.
//

#ifndef DRAGONLANGUAGE_CONSTNUMBERMATCHER_HPP
#define DRAGONLANGUAGE_CONSTNUMBERMATCHER_HPP

#include <common/lexical_analyzer/LexicalAnalyzer.hpp>
#include <common/syntax_analyzer/ast/ConstNumber.hpp>
#include "MatcherBuilderBase.hpp"

namespace DragonLang::Common::AST::Matchers {

class ConstNumberMatcher : public MatcherBuilderBase<ConstNumber> {
 public:
  // <const_number> ::=
  ConstNumberMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos);
  ASTId getId() const override;
  ConstNumber build() const override;
};

inline
ASTId ConstNumberMatcher::getId() const {
  return ASTId::ConstNumber;
}

}

#endif //DRAGONLANGUAGE_CONSTNUMBERMATCHER_HPP

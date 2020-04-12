//
// Created by redra on 04.04.20.
//

#ifndef DRAGONLANGUAGE_LETTERMATCHER_HPP
#define DRAGONLANGUAGE_LETTERMATCHER_HPP

#include <common/lexical_analyzer/LexicalAnalyzer.hpp>
#include <common/syntax_analyzer/ast/Letter.hpp>
#include "MatcherBuilderBase.hpp"

namespace DragonLang::Common::AST::Matchers {

class LetterMatcher : public MatcherBuilderBase<Letter> {
 public:
  // <var> ::= <keyword:"let"> <symbol> <special:"="> <expr> [special:";"]
  LetterMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos);
  ASTId getId() const override;
  Letter build() const override;

 private:
  std::optional<std::string> name_;
};

inline
ASTId LetterMatcher::getId() const {
  return ASTId::Letter;
}

}

#endif //DRAGONLANGUAGE_LETTERMATCHER_HPP

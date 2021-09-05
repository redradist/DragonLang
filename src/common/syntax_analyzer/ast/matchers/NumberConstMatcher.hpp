//
// Created by redra on 04.04.20.
//

#ifndef DRAGONLANGUAGE_NUMBERCONSTMATCHER_HPP
#define DRAGONLANGUAGE_NUMBERCONSTMATCHER_HPP

#include <common/lexical_analyzer/LexicalAnalyzer.hpp>
#include <common/syntax_analyzer/ast/NumberConst.hpp>
#include "MatcherBuilderBase.hpp"

namespace dragonlang::common::ast::Matchers {

class NumberConstMatcher : public MatcherBuilderBase<NumberConst> {
 public:
  NumberConstMatcher(std::vector<LexicalAnalyzer::OptionalToken> _tokenBuffer, uint64_t _startPos);
  [[nodiscard]]
  ASTId getId() const override;
  [[nodiscard]]
  std::unique_ptr<NumberConst> build() const override;

 private:
  std::string name_;
};

inline
ASTId NumberConstMatcher::getId() const {
  return ASTId::ConstNumber;
}

}

#endif //DRAGONLANGUAGE_NUMBERCONSTMATCHER_HPP

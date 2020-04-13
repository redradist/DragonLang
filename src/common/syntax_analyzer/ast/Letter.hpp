//
// Created by redra on 26.01.20.
//

#ifndef DRAGONLANGUAGE_LETTER_HPP
#define DRAGONLANGUAGE_LETTER_HPP

#include <vector>
#include <optional>
#include <common/lexical_analyzer/LexicalAnalyzer.hpp>
#include <common/syntax_analyzer/SyntaxAnalyzer.hpp>
#include "Id.hpp"
#include "Expression.hpp"

namespace dragonlang::common::ast {

/// LetterExpression - Expression class for referencing a variable, like "a"
class Letter : public Expression {
 public:
  Letter(const std::string &Name) : Name(Name) {}

  llvm::Value *codegen(llvm::IRBuilder<> & builder) override;

 private:
  std::string Name;
};

}

#endif //DRAGONLANGUAGE_LETTER_HPP

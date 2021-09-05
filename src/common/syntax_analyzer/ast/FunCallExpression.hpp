//
// Created by redra on 13.04.20.
//

#ifndef DRAGONLANG_FUNCALLEXPRESSION_HPP
#define DRAGONLANG_FUNCALLEXPRESSION_HPP

#include "Expression.hpp"

namespace dragonlang::common::ast {

///// FunCallExpression - Expression class for function calls
class FunCallExpression : public Expression {
 public:
  FunCallExpression(std::string _callee,
                    std::vector<std::unique_ptr<Expression>> _args);

  llvm::Value *codegen(llvm::IRBuilder<> &builder) override;

 private:
  std::string callee_;
  std::vector<std::unique_ptr<Expression>> args_;
};

}

#endif //DRAGONLANG_FUNCALLEXPRESSION_HPP
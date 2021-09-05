//
// Created by redra on 13.04.20.
//

#include "FunCallExpression.hpp"

#include <utility>

namespace dragonlang::common::ast {

FunCallExpression::FunCallExpression(
    std::string _callee,
    std::vector<std::unique_ptr<Expression>> _args)
    : callee_(std::move(_callee))
    , args_(std::move(_args)) {
}

llvm::Value *FunCallExpression::codegen(llvm::IRBuilder<> & builder) {
//  // Look up the name in the global module table.
//  llvm::Function *calleeFun = TheModule->getFunction(callee_);
//  if (!calleeFun)
//    return LogErrorV("Unknown function referenced");
//
//  // If argument mismatch error.
//  if (calleeFun->arg_size() != args_.size())
//    return LogErrorV("Incorrect # arguments passed");
//
//  std::vector<llvm::Value*> ArgsV;
//  for (unsigned i = 0, e = args_.size(); i != e; ++i) {
//    ArgsV.push_back(args_[i]->codegen(builder));
//    if (!ArgsV.back())
//      return nullptr;
//  }
//
//  return builder.CreateCall(CalleeF, ArgsV, "calltmp");

  return nullptr;
}

}

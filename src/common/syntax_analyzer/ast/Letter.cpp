//
// Created by redra on 26.01.20.
//

#include "Letter.hpp"

namespace dragonlang::common::ast {

llvm::Value* Letter::codegen(llvm::IRBuilder<> & builder) {
  // Look this variable up in the function.
  llvm::Value* V;
//  llvm::Value* V = NamedValues[Name];
//  if (!V)
//    return LogErrorV("Unknown variable name");
  return V;
}

}

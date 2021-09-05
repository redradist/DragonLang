//
// Created by redra on 04.04.20.
//

#ifndef DRAGONLANGUAGE_EXPRESSION_HPP
#define DRAGONLANGUAGE_EXPRESSION_HPP

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

namespace dragonlang::common::ast {

/// Expression - Base class for all expression nodes
class Expression {
 public:
  virtual ~Expression() = default;

  virtual llvm::Value *codegen(llvm::IRBuilder<> &builder) = 0;
};

}

#endif //DRAGONLANGUAGE_EXPRESSION_HPP

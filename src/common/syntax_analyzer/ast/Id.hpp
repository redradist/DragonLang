//
// Created by redra on 07.01.20.
//

#ifndef DRAGONLANGUAGE_ID_HPP
#define DRAGONLANGUAGE_ID_HPP

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

///// Expression - Base class for all expression nodes
//class Expression {
// public:
//  virtual ~Expression() = default;
//
//  virtual llvm::Value *codegen(llvm::IRBuilder<> & builder) = 0;
//};
//
///// NumberValueExpression - Expression class for numeric literals like "1.0"
//class NumberValueExpression : public Expression {
// public:
//  NumberValueExpression(int intPart, unsigned fracPart, int expPart)
//    : IntPart(intPart)
//    , FracPart(fracPart)
//    , ExpPart(expPart) {}
//
// private:
//  double IntPart;
//  double FracPart;
//  double ExpPart;
//};
//
///// BinaryExpression - Expression class for a binary operator
//class BinaryExpression : public Expression {
//  char Op;
//  std::unique_ptr<Expression> LHS, RHS;
//
// public:
//  BinaryExpression(char Op, std::unique_ptr<Expression> LHS,
//                std::unique_ptr<Expression> RHS)
//      : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
//
//  llvm::Value *codegen(llvm::IRBuilder<> & builder) override;
//};
//
///// FunCallExpression - Expression class for function calls
//class FunCallExpression : public Expression {
//  std::string Callee;
//  std::vector<std::unique_ptr<Expression>> Args;
//
// public:
//  FunCallExpression(const std::string &Callee,
//                    std::vector<std::unique_ptr<Expression>> Args)
//      : Callee(Callee), Args(std::move(Args)) {}
//
//  llvm::Value *codegen(llvm::IRBuilder<> & builder) override;
//};
//
///// FunPrototype - This class represents the "prototype" for a function,
///// which captures its name, and its argument names (thus implicitly the number
///// of arguments the function takes)
//class FunPrototype {
//  std::string Name;
//  std::vector<std::string> Args;
//
// public:
//  FunPrototype(const std::string &Name, std::vector<std::string> Args)
//      : Name(Name), Args(std::move(Args)) {}
//
//  llvm::Function *codegen(llvm::IRBuilder<> & builder);
//  const std::string &getName() const { return Name; }
//};
//
///// FunctionAST - This class represents a function definition itself
//class FunctionAST {
//  std::unique_ptr<FunPrototype> Proto;
//  std::unique_ptr<Expression> Body;
//
// public:
//  FunctionAST(std::unique_ptr<FunPrototype> Proto,
//              std::unique_ptr<Expression> Body)
//      : Proto(std::move(Proto)), Body(std::move(Body)) {}
//
//  llvm::Function *codegen(llvm::IRBuilder<> & builder);
//};

}

#endif //DRAGONLANGUAGE_ID_HPP

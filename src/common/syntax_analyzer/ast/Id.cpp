////
//// Created by redra on 07.01.20.
////
//
//#include "Id.hpp"
//
//namespace dragonlang::common::ast {
//
////===----------------------------------------------------------------------===//
//// Code Generation
////===----------------------------------------------------------------------===//
//
//static std::unique_ptr<llvm::Module> TheModule;
//static std::map<std::string, llvm::Value*> NamedValues;
//
///// LogError* - These are little helper functions for error handling.
//std::unique_ptr<Expression> LogError(const char *Str) {
//  fprintf(stderr, "Error: %s\n", Str);
//  return nullptr;
//}
//
//std::unique_ptr<FunPrototype> LogErrorP(const char *Str) {
//  LogError(Str);
//  return nullptr;
//}
//
//llvm::Value *LogErrorV(const char *Str) {
//  LogError(Str);
//  return nullptr;
//}
//
////llvm::Value *LetterExpression::codegen(llvm::IRBuilder<> & builder) {
////  // Look this variable up in the function.
////  llvm::Value *V = NamedValues[Name];
////  if (!V)
////    return LogErrorV("Unknown variable name");
////  return V;
////}
//
//llvm::Value *BinaryExpression::codegen(llvm::IRBuilder<> & builder) {
//  llvm::Value *L = LHS->codegen(builder);
//  llvm::Value *R = RHS->codegen(builder);
//  if (!L || !R)
//    return nullptr;
//
//  switch (Op) {
//    case '+':
//      return builder.CreateFAdd(L, R, "addtmp");
//    case '-':
//      return builder.CreateFSub(L, R, "subtmp");
//    case '*':
//      return builder.CreateFMul(L, R, "multmp");
//    case '<':
//      L = builder.CreateFCmpULT(L, R, "cmptmp");
//      // Convert bool 0/1 to double 0.0 or 1.0
//      return builder.CreateUIToFP(L, llvm::Type::getDoubleTy(builder.getContext()), "booltmp");
//    default:
//      return LogErrorV("invalid binary operator");
//  }
//}
//
//llvm::Function *FunPrototype::codegen(llvm::IRBuilder<> & builder) {
//  // Make the function type:  double(double,double) etc.
//  std::vector<llvm::Type *> Doubles(Args.size(), llvm::Type::getDoubleTy(builder.getContext()));
//  llvm::FunctionType *FT =
//      llvm::FunctionType::get(llvm::Type::getDoubleTy(builder.getContext()), Doubles, false);
//
//  llvm::Function *F =
//      llvm::Function::Create(FT, llvm::Function::ExternalLinkage, Name, TheModule.get());
//
//  // Set names for all arguments.
//  unsigned Idx = 0;
//  for (auto &Arg : F->args())
//    Arg.setName(Args[Idx++]);
//
//  return F;
//}
//
//llvm::Function *FunctionAST::codegen(llvm::IRBuilder<> & builder) {
//  // First, check for an existing function from a previous 'extern' declaration.
//  llvm::Function *TheFunction = TheModule->getFunction(Proto->getName());
//
//  if (!TheFunction)
//    TheFunction = Proto->codegen(builder);
//
//  if (!TheFunction)
//    return nullptr;
//
//  // Create a new basic block to start insertion into.
//  llvm::BasicBlock *BB = llvm::BasicBlock::Create(builder.getContext(), "entry", TheFunction);
//  builder.SetInsertPoint(BB);
//
//  // Record the function arguments in the NamedValues map.
//  NamedValues.clear();
//  for (auto &Arg : TheFunction->args())
//    NamedValues[Arg.getName()] = &Arg;
//
//  if (llvm::Value *RetVal = Body->codegen(builder)) {
//    // Finish off the function.
//    builder.CreateRet(RetVal);
//
//    // Validate the generated code, checking for consistency.
//    verifyFunction(*TheFunction);
//
//    return TheFunction;
//  }
//
//  // Error reading body, remove function.
//  TheFunction->eraseFromParent();
//  return nullptr;
//}
//
//}

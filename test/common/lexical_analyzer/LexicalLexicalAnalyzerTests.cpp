//
// Created by redra on 02.09.18.
//

#include <gtest/gtest.h>
#include <boost/format.hpp>

#include "common/lexical_analyzer/LexicalAnalyzer.hpp"

using dragonlang::common::TokenId;
using dragonlang::common::LexicalAnalyzer;

struct LexicalAnalyzerTest : testing::Test {
  std::unique_ptr<LexicalAnalyzer> lexical_analyzer_;

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };
};

TEST_F(LexicalAnalyzerTest, String_me_Valid)
{
  lexical_analyzer_ = std::make_unique<LexicalAnalyzer>(std::string("/home/redra/Projects/DragonLang/Kingdom/test"
                                                                    "/common/lexical_analyzer/files/Strings.me"));
  const auto & kTokens = lexical_analyzer_->getAllTokens();
  ASSERT_EQ(kTokens.size(), 78);
  int tokenIndex = 0;
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
}

TEST_F(LexicalAnalyzerTest, VarString_me_Valid)
{
  lexical_analyzer_ = std::make_unique<LexicalAnalyzer>(std::string("/home/redra/Projects/DragonLang/Kingdom/test"
                                                                    "/common/lexical_analyzer/files/VarStrings.me"));
  const auto & kTokens = lexical_analyzer_->getAllTokens();
  ASSERT_EQ(kTokens.size(), 96);
  int tokenIndex = 0;
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "String");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1231 24223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "string_number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::TextConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
}

TEST_F(LexicalAnalyzerTest, Numbers_me_Valid)
{
  lexical_analyzer_ = std::make_unique<LexicalAnalyzer>(std::string("/home/redra/Projects/DragonLang/Kingdom/test"
                                                                    "/common/lexical_analyzer/files/Numbers.me"));
  const auto & kTokens = lexical_analyzer_->getAllTokens();
  ASSERT_EQ(kTokens.size(), 37);
  int tokenIndex = 0;
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number0");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "17");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number1");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1.23");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number2");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "2.42");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number3");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "21.");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number0");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "17");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number1");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1.23");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number2");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Float");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "2.42");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number3");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Decimal");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "21.");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number0");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
}

TEST_F(LexicalAnalyzerTest, VarNumbers_me_Valid)
{
  lexical_analyzer_ = std::make_unique<LexicalAnalyzer>(std::string("/home/redra/Projects/DragonLang/Kingdom/test"
                                                                    "/common/lexical_analyzer/files/VarNumbers.me"));
  const auto & kTokens = lexical_analyzer_->getAllTokens();
  ASSERT_EQ(kTokens.size(), 46);
  int tokenIndex = 0;
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number0");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "17");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number1");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1.23");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number2");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "2.42");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number3");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "21.");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number0");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "17");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number1");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "1.23");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number2");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Float");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "2.42");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number3");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Decimal");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "21.");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "number0");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223");
}

TEST_F(LexicalAnalyzerTest, Function_me_Valid)
{
  lexical_analyzer_ = std::make_unique<LexicalAnalyzer>(std::string("/home/redra/Projects/DragonLang/Kingdom/test"
                                                                    "/common/lexical_analyzer/files/Function.me"));
  const auto & kTokens = lexical_analyzer_->getAllTokens();
  ASSERT_EQ(kTokens.size(), 23);
  int tokenIndex = 0;
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "fun");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "getName");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "(");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ")");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "{");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "num0");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223.23");
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "num1");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Float");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223.42");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "num2");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Decimal");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223.");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "}");
}

TEST_F(LexicalAnalyzerTest, Function_Plus_Logic_Valid)
{
  lexical_analyzer_ = std::make_unique<LexicalAnalyzer>(std::string("/home/redra/Projects/DragonLang/Kingdom"
                                                                    "/test/common/lexical_analyzer/files/Function_Plus_Logic.me"));
  const auto & kTokens = lexical_analyzer_->getAllTokens();
  ASSERT_EQ(kTokens.size(), 34);
  int tokenIndex = 0;
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "fun");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "getName");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "(");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ")");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "{");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "num0");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Number");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223.23");
  ASSERT_EQ(kTokens[tokenIndex++].item_, "let");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "num1");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Float");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223.42");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "num2");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ":");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "Decimal");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::NumberConst);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "123124223.");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "if");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "(");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::Keyword);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "auto");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "k");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "=");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SymbolId);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "calculate");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "(");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ")");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, ")");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "{");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "}");
  ASSERT_EQ(kTokens[tokenIndex].id_, TokenId::SpecialSymbol);
  ASSERT_EQ(kTokens[tokenIndex++].item_, "}");
}

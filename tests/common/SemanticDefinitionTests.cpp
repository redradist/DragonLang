//
// Created by redra on 08.09.18.
//

#include <gtest/gtest.h>

#include <regex>

#include "common/SemanticDefinition.hpp"

struct SemanticDefinitionTests : testing::Test {
  virtual void SetUp() {
  };

  virtual void TearDown() {
  };
};

TEST_F(SemanticDefinitionTests, ValidParseReturn0)
{
  ASSERT_TRUE(std::regex_search(R"(return 12)",
                                DragonLang::Common::kRegexKeyword));
}

TEST_F(SemanticDefinitionTests, ValidParseReturn1)
{
  ASSERT_TRUE(std::regex_search(R"(return{12})",
                                DragonLang::Common::kRegexKeyword));
}

TEST_F(SemanticDefinitionTests, InvalidParseReturn)
{
  ASSERT_FALSE(std::regex_search(R"( return 12)",
                                 DragonLang::Common::kRegexKeyword));
}

TEST_F(SemanticDefinitionTests, ValidParseClass)
{
  ASSERT_TRUE(std::regex_search(R"(class MyClass)",
                                DragonLang::Common::kRegexKeyword));
}

TEST_F(SemanticDefinitionTests, InvalidParseClass)
{
  ASSERT_FALSE(std::regex_search(R"( class MyClass)",
                                 DragonLang::Common::kRegexKeyword));
}

TEST_F(SemanticDefinitionTests, ValidParseInterface)
{
  ASSERT_TRUE(std::regex_search(R"(interface ITransport)",
                                DragonLang::Common::kRegexKeyword));
}

TEST_F(SemanticDefinitionTests, InvalidParseInterface)
{
  ASSERT_FALSE(std::regex_search(R"( interface ITransport)",
                                 DragonLang::Common::kRegexKeyword));
}

TEST_F(SemanticDefinitionTests, ValidParseIn0)
{
  ASSERT_TRUE(std::regex_search(R"(in {1, 2, 3})",
                                DragonLang::Common::kRegexContextKeyword));
}

TEST_F(SemanticDefinitionTests, ValidParseIn2)
{
  ASSERT_TRUE(std::regex_search(R"(in{1, 2, 3})",
                                DragonLang::Common::kRegexContextKeyword));
}

TEST_F(SemanticDefinitionTests, InvalidParseIn)
{
  ASSERT_FALSE(std::regex_search(R"( in {1, 2, 3})",
                                 DragonLang::Common::kRegexContextKeyword));
}

TEST_F(SemanticDefinitionTests, ValidParseOneQuoteString0)
{
  ASSERT_TRUE(std::regex_search(R"('Hello Denis !!')",
                                DragonLang::Common::kRegexString0Const));
}

TEST_F(SemanticDefinitionTests, ValidParseOneQuoteString1)
{
  ASSERT_TRUE(std::regex_search(R"(''Hello 'Denis' !!'')",
                                DragonLang::Common::kRegexString1Const));
}

TEST_F(SemanticDefinitionTests, InvalidParseOneQuoteString0)
{
  ASSERT_FALSE(std::regex_search(R"(''Hello Denis !!' ')",
                                 DragonLang::Common::kRegexString1Const));
}

TEST_F(SemanticDefinitionTests, ValidParseDoubleQuoteString0)
{
  ASSERT_TRUE(std::regex_search(R"("Hello Denis !!")",
                                DragonLang::Common::kRegexString3Const));
}

TEST_F(SemanticDefinitionTests, ValidParseDoubleQuoteString1)
{
  ASSERT_TRUE(std::regex_search(R"(""Hello 'Denis' !!"")",
                                DragonLang::Common::kRegexString4Const));
}

TEST_F(SemanticDefinitionTests, ValidParseDoubleQuoteString2)
{
  ASSERT_TRUE(std::regex_search(R"(""Hello "Denis" !!"")",
                                DragonLang::Common::kRegexString4Const));
}

TEST_F(SemanticDefinitionTests, InvalidParseDoubleQuoteString0)
{
  ASSERT_FALSE(std::regex_search(R"(""Hello Denis !!" ")",
                                 DragonLang::Common::kRegexString4Const));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber0)
{
  ASSERT_TRUE(std::regex_search(R"(2.43)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber1)
{
  ASSERT_TRUE(std::regex_search(R"(2.)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber2)
{
  ASSERT_TRUE(std::regex_search(R"(.43)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber3)
{
  ASSERT_TRUE(std::regex_search(R"(2e2)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber4)
{
  ASSERT_TRUE(std::regex_search(R"(2.e2)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber5)
{
  ASSERT_TRUE(std::regex_search(R"(2.e2.)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber6)
{
  ASSERT_TRUE(std::regex_search(R"(2.1e2.)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber7)
{
  ASSERT_TRUE(std::regex_search(R"(2.1e2.3)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber8)
{
  ASSERT_TRUE(std::regex_search(R"(.1e.3)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber9)
{
  ASSERT_TRUE(std::regex_search(R"(.1e1.3)",
                                DragonLang::Common::kRegexNumberConst));
}

TEST_F(SemanticDefinitionTests, ValidParseNumber10)
{
  ASSERT_TRUE(std::regex_search(R"(123124223e32)",
                                DragonLang::Common::kRegexNumberConst));
}

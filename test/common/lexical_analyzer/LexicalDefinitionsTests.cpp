//
// Created by redra on 08.09.18.
//

#include <gtest/gtest.h>

#include <regex>

#include "common/lexical_analyzer/LexicalDefinitions.hpp"

struct LexicalDefinitionsTests : testing::Test {
  virtual void SetUp() {
  };

  virtual void TearDown() {
  };
};

TEST_F(LexicalDefinitionsTests, ValidParseReturn0)
{
  ASSERT_TRUE(std::regex_search(R"(return 12)",
                                dragonlang::common::kRegexKeyword));
}

TEST_F(LexicalDefinitionsTests, ValidParseReturn1)
{
  ASSERT_TRUE(std::regex_search(R"(return{12})",
                                dragonlang::common::kRegexKeyword));
}

TEST_F(LexicalDefinitionsTests, InvalidParseReturn)
{
  ASSERT_FALSE(std::regex_search(R"( return 12)",
                                 dragonlang::common::kRegexKeyword));
}

TEST_F(LexicalDefinitionsTests, ValidParseClass)
{
  ASSERT_TRUE(std::regex_search(R"(class MyClass)",
                                dragonlang::common::kRegexKeyword));
}

TEST_F(LexicalDefinitionsTests, InvalidParseClass)
{
  ASSERT_FALSE(std::regex_search(R"( class MyClass)",
                                 dragonlang::common::kRegexKeyword));
}

TEST_F(LexicalDefinitionsTests, ValidParseInterface)
{
  ASSERT_TRUE(std::regex_search(R"(interface ITransport)",
                                dragonlang::common::kRegexKeyword));
}

TEST_F(LexicalDefinitionsTests, InvalidParseInterface)
{
  ASSERT_FALSE(std::regex_search(R"( interface ITransport)",
                                 dragonlang::common::kRegexKeyword));
}

TEST_F(LexicalDefinitionsTests, ValidParseIn0)
{
  ASSERT_TRUE(std::regex_search(R"(in {1, 2, 3})",
                                dragonlang::common::kRegexContextKeyword));
}

TEST_F(LexicalDefinitionsTests, ValidParseIn2)
{
  ASSERT_TRUE(std::regex_search(R"(in{1, 2, 3})",
                                dragonlang::common::kRegexContextKeyword));
}

TEST_F(LexicalDefinitionsTests, InvalidParseIn)
{
  ASSERT_FALSE(std::regex_search(R"( in {1, 2, 3})",
                                 dragonlang::common::kRegexContextKeyword));
}

TEST_F(LexicalDefinitionsTests, ValidParseOneQuoteString0)
{
  ASSERT_TRUE(std::regex_search(R"('Hello Denis !!')",
                                dragonlang::common::kRegexStringSingleQuoteConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseOneQuoteString1)
{
  ASSERT_TRUE(std::regex_search(R"(''Hello 'Denis' !!'')",
                                dragonlang::common::kRegexStringTwoSingleQuoteConst));
}

TEST_F(LexicalDefinitionsTests, InvalidParseOneQuoteString0)
{
  ASSERT_FALSE(std::regex_search(R"(''Hello Denis !!' ')",
                                 dragonlang::common::kRegexStringTwoSingleQuoteConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseOneQuoteString3)
{
  ASSERT_TRUE(std::regex_search(R"('''Hello 'Denis' !!''')",
                                dragonlang::common::kRegexStringThreeSingleQuoteConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseDoubleQuoteString0)
{
  ASSERT_TRUE(std::regex_search(R"("Hello Denis !!")",
                                dragonlang::common::kRegexStringQuoteConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseDoubleQuoteString1)
{
  ASSERT_TRUE(std::regex_search(R"(""Hello 'Denis' !!"")",
                                dragonlang::common::kRegexStringTwoQuoteConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseDoubleQuoteString2)
{
  ASSERT_TRUE(std::regex_search(R"(""Hello "Denis" !!"")",
                                dragonlang::common::kRegexStringTwoQuoteConst));
}

TEST_F(LexicalDefinitionsTests, InvalidParseDoubleQuoteString0)
{
  ASSERT_FALSE(std::regex_search(R"(""Hello Denis !!" ")",
                                 dragonlang::common::kRegexStringTwoQuoteConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber0)
{
  ASSERT_TRUE(std::regex_search(R"(2.43)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber1)
{
  ASSERT_TRUE(std::regex_search(R"(2.)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber2)
{
  ASSERT_TRUE(std::regex_search(R"(.43)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber3)
{
  ASSERT_TRUE(std::regex_search(R"(2e2)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber4)
{
  ASSERT_TRUE(std::regex_search(R"(2.e2)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber5)
{
  ASSERT_TRUE(std::regex_search(R"(2.e2.)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber6)
{
  ASSERT_TRUE(std::regex_search(R"(2.1e2.)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber7)
{
  ASSERT_TRUE(std::regex_search(R"(2.1e2.3)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber8)
{
  ASSERT_TRUE(std::regex_search(R"(.1e.3)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber9)
{
  ASSERT_TRUE(std::regex_search(R"(.1e1.3)",
                                dragonlang::common::kRegexNumberConst));
}

TEST_F(LexicalDefinitionsTests, ValidParseNumber10)
{
  ASSERT_TRUE(std::regex_search(R"(123124223e32)",
                                dragonlang::common::kRegexNumberConst));
}

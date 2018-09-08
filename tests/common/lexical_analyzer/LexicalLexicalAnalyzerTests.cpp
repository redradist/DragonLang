//
// Created by redra on 02.09.18.
//

#include <gtest/gtest.h>

#include <boost/format.hpp>

#include "common/lexical_analyzer/LexicalAnalizer.hpp"

using DragonLang::Common::LexicalAnalyzer;

struct LexicalAnalyzerTest : testing::Test {
  std::unique_ptr<LexicalAnalyzer> lexical_analyzer_;

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };
};

TEST_F(LexicalAnalyzerTest, ValidFile)
{
  lexical_analyzer_ = std::make_unique<LexicalAnalyzer>(std::string( "/home/redra/Projects/DragonLanguage/Kingdom/tests" )+
                                                        "/common/lexical_analyzer/files/Code.me");
  const auto & kTokens = lexical_analyzer_->getAllTokens();
  ASSERT_EQ(kTokens.size(), 46);
}

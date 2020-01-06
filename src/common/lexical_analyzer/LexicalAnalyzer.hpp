#ifndef DRAGONLANGUAGE_LEXICAL_ANALYZER
#define DRAGONLANGUAGE_LEXICAL_ANALYZER

#include <string>
#include <vector>
#include <optional>
#include <iostream>
#include <fstream>
#include <sstream>

#include "LexicalDefinitions.hpp"
#include "InStreamRange.hpp"
#include "SearchResult.hpp"

namespace DragonLang::Common {

class LexicalAnalyzer {
 public:
  struct Token {
    TokenId id_;
    std::string item_;

    std::string toString() const;
  };

  using OptionalTokenId = std::optional<TokenId>;
  using OptionalToken = std::optional<Token>;

  explicit LexicalAnalyzer(const std::string & _file);
  virtual ~LexicalAnalyzer() = default;

  OptionalToken getNextToken();
  std::vector<Token> getAllTokens();
  void printTokens(const std::vector<LexicalAnalyzer::Token> &_tokens) const;
  void printTokens();

 protected:
  [[nodiscard]]
  virtual SearchResult isNextSymbolId() const;
  [[nodiscard]]
  virtual SearchResult isNextTextConst() const;
  [[nodiscard]]
  virtual SearchResult isNextNumber() const;
  [[nodiscard]]
  virtual SearchResult isNextKeyword() const;
  [[nodiscard]]
  virtual SearchResult isNextContextKeyword() const;
  [[nodiscard]]
  virtual SearchResult isNextSpecialSymbol() const;
  [[nodiscard]]
  virtual bool isWhiteSpace(char const &_rawStr) const;
  [[nodiscard]]
  virtual bool isIndentSymbol(char const &_rawStr) const;
  [[nodiscard]]
  virtual bool isNewLine(char const &_rawStr) const;

 private:
  OptionalTokenId prev_token_id_;
  std::unique_ptr<InStreamRange> stream_range_;
  std::string token_buffer_;
};

using Scanner = LexicalAnalyzer;

}

#endif  // DRAGONLANGUAGE_LEXICAL_ANALYZER

#ifndef DRAGONLANGUAGE_LEXICAL_ANALYZER
#define DRAGONLANGUAGE_LEXICAL_ANALYZER

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/optional.hpp>

#include "LexicalDefinitions.hpp"
#include "InStreamRange.hpp"
#include "SearchResult.hpp"

namespace DragonLang::Common {

class LexicalAnalyzer {
 public:
  struct Token {
    TokenId id_;
    std::string item_;

    std::string toString() const {
      switch (id_) {
        case TokenId::SpecialSymbol: {
          return "<SpecialSymbol> \""+ item_ + "\"";
        }
        case TokenId::Keyword: {
          return "<Keyword> \""+ item_ + "\"";
        }
        case TokenId::ContextKeyword: {
          return "<ContextKeyword> \""+ item_ + "\"";
        }
        case TokenId::NewLine: {
          return "<NewLine> \""+ item_ + "\"";
        }
        case TokenId::NumberConst: {
          return "<NumberConst> \""+ item_ + "\"";
        }
        case TokenId::TextConst: {
          return "<TextConst> \""+ item_ + "\"";
        }
        case TokenId::SymbolId: {
          return "<SymbolId> \""+ item_ + "\"";
        }
        default: {
          return std::string("<!! UnknownToken [") + std::to_string(static_cast<int>(id_)) + "] !!> \"" + item_ + "\"";
        }
      }
    }
  };

  using OptionalTokenId = boost::optional<TokenId>;
  using OptionalToken = boost::optional<Token>;

  LexicalAnalyzer(const std::string & _file);
  virtual ~LexicalAnalyzer() = default;

  OptionalToken getNextToken();
  std::vector<Token> getAllTokens();
  void printTokens(const std::vector<LexicalAnalyzer::Token> &_tokens) const;
  void printTokens();

 protected:
  virtual SearchResult isNextSymbolId() const;
  virtual SearchResult isNextTextConst() const;
  virtual SearchResult isNextNumber() const;
  virtual SearchResult isNextKeyword() const;
  virtual SearchResult isNextContextKeyword() const;
  virtual SearchResult isNextSpecialSymbol() const;
  virtual bool isWhiteSpace(char const &_rawStr) const;
  virtual bool isIndentSymbol(char const &_rawStr) const;
  virtual bool isNewLine(char const &_rawStr) const;

 private:
  OptionalTokenId prev_token_id_;
  std::unique_ptr<InStreamRange> stream_range_;
  std::string token_buffer_;
};

using Scanner = LexicalAnalyzer;

}

#endif  // DRAGONLANGUAGE_LEXICAL_ANALYZER

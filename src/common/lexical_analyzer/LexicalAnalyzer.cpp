#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

#include <boost/format.hpp>

#include "LexicalAnalyzer.hpp"

namespace dragonlang::common {

const int kFullMatchIndex = 0;
const int kTokenMatchIndex = 1;

std::string LexicalAnalyzer::Token::toString() const {
  switch (id_) {
    case TokenId::SpecialSymbol: {
      return "<SpecialSymbol " + item_ + ">";
    }
    case TokenId::Keyword: {
      return "<Keyword " + item_ + ">";
    }
    case TokenId::ContextKeyword: {
      return "<ContextKeyword " + item_ + ">";
    }
    case TokenId::NewLine: {
      return "<NewLine " + item_ + ">";
    }
    case TokenId::NumberConst: {
      return "<NumberConst " + item_ + ">";
    }
    case TokenId::TextConst: {
      return "<TextConst " + item_ + ">";
    }
    case TokenId::SymbolId: {
      return "<SymbolId " + item_ + ">";
    }
    default: {
      return std::string("<!! UnknownToken [") + std::to_string(static_cast<int>(id_)) + "] !!> \"" + item_ + "\"";
    }
  }
}

LexicalAnalyzer::LexicalAnalyzer(const std::string & _file) {
  std::ifstream fileStream{_file};
  if (!fileStream) {
    std::cerr << boost::format("Cannot open file: %1%") % _file << std::endl;
    std::cerr << "Please, check the name of the file." << std::endl;
#ifdef __EXCEPTIONS
    throw std::string("Cannot open file !!");
#else
    ::exit(1);
#endif
  } else {
    std::string stream_buffer_ = {std::istreambuf_iterator<char>(fileStream),
                                  std::istreambuf_iterator<char>()};
    stream_range_ = std::make_unique<InStreamRange>(std::move(stream_buffer_));
  }
}

LexicalAnalyzer::OptionalToken
LexicalAnalyzer::getNextToken() {
  OptionalToken token;
  char symbol;
  while (*stream_range_) {
    // Put into token buffer a new symbol
    const char kNextChar = stream_range_->getNextChar();
    if (isWhiteSpace(kNextChar) || isIndentSymbol(kNextChar) || isNewLine(kNextChar)) {
      stream_range_->moveNext();
      continue;
    }

    SearchResult result;
    std::vector<SearchResult> results;

    SearchResult keyword = isNextKeyword();
    if (keyword > result) {
      result = keyword;
      results.clear();
      results.push_back(result);
    } else if (keyword == result) {
      results.push_back(keyword);
    }

    SearchResult contextKeyword = isNextContextKeyword();
    if (contextKeyword > result) {
      result = contextKeyword;
      results.clear();
      results.push_back(result);
    } else if (contextKeyword == result) {
      results.push_back(contextKeyword);
    }

    SearchResult textConst = isNextTextConst();
    if (textConst > result) {
      result = textConst;
      results.clear();
      results.push_back(result);
    } else if (textConst == result) {
      results.push_back(textConst);
    }

    SearchResult number = isNextNumber();
    if (number > result) {
      result = number;
      results.clear();
      results.push_back(result);
    } else if (number == result) {
      results.push_back(number);
    }

    if (!keyword) {
      SearchResult symbolId = isNextSymbolId();
      if (symbolId > result) {
        result = symbolId;
        results.clear();
        results.push_back(result);
      } else if (symbolId == result) {
        results.push_back(symbolId);
      }
    }

    SearchResult specialSymbol = isNextSpecialSymbol();
    if (specialSymbol > result) {
      result = specialSymbol;
      results.clear();
      results.push_back(result);
    } else if (specialSymbol == result) {
      results.push_back(specialSymbol);
    }

    if (results.size() > 1) {
      std::cerr << "Error. Ambiguity !! " << results.size() << std::endl;
      for (const auto result : results) {
        std::cerr << "result.id_ = " << static_cast<int>(result.id_) << std::endl;
        std::cerr << "result.match_[kFullMatchIndex] = " << result.match_[kFullMatchIndex] << std::endl;
      }
      break;
    } else if (result) {
      std::string res = result.match_[kTokenMatchIndex];
      token = Token{result.id_, res};
      if (TokenId::TextConst == token->id_) {
        stream_range_->moveNext(result.match_.str().size());
      } else {
        std::size_t found = result.match_.str().find(res);
        stream_range_->moveNext(found + res.size());
      }
      break;
    } else {
      stream_range_->moveNext();
    }
  }

  return token;
}

std::vector<LexicalAnalyzer::Token>
LexicalAnalyzer::getAllTokens() {
  std::vector<LexicalAnalyzer::Token> tokens;
  LexicalAnalyzer::OptionalToken token;
  while (token = getNextToken()) {
    tokens.push_back(token.value());
  }
  return tokens;
}

void LexicalAnalyzer::printTokens() {
  printTokens(getAllTokens());
}

void LexicalAnalyzer::printTokens(const std::vector<LexicalAnalyzer::Token> &_tokens) const {
  for (const auto &kToken : _tokens) {
    switch (kToken.id_) {
      case TokenId::SpecialSymbol: {
        std::cout << "SpecialSymbol: " << kToken.item_ << std::endl;
        break;
      }
      case TokenId::Keyword: {
        std::cout << "Keyword: " << kToken.item_ << std::endl;
        break;
      }
      case TokenId::ContextKeyword: {
        std::cout << "ContextKeyword: " << kToken.item_ << std::endl;
        break;
      }
      case TokenId::NewLine: {
        std::cout << "NewLine detected !" << std::endl;
        break;
      }
      case TokenId::NumberConst: {
        std::cout << "Number: " << kToken.item_ << std::endl;
        break;
      }
      case TokenId::TextConst: {
        std::cout << "Text: " << kToken.item_ << std::endl;
        break;
      }
      default: {
        std::cout << "ERROR, UNKOWN TOKEN ID !!!" << std::endl;
        break;
      }
    }
  }
}

SearchResult LexicalAnalyzer::isNextNumber() const {
  std::smatch matchValue;
  return {std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexNumberConst),
          TokenId::NumberConst,
          matchValue};
}

SearchResult LexicalAnalyzer::isNextSymbolId() const {
  std::smatch matchValue;
  return {std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexSymbolId),
          TokenId::SymbolId,
          matchValue};
}

SearchResult LexicalAnalyzer::isNextTextConst() const {
  std::smatch matchValue;
  return {std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexStringThreeSingleQuoteConst) ||
          std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexStringThreeQuoteConst) ||
          std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexStringTwoSingleQuoteConst) ||
          std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexStringTwoQuoteConst) ||
          std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexStringSingleQuoteConst) ||
          std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexStringQuoteConst),
          TokenId::TextConst,
          matchValue};
}

SearchResult LexicalAnalyzer::isNextKeyword() const {
  std::smatch matchValue;
  return {std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexKeyword),
          TokenId::Keyword,
          matchValue};
}

SearchResult LexicalAnalyzer::isNextContextKeyword() const {
  std::smatch matchValue;
  return {std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexContextKeyword),
          TokenId::ContextKeyword,
          matchValue};
}

SearchResult LexicalAnalyzer::isNextSpecialSymbol() const {
  std::smatch matchValue;
  return {std::regex_search(stream_range_->begin(),
                            stream_range_->end(),
                            matchValue, kRegexSpecialSymbol),
          TokenId::SpecialSymbol,
          matchValue};
}

bool LexicalAnalyzer::isWhiteSpace(char const &_rawStr) const {
  return isNewLine(_rawStr) || isIndentSymbol(_rawStr);
}

bool LexicalAnalyzer::isIndentSymbol(char const &_rawStr) const {
  return kIndentSymbols.end() != kIndentSymbols.find(_rawStr);
}

bool LexicalAnalyzer::isNewLine(char const &_rawStr) const {
  return kNewLines.end() != kNewLines.find(_rawStr);
}

}

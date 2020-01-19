#ifndef DRAGONLANGUAGE_LEXICAL_DEFINITIONS
#define DRAGONLANGUAGE_LEXICAL_DEFINITIONS

#include <string>
#include <unordered_set>
#include <regex>

namespace DragonLang::Common {

enum class TokenId {
  SpecialSymbol,  // < > + - = - > " ' ...
  Keyword,        // fun return class ...
  ContextKeyword, // in, is, not, as ...
  NewLine,        // \r \n
  NumberConst,    // 23, 27, 2.75, 2.75f, 2.75e-23f, 2.75d, 2.75e-23d ...
  TextConst,      // 'Hello Denis Good Job', "Hello Denis Good Job" ...
  SymbolId,       // Name of variables, name of classes, name of structs and so on ...
};

inline std::unordered_set<char> const kNewLines = {
  '\r',
  '\n',
};

inline std::unordered_set<char> const kIndentSymbols = {
  ' ',
  '\t',
};

inline std::regex_constants::syntax_option_type const kRegexOptions =
    std::regex_constants::ECMAScript |
    std::regex_constants::optimize;

inline std::regex const kRegexKeyword(
  R"(^()"
  R"(yield|)"
  R"(return|)"
  R"(enum|)"
  R"(struct|)"
  R"(class|)"
  R"(fun|)"
  R"(public|)"
  R"(protected|)"
  R"(private|)"
  R"(internal|)"
  R"(data|)"
  R"(interface|)"
  R"(trait|)"
  R"(import|)"
  R"(from|)"
  R"(void|)"
  R"(new|)"
  R"(delete|)"
  R"(extension|)"
  R"(extends|)"
  R"(inherits|)"
  R"(implements|)"
  R"(let|)"
  R"(auto|)"
  R"(char|)"
  R"(char8|)"
  R"(char16|)"
  R"(char32|)"
  R"(byte|)"
  R"(await|)"
  R"(async|)"
  R"(if|)"
  R"(else|)"
  R"(try|)"
  R"(catch|)"
  R"(atomic|)"
  R"(volatile|)"
  R"(inline)"
  R"()(\s|\W|$))", kRegexOptions);
inline std::regex const kRegexContextKeyword(
  R"(^()"
  R"(in|)"
  R"(is|)"
  R"(not|)"
  R"(as|)"
  R"(to)"
  R"()(\s|\W|$))", kRegexOptions);
inline std::regex const kRegexSpecialSymbol(
  R"(^([)"
  R"(\()"
  R"(\))"
  R"(\[)"
  R"(\])"
  R"(\$)"
  R"(\@)"
  R"(\!)"
  R"(\~)"
  R"(\^)"
  R"(\&)"
  R"(\*)"
  R"(\%)"
  R"(\?)"
  R"(\:)"
  R"(\;)"
  R"(\,)"
  R"(\.)"
  R"(\-)"
  R"(\+)"
  R"(\=)"
  R"(\>)"
  R"(\<)"
  R"(\+)"
  R"(\{)"
  R"(\})"
  R"(]))", kRegexOptions);
inline std::regex const kRegexNumberConst(R"(^(([0-9]+([.][0-9]*)?|[.][0-9]+)(e([0-9]+([.][0-9]*)?|[.][0-9]+))?)(\s|\W|$))", kRegexOptions);
inline std::regex const kRegexStringSingleQuoteConst(R"(^'([^\n]*)')", kRegexOptions);
inline std::regex const kRegexStringTwoSingleQuoteConst(R"(^''([^\n]*)'')", kRegexOptions);
inline std::regex const kRegexStringThreeSingleQuoteConst(R"(^'''([^]*?)''')", kRegexOptions);
inline std::regex const kRegexStringQuoteConst(R"(^\"([^\n]*)\")", kRegexOptions);
inline std::regex const kRegexStringTwoQuoteConst(R"(^\"\"([^\n]*)\"\")", kRegexOptions);
inline std::regex const kRegexStringThreeQuoteConst(R"(^\"\"\"([^]*?)\"\"\")", kRegexOptions);
inline std::regex const kRegexSymbolId(R"(^([_A-Za-z][_A-Za-z\d]*)(\s|\W|$))", kRegexOptions);

}

#endif  // DRAGONLANGUAGE_LEXICAL_DEFINITIONS

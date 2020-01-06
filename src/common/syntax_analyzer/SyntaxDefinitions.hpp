//
// Created by redra on 16.09.18.
//

#ifndef DRAGONLANGUAGE_SYNTAX_DEFINITIONS_HPP
#define DRAGONLANGUAGE_SYNTAX_DEFINITIONS_HPP

#include <string>
#include <unordered_set>
#include <regex>

namespace DragonLang::Common {

inline std::regex_constants::syntax_option_type const kRegexOptions =
    std::regex_constants::ECMAScript |
    std::regex_constants::optimize;

inline std::map<std::string, std::string> kLanguageGrammar = {
    {"declaration", ""}
};
inline std::regex const kRegexVarDefinition(
    R"(^(<Keyword var><SymbolId .*>()?)", kRegexOptions);

}

#endif  // DRAGONLANGUAGE_SYNTAX_DEFINITIONS_HPP

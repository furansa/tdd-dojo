#include "Soundex.hpp"

using std::string;
using std::unordered_map;

string Soundex::encode(const string& word) const {
    return zeroPad(head(word) + encodedDigits(word));
}

string Soundex::encodedDigits(const string& word) const {
    if (word.length() > 1) return encodedDigit(word[1]);

    return "";
}

string Soundex::encodedDigit(char letter) const {
    const unordered_map<char, string> encodings {
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"},
        {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"},
        {'l', "4"},
        {'m', "5"}, {'n', "5"},
        {'r', "6"},
    };

    auto it = encodings.find(letter);

    return it == encodings.end() ? "" : it->second;
}

string Soundex::head(const string& word) const {
    return word.substr(0, 1);
}

string Soundex::zeroPad(const string& word) const {
    auto zerosNeeded = MaxCodeLength - word.length();

    return word + string(zerosNeeded, '0');
}

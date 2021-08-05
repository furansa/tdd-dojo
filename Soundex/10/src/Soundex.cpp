#include "Soundex.hpp"

using std::string;
using std::unordered_map;

string Soundex::encode(const string& word) const {
    return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
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

    auto it = encodings.find(std::tolower(letter));

    return it == encodings.end() ? NotADigit : it->second;
}

string Soundex::encodedDigits(const string& word) const {
    string encoding;

    for (auto letter : word) {
        if (isComplete(encoding)) break;

        auto digit = encodedDigit(letter);

        if (digit != NotADigit && digit != lastDigitAppended(encoding)) {
            encoding += digit;
        }
    }

    return encoding;
}

string Soundex::head(const string& word) const {
    return word.substr(0, 1);
}

bool Soundex::isComplete(const string& encoding) const {
    return encoding.length() == (MaxCodeLength - 1);
}

string Soundex::lastDigitAppended(const string& encoding) const {
    if (encoding.empty()) return NotADigit;

    return string(1, encoding.back());
}

string Soundex::tail(const string& word) const {
    return word.substr(1);
}

string Soundex::upperFront(const string& word) const {
    return string(1, std::toupper(static_cast<unsigned char>(word.front())));
}

string Soundex::zeroPad(const string& word) const {
    auto zerosNeeded = MaxCodeLength - word.length();

    return word + string(zerosNeeded, '0');
}

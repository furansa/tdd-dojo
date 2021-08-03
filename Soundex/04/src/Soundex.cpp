#include "Soundex.hpp"

using std::string;

string Soundex::encode(const string& word) const {
    return zeroPad(head(word) + encodedDigits(word));
}

string Soundex::encodedDigits(const string& word) const {
    if (word.length() > 1) return encodedDigit();

    return "";
}

string Soundex::encodedDigit() const {
    return "1";
}

string Soundex::head(const string& word) const {
    return word.substr(0, 1);
}

string Soundex::zeroPad(const string& word) const {
    auto zerosNeeded = MaxCodeLength - word.length();

    return word + string(zerosNeeded, '0');
}

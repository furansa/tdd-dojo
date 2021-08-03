#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>
#include <unordered_map>

using std::string;

class Soundex {
public:
    string encode(const string& word) const;

private:
    static const size_t MaxCodeLength{4};

    string encodedDigits(const string& word) const;
    string encodedDigit(char letter) const;
    string head(const string& word) const;
    string zeroPad(const string& word) const;
};
#endif

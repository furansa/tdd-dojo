#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>

using std::string;

class Soundex {
public:
    string encode(const string& word) const;

private:
    string zeroPad(const string& word) const;
};
#endif
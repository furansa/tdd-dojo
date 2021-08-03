#include "gmock/gmock.h"

#include "../../src/Soundex.hpp"

using testing::Eq;
using testing::Test;

class SoundexEncoding: public Test {
public:
    // Arrange
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    // Act
    auto encoded = soundex.encode("A");

    // Assert
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits) {
    // Act
    auto encoded = soundex.encode("I");

    // Assert
    ASSERT_THAT(encoded, Eq("I000"));
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

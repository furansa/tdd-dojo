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

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
    // Act
    auto encoded = soundex.encode("Ax");

    // Assert
    ASSERT_THAT(encoded, Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
    // Act
    auto encoded = soundex.encode("A#");

    // Assert
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
    // Act
    auto encoded = soundex.encode("Acdl");

    // Assert
    ASSERT_THAT(encoded, Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
    // Act
    auto encoded = soundex.encode("Dcdlb");

    // Assert
    ASSERT_THAT(encoded.length(), Eq(4u));
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

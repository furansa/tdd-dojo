#include "gmock/gmock.h"

#include "../../src/Soundex.hpp"

using testing::Eq;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    // Arrange
    Soundex soundex;

    // Act
    auto encoded = soundex.encode("A");

    // Assert
    ASSERT_THAT(encoded, Eq("A"));
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

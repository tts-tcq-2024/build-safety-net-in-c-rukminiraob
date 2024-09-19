#include "Soundex.h"
#include <gtest/gtest.h>

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];

    generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A200");

    generateSoundex("Robert", soundex);
    ASSERT_STREQ(soundex, "R163");

    generateSoundex("Rupert", soundex);
    ASSERT_STREQ(soundex, "R163");

    generateSoundex("Rubin", soundex);
    ASSERT_STREQ(soundex, "R150");

    generateSoundex("Ashcraft", soundex);
    ASSERT_STREQ(soundex, "A261");

    generateSoundex("Ashcroft", soundex);
    ASSERT_STREQ(soundex, "A261");
}

TEST(SoudexTestsuite, NonAlphabetCharacter) {
    char soundex[5];

    generateSoundex("A#hcroft", soundex);
    ASSERT_STREQ(soundex, "A261");
}

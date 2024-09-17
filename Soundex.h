#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

//...........................ABCDEFGHIJKLMNOPQRSTUVWXYZ
static const char* mappings = "01230120022455012623010202";

char getMappedChar(char c) {
    c = toupper(c);

    if (c < 'A' || c > 'Z') {
        return '0'; // Handle non-alphabetic characters
    }

    return mappings[c - 'A'];
}

int isValidToAdd(char mappedChar, char lastChar, int si) {
    return (si < 4) && (mappedChar != '0') && (mappedChar != lastChar);
}

void addChar(char mappedChar, char* soundex, int* sip) {
    if (isValidToAdd(mappedChar, soundex[*sip - 1], *sip)) {
        soundex[*sip] = mappedChar;
        (*sip)++;
    }
}

void generateSoundex(const char* name, char* soundex) {
    int si = 1;
    soundex[0] = toupper(name[0]);
    int l = strlen(name);

    for (int i = 1; i < l; i++) {
        char mappedChar = getMappedChar(name[i]);
        addChar(mappedChar, soundex, &si);
    }

    while (si < 4) {
        soundex[si++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H

#include "token.h"
#include <iostream>

static std::string identifierStr;
static double NumVal;

// function for lexing
static int getTokens()
{
    // initializes lastChar
    static int lastChar = ' ';

    // skipping whitespace
    while (isspace(lastChar))
        lastChar = getchar();

    // checks if char is an alphabet
    if (isalpha(lastChar))
    {
        // gets words
        identifierStr = lastChar;
        while (isalnum((lastChar = getchar())))
            identifierStr += lastChar;

        // checks if word is def or extern
        if (identifierStr == "def")
            return tok_def;
        if (identifierStr == "extern")
            return tok_extern;
        return tok_identifier;
    }
}
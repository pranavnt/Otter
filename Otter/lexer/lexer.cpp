#include "token.h"
#include <iostream>

static std::string identifierStr;
static double numVal;

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

    // if char is a digit or . (decimal)
    if (isdigit(lastChar) || lastChar == '.')
    {
        // string for numbers
        std::string numStr;

        // goes through string until it gets the full number
        do
        {
            numStr += lastChar;
            lastChar = getchar();
        } while (isdigit(lastChar) || lastChar == '.');

        // converts string to double
        numVal = strtod(numStr.c_str(), 0);
        return tok_number;
    }

    // checks for comments
    // TODO: Switch to // and /*
    if (lastChar == '#')
    {
        // ignores line if it starts with # (soon //)
        do
            lastChar = getchar();
        while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        // making sure final char is not at EOF
        if (lastChar != EOF)
            return getTokens();
    }

    // checks if final character is eof
    if (lastChar == EOF)
        return tok_eof;

    // returns final char
    int thisChar = lastChar;
    lastChar = getchar();
    return thisChar;
}

int main()
{
    std::cout << getTokens();
}

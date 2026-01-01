#ifndef EINFACHLANG_TOKEN_H
#define EINFACHLANG_TOKEN_H


union TokenValue {
    double as_double;
    int as_int;
    char as_char;
    const char* as_str;
};

enum TokenType {
    Token_Int,
    Token_Double,
    Token_String,

    Token_Plus,
    Token_Minus,
    Token_Asterisk,
    Token_Slash,

    Token_EOF
};

struct Token {
    union TokenValue value;
    enum TokenType type;
};

#endif
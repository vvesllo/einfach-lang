#ifndef EINFACHLANG_LEXER_H
#define EINFACHLANG_LEXER_H


#include "../../include/parser/token.h"


struct Lexer
{
    const char* source;
    char current;
    size_t position;
};

struct Lexer* lexer_init(const char* source);

char lexer_advance(struct Lexer* lexer);

struct Token* lexer_next_token(struct Lexer* lexer);

struct Token* lexer_eof(struct Lexer* lexer);

struct Token* lexer_parse_int(struct Lexer* lexer);

struct Token* lexer_parse_operator(struct Lexer* lexer);

void lexer_skip_whitespaces(struct Lexer* lexer);

void lexer_destroy(struct Lexer* lexer);

#endif
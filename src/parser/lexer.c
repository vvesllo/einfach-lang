#include "../../include/parser/lexer.h"
#include <corecrt_search.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Lexer* lexer_init(const char* source)
{
    struct Lexer* lexer = (struct Lexer*)malloc(sizeof(struct Lexer));

    lexer->position = 0;
    lexer->source = source;
    lexer->current = source[0];

    return lexer;
}

char lexer_advance(struct Lexer* lexer)
{
    if (lexer->current == '\0') return '\0';
    
    lexer->current = lexer->source[++lexer->position];
    return lexer->current;
}

struct Token* lexer_next_token(struct Lexer* lexer)
{
    if (isspace(lexer->current)) lexer_skip_whitespaces(lexer);

    if (lexer->current == '\0') return lexer_eof(lexer);
    
    if (isdigit(lexer->current))  return lexer_parse_int(lexer);

    return lexer_parse_operator(lexer);
}

struct Token* lexer_eof(struct Lexer* lexer)
{
    struct Token* token = (struct Token*)malloc(sizeof(struct Token));
    token->type = Token_EOF;
    token->value.as_int = 0;
    return token;
}

struct Token* lexer_parse_int(struct Lexer* lexer)
{
    size_t position = lexer->position;
    while (isdigit(lexer->current))
        lexer_advance(lexer);

    size_t length = lexer->position - position;
    char* value = (char*)malloc(length + 1);
    memcpy(value, lexer->source + position, length);
    value[length] = '\0';

    struct Token* token = (struct Token*)malloc(sizeof(struct Token));
    token->type = Token_Int;
    token->value.as_int = atoi(value);

    free(value);

    return token;
}

struct Token* lexer_parse_operator(struct Lexer* lexer)
{
    struct Token* token = (struct Token*)malloc(sizeof(struct Token));
    token->value.as_char = lexer->current;
    
    lexer_advance(lexer);

    switch (token->value.as_char) 
    {
    case '+': token->type = Token_Plus; break;
    case '-': token->type = Token_Minus; break;
    case '*': token->type = Token_Asterisk; break;
    case '/': token->type = Token_Slash; break;
    default: 
        free(token);
        return NULL;
    }

    return token;
}

void lexer_skip_whitespaces(struct Lexer* lexer)
{
    while (isspace(lexer->current))
        lexer_advance(lexer);
}

void lexer_destroy(struct Lexer* lexer)
{
    free(lexer);
}
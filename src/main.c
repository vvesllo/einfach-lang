#include "../include/parser/lexer.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char* source = "123 + 2 - 2123123";

    struct Lexer* lexer = lexer_init(source);
    struct Token* token;

    short running = 1;

    while (running) 
    {
        token = lexer_next_token(lexer);
        if (token)
        {
            switch (token->type) 
            {
            case Token_Int:
                printf("Int: %d\n", token->value.as_int);
                break;
            case Token_Plus:
            case Token_Minus:
            case Token_Asterisk:
            case Token_Slash:
                printf("Operator: %c\n", token->value.as_char);
                break;
            case Token_EOF:
                running = 0;
                break;
            default:
                printf("Unknown token\n");
                break;
            }
        }
        else 
        {
            printf("Null token\n");
        }
    }

    free(token);

    lexer_destroy(lexer);

    return 0;
}
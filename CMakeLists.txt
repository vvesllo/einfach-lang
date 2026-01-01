cmake_minimum_required(VERSION 4.2)

project(einfachlang C)

add_executable(${PROJECT_NAME}
    src/main.c
    src/parser/lexer.c      include/parser/lexer.h
    src/parser/token.c      include/parser/token.h
)
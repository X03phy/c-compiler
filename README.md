# c-compiler
Writing a C compiler from scratch - Using Assembly and C

## Structure

1. The lexer breaks up the source code into a list of tokens. Tokens are the
smallest syntactic units of a program; they include delimiters, arith-
metic symbols, keywords, and identifiers. If a program is like a book,
tokens are like individual words.2. The parser converts the list of tokens into an abstract syntax tree (AST),
which represents the program in a form we can easily traverse and
analyze.
3. The assembly generation pass converts the AST into assembly. At this
stage, we still represent the assembly instructions in a data structure
that the compiler can understand, not as text.
4. The code emission pass writes the assembly code to a file so the assembler
and linker can turn it into an executable.


## C norm

https://www.kernel.org/doc/html/v4.10/process/coding-style.html

https://en.cppreference.com/w/c/keyword.html
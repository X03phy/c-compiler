#include "lexer.h"
#include <stdbool.h> // bool, true, false
#include <stddef.h> // size_t
#include <string.h> // strncmp()


bool is_keyword(const char *start, size_t len)
{
	static const char *keywords[] = {"auto", "break", "case", "char",
				    "const", "continue", "default", "do",
				    "double", "else", "enum", "extern",
				    "float", "for", "goto",  "if",
				    "int", "long", "register", "return",
				    "short", "signed",  "sizeof", "static",
				    "struct", "switch", "typedef", "union",
				    "unsigned", "void", "volatile", "while"
				   };

	for (size_t i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i += 1) {
		if (strlen(keywords[i]) == len
		    && strncmp(start, keywords[i], len) == 0)
			return (true);
	}

	return (false);
}

#include "lexer.h"


bool is_keyword(const char *start, size_t len)
{
	const char *keywords[32] = {"auto", "break", "case", "char",
				    "const", "continue", "default", "do",
				    "double", "else", "enum", "extern",
				    "float", "for", "goto",  "if",
				    "int", "long", "register", "return",
				    "short", "signed",  "sizeof", "static",
				    "struct", "switch", "typedef", "union",
				    "unsigned", "void", "volatile", "while"
				   };

	for (int i = 0; i < 32; i += 1)
		if (strncmp(start, keywords[i], len) == 0)
			return (true);

	return (false);
}

//// https://www.cs.auckland.ac.nz/references/unix/digital/AQTLTBTE/DOCU_008.HTM
//bool is_punctuator(const char *substr)
//{
//	const char *punctuators[] = {"{", "}", "(", ")", ";"};

//	for (int i = 0; i < ARRAY_SIZE(punctuators); i += 1)
//		for (int i = 0; i < ARRAY_SIZE(punctuators); i += 1)
//		if (strcmp(substr, punctuators[i]) == 0)
//			return (true);

//	return (false);
//}

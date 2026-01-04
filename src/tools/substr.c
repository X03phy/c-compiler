#include <stdio.h>
#include <string.h> // For strlen(), strdup()
#include <stdlib.h>

char *substr(char const *str, unsigned int start, size_t length)
{
	size_t str_len;
	size_t copy_len;
	char   *sub;

	if (!str)
		return (NULL);

	str_len = strlen(str);
	if (str_len <= start)
		return (strdup(""));

	copy_len = str_len - start;
	if (copy_len > length)
		copy_len = length;
	copy_len += 1;

	sub = malloc(sizeof(char) * copy_len);
	if (!sub)
		return (NULL);

	strncpy(sub, (str + start), copy_len);

	return (sub);
}

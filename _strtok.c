#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _strtok(const char *str, char delimeter)
{
	int len = strlen(str);
	char word[len + 1];
	int i, j;

	for (i = 0; i <= len; i++)
	{
		j = 0;
		if (str[i] == delimeter || str[i] == '\0')
			word[j] = '\0';
		if (j > 0)
		{
		printf("%s\n", word);
		j = 0;
		}
		else
		{
		word[j++] = str[i];
		}

	}
}

int main(void)
{
	const char *string = "no woman no cry";
	char delim = ' ';
	char *token;


	token = malloc(sizeof(char) * 49);
	strcpy(token, string);

	token = _strtok(string, delim);
	printf("%s\n", token);
	return (0);
}

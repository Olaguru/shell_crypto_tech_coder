#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void check_command(char *command)
{
	if (access(command, F_OK) == 0)
		printf("%s: Found\n", command);
	else
		printf("%s: NOT FOUND\n", command);
}

int main()
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t chars;
	char *token;

	while (1)
	{
		write(1, "$ ", 2);
		chars = getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, " \t\n");
		if (strcmp(token, "which") == 0)
		{
			token = strtok(NULL, " \t\n");
			while (token)
			{
				check_command(token);
				token = strtok(NULL, " \t\n");
			}

		}
		else
			printf("command dosent exist\n");;
	}
	return (0);
}

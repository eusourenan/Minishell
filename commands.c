#include "header.h"

/**
 * @param input Input typing by the user.
 * @brief Count the number of pipes that separates commands.
 **/
int	count_pipes(char *input)
{
	int	pipes;

	if (input == NULL)
		return (0);
	pipes = 0;
	while (*input != '\0')
	{
		if (*input == '\'' || *input == '"')
			input = ft_strchr(input + 1, *input);
		input++;
		if (*input == '|')
			pipes++;
	}
	return (pipes);
}

char	**insert_command(char *input, char **commands)
{
	int		line;
	char	*start;

	start = input;
	line = 0;
	while (*input)
	{
		if (*input == '\'' || *input == '"')
			input = ft_strchr(input + 1, *input);
		input++;
		if (*input == '|' || *input == '\0')
		{
			commands[line] = ft_substr(start, 0, input - start);
			if (commands[line] == NULL)
			{
				free_matrix((void **)commands);
				return (NULL);
			}
			line++;
			if (*input)
				start = input + 1;
		}
	}
	commands[line] = NULL;
	return (commands);
}

/**
 * @param input Input typing by the user.
 * @brief Splits the commands through the pipes.
 *
 * @note Some errors examples:
 * @note <many spaces> | echo hi
 * @note echo "hi"' that is the complement' | | grep o
 * @note echo "hi"' that is the complement' | grep o |
 **/
char	**split_commands(char *input)
{
	char	**commands;
	int		line;

	if (input == NULL)
		return (NULL);
	line = 0;
	commands = (char **) malloc ((count_pipes(input) + 2) * sizeof(char*));
	if (commands == NULL)
		return (NULL);
	commands = insert_command(input, commands);
	if (!commands)
		return (NULL);
	return (commands);
}

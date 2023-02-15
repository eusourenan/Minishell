
#include "header.h"

void	print_error(void)
{
	printf("Man! You just have ONE job. Close your quotes!");
	exit(2);
}

int	has_unclosed_quotes(char *input)
{
	char	quote;
	char	*tmp;

	while (*input)
	{
		if (*input == '\'')
		{
			tmp = strchr(input + 1, '\'');
			if (!tmp)
				return (1);
			input = tmp + 1;
		}
		else if (*input == '"')
		{
			tmp = strchr(input + 1, '"');
			if (!tmp)
				return (1);
			input = tmp + 1;
		}
	}
	return (0);
}

// Fazer recursivo
void	remove_quotes(char *input)
{
	char	quote;

	while (*input)
	{
		quote = 0;
		while (*input && !quote)
		{
			if (*input == '\'' || *input == '"')
			{
				quote = *input;
				memmove(input, input + 1, strlen(input));
			}
			else
				input++;
		}
		while (*input && quote)
		{
			if (*input == quote)
			{
				memmove(input, input + 1, strlen(input));
				break ;
			}
			input++;
		}
	}
}
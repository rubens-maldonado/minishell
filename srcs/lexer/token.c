/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:51:31 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 09:15:39 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 
#include "parse.h"
#include "lexer.h"

void	verify_token(t_token *tok, char **string, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tok[i].value = ft_strdup(string[i]);
		if (!ft_strcmp(string[i], "<<"))
			tok[i].type = LEFT_DOUBLE;
		else if (!ft_strcmp(string[i], ">>"))
			tok[i].type = RIGHT_DOUBLE;
		else if (!ft_strcmp(string[i], "<"))
			tok[i].type = LEFT;
		else if (!ft_strcmp(string[i], ">"))
			tok[i].type = RIGHT;
		else if (!ft_strcmp(string[i], "|"))
			tok[i].type = PIPE;
		else if (string[i][0] == '\'')
			tok[i].type = STRING;
		else if (ft_strnstr(string[i], "$", ft_strlen(string[i])))
			tok[i].type = VARS;
		else
			tok[i].type = STRING;
		i++;
	}
}

int	count(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		i++;
	return (i);
}

void	create_tokens(char **str, int i, t_token **tok, t_minishell *shell)
{
	if (!tok)
		return ;
	verify_token(*tok, str, i);
	start_parse(*tok, i, shell);
}

int	start_lexer(char *prompt, t_minishell *shell)
{
	char	**s;
	int		i;
	t_token	*tok;

	i = 0;
	while (prompt[i] == ' ')
		i++;
	if (!prompt[i])
		return (0);
	s = ft_split(prompt, ' ');
	i = count(s);
	if (!verify_exit(s, i))
	{
		free_pointer(s);
		return (0);
	}
	tok = ft_calloc(sizeof(t_token), (i + 1));
	create_tokens(s, i, &tok, shell);
	free_pointer(s);
	return (1);
}

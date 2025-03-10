/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:19:48 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/26 10:57:35 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum e_type {
	NONE,
	STRING,
	LEFT_DOUBLE,
	RIGHT_DOUBLE,
	LEFT,
	RIGHT,
	PIPE,
	VARS,
}	t_type;

typedef struct s_token
{
	t_type	type;
	char	*value;
}	t_token;

int		start_lexer(char *input, t_minishell *shell);
int		count(char **result);
void	free_tokens2(t_token *tokens);
#endif

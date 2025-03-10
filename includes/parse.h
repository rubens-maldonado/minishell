/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 06:21:27 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/24 21:58:34 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"
# include "lexer.h"

void	start_parse(t_token *tok, int i, t_minishell *shell);
void	join_tokens(t_token *tok, int size, t_minishell *shell);
#endif

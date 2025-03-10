/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:05:29 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/29 21:01:42 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSER_H
# define EXPANSER_H

# include "minishell.h"
# include "lexer.h"

void	set_list(t_minishell *shell);
void	print_list(t_minishell *shell);
int		check_path(char *str, t_minishell *shell);
int		count_npath(char *str, int i);
int		count_path(char *str, int i);
int		count_src(char *str);
int		expanser(t_token *tokens, t_minishell *shell, int pos);
char	*expanse_path(char *str, char *path, int *i, t_minishell *shell);
char	*expanse_str(char *str, char *path, int *i);
char	*get_path(char *str, t_minishell *shell);
char	*find_path(char *str, t_minishell *shell);
char	*remove_quotes(char *str);
char	*remove_simples(char *str);
char	*select_option(char *args);
int		verify_simple_quotes(char *args);
#endif

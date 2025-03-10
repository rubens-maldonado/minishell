/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:20:31 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/29 17:46:06 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

void	split_commands(char **args, t_minishell *shell);
void	exec_commands(char **args, t_minishell *shell);
void	echo(char **args, int size);
void	export_str(char *str, t_minishell *shell);
void	unset(char *str, t_minishell *shell);
void	pwd(void);
void	print_env(t_minishell *shell);
void	cd(char **path, t_minishell *shell);
int		size_env(t_minishell *env);
int		search_env(char *env, t_minishell *shell);
char	*get_env(char *env, t_minishell *shell);
char	*get_pwd(void);
char	*filling_msg(char *str);
int		check_directory(char *res_split);
#endif

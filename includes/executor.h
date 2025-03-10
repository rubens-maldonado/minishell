/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:54:59 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 10:04:54 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"
# include "commands.h"
# include "expanser.h"
# include <fcntl.h>

void	pidwait(pid_t pid, int exit, char *cmd);
void	search_path(t_minishell *shell);
void	my_execv(t_minishell *shell, char **res_split);
void	create_here(char *delimiter, int *fd);
void	create_heredoc(char *delimiter, int *fd);
void	ft_pipex(t_minishell *shell, char ***split, int **fd);
int		redirect(char **args, int *fd);
int		redirect_solo(char **args, int *fd);
char	*mount_command(t_minishell *shell, char **res_split);
char	**format_cmd(char **split_cmd);
void	final_wait(pid_t pid, int i);
#endif

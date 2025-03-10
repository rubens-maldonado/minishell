/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:56:35 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/28 19:50:10 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <sys/ioctl.h>
# include <sys/wait.h>

extern int	g_exit_status;

typedef struct s_minishell
{
	char	**env;
	char	**env_path;
	char	*oldpwd;
	char	**list;
	int		c;
	int		fd_in;
	int		fd_out;
	int		fd[2];
	int		n_comm;
}	t_minishell;

int		verify_exit(char **message, int i);
void	error(void);
void	free_execve(char *src);
void	free_wait(char *src);
void	free_ptwo(char ***pointer);
void	free_pointer(char **pointer);
void	free_all(t_minishell *shell, char *str, char *str2);
void	free_alltwo(t_minishell *shell, char *str, char *str2);
void	free_str(char *str, char *msg);
void	my_env(char **str, t_minishell *shell);
size_t	count_env(t_minishell *shell);
size_t	count_var(char *str);
void	print_error(char *str);
void	ctrl_handler(char *args, t_minishell *shell);
void	set_signal(void);
void	set_signal_child(void);
#endif

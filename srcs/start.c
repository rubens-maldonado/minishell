/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:15:33 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 09:55:55 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

int	g_exit_status;

int	verify_exit2(char **message)
{
	write(2, "exit\n", 5);
	write(2, "minishell:", 10);
	write(2, " exit: ", 7);
	write(2, message[1], ft_strlen(message[1]));
	write(2, ": numeric argument required\n", 28);
	exit(255);
}

int	verify_exit(char **message, int i)
{
	int	exit_status;

	exit_status = 0;
	if (!ft_strcmp("exit", message[0]) && i >= 2)
	{
		if (ft_isdigit(message[1]) && message[2])
		{
			write(2, "exit\n", 5);
			write(2, "minishell: exit: too many arguments\n", 36);
			g_exit_status = 1;
			return (0);
		}
		else if (ft_isdigit(message[1]) && !message[2])
		{
			exit_status = ft_atoi(message[1]);
			write(2, "exit\n", 5);
			exit(exit_status);
		}
		else if (!ft_isdigit(message[1]))
			verify_exit2(message);
	}
	else if (!ft_strcmp("exit", message[0]))
		exit(0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char		*prompt;
	t_minishell	shell;

	(void) argv;
	my_env(envp, &shell);
	g_exit_status = 0;
	shell.fd_in = dup(0);
	shell.fd_out = dup(1);
	if (argc > 1)
		error();
	while (1)
	{
		set_signal();
		prompt = readline("➜Minishell✗ ");
		if (prompt == NULL)
			ctrl_handler(prompt, &shell);
		if (prompt[0])
		{
			add_history(prompt);
			start_lexer(prompt, &shell);
		}
		free(prompt);
	}
	close(shell.fd_in);
	close(shell.fd_out);
}

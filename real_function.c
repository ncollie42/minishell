/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:43:55 by ncollie           #+#    #+#             */
/*   Updated: 2019/01/08 21:31:24 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <signal.h>

static int	child_process(char **argv)
{
	char *path;

	signal(SIGINT, SIG_DFL);
	if (ft_strchr(argv[0], '/'))
		execve(argv[0], argv, g_environ);
	if (!(path = look_function_location(argv[0])))
	{
		b_printf("zsh: command not found: %s\n", argv[0]);
		exit(0);
		return (1);
	}
	if (execve(path, argv, g_environ) == -1)
	{
		b_printf("execve has failed\n");
		exit(1);
	}
	return (1);
}

int			real_function(char **argv)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		b_printf("fork failed!\n");
		exit(0);
	}
	else if (pid == 0)
		child_process(argv);
	else
		waitpid(pid, &status, 0);
	return (1);
}

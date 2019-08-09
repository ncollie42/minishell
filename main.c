/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:41:09 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/08 20:40:28 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "header.h"
#include <signal.h>

/*
**	Main idea:
**
**	loda up data	//init
**	run loop
**	shutdown / clean -- up
*/

void	handler(int num)
{
	(void)num;
	b_printf("\033[4G  \n\033[32m>>>\033[0m");
}

int		main(void)
{
	signal(SIGINT, handler);
	set_environ();
	main_loop();
}

/*
** Read: stdin
** Parce: program / args
** Execute: run command
*/

void	main_loop(void)
{
	char	*line;
	char	**argv;
	int		status;

	status = 1;
	while (1)
	{
		prompt();
		line = read_input();
		argv = parse_words(line);
		if (remove_quotes(argv) == -1)
		{
			ft_free(argv, line);
			continue ;
		}
		replace_argvs(argv);
		run(argv);
		ft_free(argv, line);
	}
}

void	set_environ(void)
{
	extern char	**environ;
	int			size;
	int			n;

	n = -1;
	size = double_char_ptr_size(environ);
	g_environ = malloc(sizeof(char *) * (size + 1));
	while (environ[++n])
		g_environ[n] = ft_strdup(environ[n]);
	g_environ[n] = NULL;
}

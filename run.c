/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:05:58 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/10 18:47:57 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "structs.h"

void	ft_echo(char **argv)
{
	int n;

	n = 0;
	if (argv[1])
	{
		while (argv[++n])
		{
			b_printf("%s", (argv[n]));
			if (argv[n + 1])
				b_printf(" ");
		}
	}
	b_printf("\n");
}

void	ft_exit(char **argv)
{
	(void)argv[0];
	exit(0);
}

void	env(char **argv)
{
	int	n;

	(void)argv[0];
	n = -1;
	while (g_environ[++n])
		b_printf("%s\n", g_environ[n]);
}

void	run(char **argv)
{
	t_built_in	*list;
	int			n;

	n = -1;
	list = set_list();
	if (!argv[0])
		return ;
	while (list[++n].name)
		if (!ft_strcmp(argv[0], list[n].name))
		{
			(list[n].function(argv));
			return ;
		}
	real_function(argv);
	return ;
}

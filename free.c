/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:52:55 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/08 20:44:47 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_free(char **argv, char *line)
{
	int n;

	n = -1;
	while (argv && argv[++n])
	{
		free(argv[n]);
	}
	free(argv);
	free(line);
}

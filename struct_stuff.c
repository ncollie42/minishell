/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:54:18 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/07 19:49:32 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "structs.h"

t_built_in	*set_list(void)
{
	t_built_in	*list;

	list = (t_built_in[])
	{
		{"echo", ft_echo},
		{"exit", ft_exit},
		{"env", env},
		{"cd", ft_cd},
		{"setenv", ft_setenv},
		{"unsetenv", ft_unsetenv},
		{NULL, NULL},
	};
	return (list);
}

t_color		*set_color(void)
{
	t_color *list;

	list = (t_color[])
	{
		{"red", "\033[31m"},
		{"green", "\033[32m"},
		{"yellow", "\033[33m"},
		{"blue", "\033[34m"},
		{NULL, NULL},
	};
	return (list);
}

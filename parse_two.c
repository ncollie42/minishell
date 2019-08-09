/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:18:26 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/10 19:15:03 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		regular(char *str)
{
	int n;

	n = 0;
	while (*str && *str != 9 && *str != 11 && *str != 32)
		n++;
	return (n);
}

char	*move_to_next_word(char *str)
{
	while (*str == 9 || *str == 11 || *str == 32)
		str++;
	return (str);
}

int		remove_quotes(char **argv)
{
	int n;

	n = -1;
	if (argv)
	{
		while (argv[++n])
		{
			if (!(argv[n] = remove_quotes_string(&argv[n])))
				return (-1);
		}
	}
	return (0);
}

char	*test(char **line, char c)
{
	int		n;
	char	*temp;

	n = 0;
	temp = *line;
	while ((temp = ft_strchr(temp, c)))
	{
		temp++;
		n++;
	}
	if (n == 2)
	{
		if (ft_strlen(*line) == 2)
			temp = "";
		else
			temp = ft_strndup(*line + 1, ft_strlen(*line) - 2);
		ft_strdel(line);
		return (temp);
	}
	if (n == 1)
		b_printf("unmatched quote\n");
	free(*line);
	return (NULL);
}

char	*remove_quotes_string(char **line)
{
	if (*(line[0]) == '"')
	{
		return (test(line, '"'));
	}
	else if (*(line[0]) == '\'')
	{
		return (test(line, '\''));
	}
	return (*line);
}

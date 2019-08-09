/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:09:33 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/07 20:03:14 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_built_in
{
	char		*name;
	void		(*function)(char **argv);
}				t_built_in;

typedef struct	s_color
{
	char		*name;
	char		*color;
}				t_color;
#endif

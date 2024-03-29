/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <mmark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:01:31 by jvoor             #+#    #+#             */
/*   Updated: 2019/08/14 16:43:36 by mmark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_strs_words(char **str)
{
	char		**buff;
	int			count_first;
	int			count_next;
	int			i;

	i = 0;
	count_first = 0;
	count_next = 0;
	buff = (ft_strsplit(str[0], ' ') - 1);
	while (*(++buff) != NULL)
		count_first++;
	while (str[++i])
	{
		buff = ft_strsplit(str[i], ' ');
		while (*buff != NULL)
		{
			buff++;
			count_next++;
		}
		if (count_first != count_next)
			return (-1);
		count_next = 0;
	}
	return (1);
}

static int		check_symbs(char **str)
{
	int			i;
	int			j;

	i = -1;
	while (str[++i] != NULL)
	{
		j = -1;
		while (str[i][++j] != '\0')
		{
			if ((!('a' <= str[i][j] && str[i][j] <= 'f'))
				&& (!('A' <= str[i][j] && str[i][j] <= 'F'))
				&& (!('0' <= str[i][j] && str[i][j] <= '9'))
				&& (str[i][j] != 'x') && (str[i][j] != ',')
				&& (str[i][j] != ' ') && (str[i][j] != '-'))
				return (0);
		}
	}
	return (1);
}

int				is_valid(char **str)
{
	if ((check_strs_words(str) == 1) && (check_symbs(str) == 1))
		return (1);
	return (0);
}

int				name_valid(char *name)
{
	char		*str;

	str = ft_strstr(name, ".fdf");
	if (str == 0)
		return (0);
	return (1);
}

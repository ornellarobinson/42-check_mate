/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:42:31 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/22 12:02:54 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

static int	check_line(int i, char **tab)
{
	int j;

	j = 0;
	while (tab[i][j])
	{
		if (tab[i][j] == 'K')
			return (1);
		j++;
	}
	return (0);
}

static int	check_column(int j, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][j] == 'K')
			return (1);
		i++;
	}
	return (0);
}

int			check_rook(char **tab, int i, int j)
{
	if (check_line(i, tab) == 1)
		return (1);
	else if (check_column(j, tab) == 1)
		return (1);
	return (0);
}

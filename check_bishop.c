/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bishop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:55:05 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/22 00:02:13 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

static int	check_diago_top_left(char **tab, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= size)
		return (-1);
	if (tab[i][j] == 'K')
		return (1);
	return (check_diago_top_left(tab, i - 1, j + 1, size));
}

static int	check_diago_top_right(char **tab, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= size)
		return (-1);
	if (tab[i][j] == 'K')
		return (1);
	return (check_diago_top_right(tab, i - 1, j - 1, size));
}

static int	check_diago_bottom_left(char **tab, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= size)
		return (-1);
	if (tab[i][j] == 'K')
		return (1);
	return (check_diago_bottom_left(tab, i + 1, j - 1, size));
}

static int	check_diago_bottom_right(char **tab, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= size)
		return (-1);
	if (tab[i][j] == 'K')
		return (1);
	return (check_diago_bottom_right(tab, i + 1, j + 1, size));
}

int			check_bishop(char **tab, int i, int j, int size)
{
	if (check_diago_top_left(tab, i, j, size) == 1)
		return (1);
	if (check_diago_top_right(tab, i, j, size) == 1)
		return (1);
	if (check_diago_bottom_left(tab, i, j, size) == 1)
		return (1);
	if (check_diago_bottom_right(tab, i, j, size) == 1)
		return (1);
	return (0);
}

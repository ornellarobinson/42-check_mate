/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bishop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:55:05 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/21 23:55:38 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

static int	check_diago_haut_gauche(char **tab, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= size)
		return (-1);
	if (tab[i][j] == 'K')
		return (1);
	return (check_diago_haut_gauche(tab, i - 1, j + 1, size));
}

static int	check_diago_haut_droite(char **tab, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= size)
		return (-1);
	if (tab[i][j] == 'K')
		return (1);
	return (check_diago_haut_droite(tab, i - 1, j - 1, size));
}

static int	check_diago_bas_gauche(char **tab, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= size)
		return (-1);
	if (tab[i][j] == 'K')
		return (1);
	return (check_diago_bas_gauche(tab, i + 1, j - 1, size));
}

static int	check_diago_bas_droite(char **tab, int i, int j, int size)
{
	if (i < 0 || j < 0 || i >= size || j >= size)
		return (-1);
	if (tab[i][j] == 'K')
		return (1);
	return (check_diago_bas_droite(tab, i + 1, j + 1, size));
}

int		check_bishop(char **tab, int i, int j, int size)
{
	if (check_diago_haut_gauche(tab, i, j, size) == 1)
		return (1);
	if (check_diago_haut_droite(tab, i, j, size) == 1)
		return (1);
	if (check_diago_bas_gauche(tab, i, j, size) == 1)
		return (1);
	if (check_diago_bas_droite(tab, i, j, size) == 1)
		return (1);
	return (0);
}

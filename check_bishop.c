/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bishop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:55:05 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/21 19:20:20 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

static int	check_diago_haut_gauche(char **tab, int i, int j)
{
	while (tab[i - 1][j - 1])
	{
		if (tab[i - 1][j - 1] == 'K')
			return (1);
		i -= 1;
		j -= 1;
	}
	return (0);
}

static int	check_diago_haut_droite(char **tab, int i, int j)
{
	if ( && tab[i -1][])
	while (tab[i - 1][j + 1])
	{
		if (tab[i - 1][j + 1] == 'K')
			return (1);
		i -= 1;
		j += 1;
	}
	return (0);
}

static int	check_diago_bas_gauche(char **tab, int i, int j)
{
	if (tab[i + 1] && (j != 0))
	{
		while (tab[i + 1][j - 1])
		{
			if (tab[i + 1][j - 1] == 'K')
				return (1);
			i += 1;
			j += 1;
		}
	}
	return (0);
}

static int	check_diago_bas_droite(char **tab, int i, int j)
{
	if (tab[i + 1] && j != (ft_strlen(tab[i]) - 1))
	{
		while (tab[i + 1][j + 1])
		{
			if (tab[i + 1][j + 1] == 'K')
				return (1);
			i += 1;
			j += 1;
		}
	}
	return (0);
}

int		check_bishop(char **tab, int i, int j)
{
	if (check_diago_haut_gauche(tab, i, j) == 1)
		return (1);
	if (check_diago_haut_droite(tab, i, j) == 1)
		return (1);
	if (check_diago_bas_gauche(tab, i, j) == 1)
		return (1);
	if (check_diago_bas_droite(tab, i, j) == 1)
		return (1);
	return (0);
}

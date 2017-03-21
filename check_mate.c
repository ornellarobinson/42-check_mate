/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:39:03 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/21 19:06:03 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "check_mate.h"

static char **copy(char *argv[], char **tab)
{
	int i = 0;
	while (argv[i])
	{
		tab[i] = argv[i];
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static int	check_chessboard(char **tab)
{
	int i = 0;
	int j;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'R' && check_rook(tab, i, j))
				return (1);
			if (tab[i][j] == 'B' && check_bishop(tab, i, j))
				return (1);
			if (tab[i][j] == 'P' && check_pawn(tab, i, j))
				return (1);
			if (tab[i][j] == 'Q' && check_rook(tab, i, j) &&
			check_bishop(tab, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	char **tab;
	int i;

	i = 1;
	if (argc != 1)
	{
		if (!(tab = malloc(sizeof(char *) * argc)))
			return (-1);
		while (i < argc - 1)
		{
			if (!(tab[i] = malloc(sizeof(char) * argc - 1)))
				return (-1);
			i++;
		}
		tab = copy(argv, tab);
		if (check_chessboard(tab) == 1)
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
	return (0);
}

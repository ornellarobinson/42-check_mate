/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:39:03 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/22 15:17:28 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

static void	free_chessboard(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	**copy(char *argv[], char **tab)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		tab[i] = argv[j];
		i++;
		j++;
	}
	tab[i] = NULL;
	return (tab);
}

static int	check_chessboard(char **tab, int size)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'R' && check_rook(tab, i, j))
				return (1);
			if (tab[i][j] == 'B' && check_bishop(tab, i, j, size))
				return (1);
			if (tab[i][j] == 'P' && check_pawn(tab, i, j))
				return (1);
			if (tab[i][j] == 'Q' && check_rook(tab, i, j) &&
			check_bishop(tab, i, j, size))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			main(int argc, char *argv[])
{
	char	**tab;
	int		i;
	int		size;

	i = 1;
	size = t_strlen(tab[i]);
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
		if (check_chessboard(tab, size) == 1)
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
	free_chessboard(tab);
	return (0);
}

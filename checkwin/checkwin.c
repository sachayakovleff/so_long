/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:45:57 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/17 18:16:27 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	swaptox(char **map, int pos_x, int pos_y)
{
	int	count;

	count = 0;
	if (iswall(map[pos_y][pos_x - 1]) > -1)
	{
		map[pos_y][pos_x - 1] = 'x';
		count++;
	}
	if (iswall(map[pos_y][pos_x + 1]) > -1)
	{
		map[pos_y][pos_x + 1] = 'x';
		count++;
	}
	if (iswall(map[pos_y - 1][pos_x]) > -1)
	{
		map[pos_y - 1][pos_x] = 'x';
		count++;
	}
	if (iswall(map[pos_y + 1][pos_x]) > -1)
	{
		map[pos_y + 1][pos_x] = 'x';
		count++;
	}
	return (count);
}

int	scanmap(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'E' || map[j][i] == 'C')
				count += 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

int	changedvalues(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'v')
				count += setvent(map, i, j);
			if (map[j][i] == 'P' || map[j][i] == 'x')
				count += swaptox(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

int	checkpath(char **map)
{
	while (changedvalues(map) != 0)
		map = map;
	if (scanmap(map) != 0)
		return (-1);
	return (1);
}

int	checkwin(t_mlx *mlx)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (ft_arraylen(mlx->map) + 1));
	if (map == NULL)
	{
		freedata(mlx);
		return (ft_printf("malloc error"), -1);
	}
	while (mlx->map[i])
	{
		map[i] = ft_strdup(mlx->map[i]);
		i++;
	}
	map[i] = NULL;
	if (checkpath(map) == -1)
	{
		ft_printf("Error map unwinnable (can't reach all collectibles/exit)\n");
		freedata(mlx);
		freesplit(map);
		exit(0);
	}
	return (freesplit(map), 1);
}

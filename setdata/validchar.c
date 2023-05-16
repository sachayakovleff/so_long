/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:23:24 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/12 19:12:44 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkvent(t_mlx *mlx)
{
	int	count;
	int	j;
	int	i;

	i = 0;
	j = 0;
	count = 0;
	while (mlx->map[j])
	{
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == 'v')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	if (count == 0 || count == 2)
		return (1);
	return (-1);
}

int	ft_validchar(char c)
{
	if (!(c <= '9' && c >= '0') && c != 'd'
		&& c != 'p' && c != 'g' && c != 'e' && c != 's' && c != 'v')
		return (-1);
	return (1);
}

void	ft_checkplayerxpm(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 3)
		{
			if (mlx->player.playerimg[i][j] == NULL)
			{
				ft_printf("error, xpm file couldn't load a player xpm");
				freedata(mlx);
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_checkwallsxpm(t_mlx *mlx, int i)
{
	if (mlx->walls.walls_bot[0] == NULL || mlx->walls.walls_left[0] == NULL
		|| mlx->walls.walls_top[0] == NULL || mlx->walls.walls_right[0] == NULL)
	{
		{
			ft_printf("error, xpm file couldn't load a wall xpm");
			freedata(mlx);
			exit(0);
		}
	}
	while (i < 4)
	{
		if (mlx->walls.corner[i] == NULL)
		{
			ft_printf("error, xpm file couldn't load a corner xpm");
			freedata(mlx);
			exit(0);
		}
		i++;
	}
}

void	ft_checkgroundxpm(t_mlx *mlx, int i)
{
	while (i < 5)
	{
		if (mlx->walls.groundimg[i] == NULL)
		{
			ft_printf("error, xpm file couldn't load a ground xpm");
			freedata(mlx);
			exit(0);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:42:57 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/17 16:33:26 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "stdbool.h"
#include "../minilibx-linux/mlx.h"
#include "../getnextline/get_next_line.h"

void	setmapchar(t_mlx *mlx)
{
	mlx->content.exit = 'e';
	mlx->content.player = 'p';
	mlx->content.ground = 'g';
	mlx->content.vent = 'v';
	mlx->content.cornerbotleft = '1';
	mlx->content.cornerbotright = '3';
	mlx->content.cornertopleft = '7';
	mlx->content.cornertopright = '9';
	mlx->content.wallstop = '8';
	mlx->content.wallsleft = '4';
	mlx->content.wallsright = '6';
	mlx->content.wallsbot = '2';
	mlx->content.key = 'k';
}

void	getplayerpos(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[i])
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->player.pos_x = j * 32;
				mlx->player.pos_y = i * 32;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_setmap(t_mlx *mlx)
{
	char	*line_map;
	char	*res;
	int		fd;

	fd = open(mlx->mapfile, O_RDONLY);
	line_map = get_next_line(fd);
	if (line_map != NULL)
	{
		res = "";
		res = ft_strjoin(res, line_map);
		free(line_map);
		while (true)
		{
			line_map = get_next_line(fd);
			if (line_map == NULL)
				break ;
			res = ft_strjoin(res, line_map);
			free(line_map);
		}
		res = ft_strjoin(res, line_map);
		free(line_map);
		mlx->map = ft_split(res, '\n');
		return ;
	}
	mlx->map = NULL;
}

int	checkplayer(t_mlx *mlx, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (mlx->map[i])
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == c)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 1)
		return (-1);
	return (1);
}

int	checkchar(t_mlx *mlx)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 1;
	while (mlx->map[j])
	{
		while (mlx->map[j][i])
		{
			if (ft_validchar(mlx->map[j][i]) == -1)
			{
				ft_printf("invalid char in map lign %d col %d\n", j, i);
				res = -1;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (res);
}

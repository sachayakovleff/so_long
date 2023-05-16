/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:50:18 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/16 14:40:35 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_display(t_mlx *mlx, void *img, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = 1;
	pos_y = 1;
	pos_x = pos_x * x * 32;
	pos_y = pos_y * y * 32;
	if (img)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, pos_x, pos_y);
	else
	{
		freedata(mlx);
		ft_printf("error, xpm file couldn't load");
		exit(0);
	}
}

void	ft_display_walls(t_mlx *mlx, int i, int j)
{
	while (mlx->map[j])
	{
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == '7')
				ft_display(mlx, mlx->walls.corner[2], i, j);
			if (mlx->map[j][i] == '2')
				ft_display(mlx, mlx->walls.walls_top[0], i, j);
			if (mlx->map[j][i] == '9')
				ft_display(mlx, mlx->walls.corner[3], i, j);
			if (mlx->map[j][i] == '4')
				ft_display(mlx, mlx->walls.walls_right[0], i, j);
			if (mlx->map[j][i] == '3')
				ft_display(mlx, mlx->walls.corner[1], i, j);
			if (mlx->map[j][i] == '8')
				ft_display(mlx, mlx->walls.walls_bot[0], i, j);
			if (mlx->map[j][i] == '1')
				ft_display(mlx, mlx->walls.corner[0], i, j);
			if (mlx->map[j][i] == '6')
				ft_display(mlx, mlx->walls.walls_left[0], i, j);
			i++;
		}
		j++;
		i = 0;
	}
}

void	ft_display_player(t_mlx *mlx, int u)
{
	if (mlx->count[0] != mlx->count[1])
	{
		ft_printf("nombre de déplacement: %d\n", mlx->count[0]);
		mlx->count[1] = mlx->count[0];
	}
	ft_display(mlx, mlx->player.playerimg[mlx->player.facing][u],
		mlx->player.pos_x / 32, mlx->player.pos_y / 32);
}

void	ft_display_danger(t_mlx *mlx, int u)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[j])
	{
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == 'd')
			{
				if (u % 1000 < 500)
					ft_display(mlx, mlx->walls.groundimg[3], i, j);
				else
					ft_display(mlx, mlx->walls.groundimg[0], i, j);
			}
			i++;
		}
		j++;
		i = 0;
	}
}

void	ft_display_ground(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[j])
	{
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == 'g' || mlx->map[j][i] == 'p')
				ft_display(mlx, mlx->walls.groundimg[1], i, j);
			if (mlx->map[j][i] == 'e')
				ft_display(mlx, mlx->walls.groundimg[2], i, j);
			if (mlx->map[j][i] == 's')
				ft_display(mlx, mlx->walls.groundimg[0], i, j);
			if (mlx->map[j][i] == 'v')
				ft_display(mlx, mlx->walls.groundimg[4], i, j);
			i++;
		}
		j++;
		i = 0;
	}
}

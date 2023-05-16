/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:29:15 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/12 18:43:36 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freesplit(char **array);
void	ft_destroy_image(void *mlx_ptr, void *img);

void	freecorner(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_destroy_image(mlx->mlx_ptr, mlx->walls.corner[i]);
		i++;
	}
}

void	freewalls1(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		ft_destroy_image(mlx->mlx_ptr, mlx->walls.walls_bot[i]);
		i++;
	}
	i = 0;
	while (i < 1)
	{
		ft_destroy_image(mlx->mlx_ptr, mlx->walls.walls_left[i]);
		i++;
	}
}

void	freewalls2(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		ft_destroy_image(mlx->mlx_ptr, mlx->walls.walls_right[i]);
		i++;
	}
	i = 0;
	while (i < 1)
	{
		ft_destroy_image(mlx->mlx_ptr, mlx->walls.walls_top[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		ft_destroy_image(mlx->mlx_ptr, mlx->walls.groundimg[i]);
		i++;
	}
}

void	freeplayer(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 3)
		{
			ft_destroy_image(mlx->mlx_ptr, mlx->player.playerimg[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	freedata(t_mlx *mlx)
{
	freecorner(mlx);
	freeplayer(mlx);
	freewalls1(mlx);
	freewalls2(mlx);
	if (mlx->mapfile)
		free(mlx->mapfile);
	freesplit(mlx->map);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

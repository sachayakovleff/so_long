/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:03:14 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/15 16:46:07 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

void	ft_setmap(t_mlx *mlx);
int		ft_checkmap(t_mlx *mlx);

void	ft_setplayerimg(t_mlx *mlx)
{
	mlx->player.playerimg[0][0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_s1.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[0][1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_s2.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[0][2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_s3.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[1][0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_w1.xpm", &mlx->player.imgsize_x,
			&mlx->player.imgsize_y);
	mlx->player.playerimg[1][1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_w2.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[1][2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_w3.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
}

void	ft_setwall_left_right(t_mlx *mlx)
{
	mlx->walls.walls_left[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/walls/wall_left/wall1.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.walls_right[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/walls/wall_right/wall1.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.corner[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/corner_bottom_left.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.corner[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/corner_bottom_right.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.corner[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/corner_top_left.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.corner[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/corner_top_right.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
}

void	ft_setwall_top_bot(t_mlx *mlx)
{
	mlx->walls.walls_bot[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/walls/wall_bot/floor1.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.walls_top[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/walls/wall_top/wall1.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->player.playerimg[2][0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_e1.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[2][1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_e2.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[2][2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_e3.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[3][0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_n1.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[3][1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_n2.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
	mlx->player.playerimg[3][2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/player/player_n3.xpm",
			&mlx->player.imgsize_x, &mlx->player.imgsize_y);
}

void	ft_setfloor(t_mlx *mlx)
{
	mlx->walls.groundimg[0] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/floor/bdanger.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.groundimg[1] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/floor/classic_floor.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.groundimg[2] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/floor/exit.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.groundimg[3] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/floor/rdanger.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
	mlx->walls.groundimg[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./xpm/map/floor/vent.xpm",
			&mlx->walls.imgsize_x, &mlx->walls.imgsize_y);
}

void	setdata(t_mlx *mlx)
{
	mlx->player.imgsize_x = 33;
	mlx->player.imgsize_y = 33;
	mlx->walls.imgsize_x = 32;
	mlx->walls.imgsize_y = 32;
	mlx->win_ptr = NULL;
	mlx->count[0] = 0;
	mlx->count[1] = 0;
	ft_setplayerimg(mlx);
	ft_setwall_left_right(mlx);
	ft_setfloor(mlx);
	ft_setwall_top_bot(mlx);
	ft_setmap(mlx);
	setmapchar(mlx);
	ft_checkplayerxpm(mlx);
	ft_checkwallsxpm(mlx, 0);
	ft_checkgroundxpm(mlx, 0);
	mlx->player.facing = 0;
	if (ft_checkmap(mlx) == -1)
	{
		freedata(mlx);
		exit(0);
	}
	if (checkwin(mlx) == -1)
		exit(0);
	getplayerpos(mlx);
}

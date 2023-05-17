/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:07:23 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/17 16:46:10 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setdata(t_mlx *mlx);

int	ft_arraylen(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	handleloop(t_mlx *mlx)
{
	static int			i = 0;
	static unsigned int	u[2] = {1, 0};
	int					save;

	save = u[0];
	if (i % 500 == 0)
	{
		if (u[0] == 0)
			u[0]++;
		else if (u[0] == 2)
			u[0]--;
		else if (u[0] > u[1])
			u[0]++;
		else
			u[0]--;
		u[1] = save;
	}
	i++;
	ft_display_walls(mlx, 0, 0);
	ft_display_ground(mlx);
	ft_display_danger(mlx, i);
	ft_display_player(mlx, u[0]);
	return (0);
}

void	ft_setmove(int key, t_mlx *mlx)
{
	if (key == 'w')
	{
		mlx->player.pos_y -= 32;
		mlx->player.facing = 3;
	}
	if (key == 'a')
	{
		mlx->player.pos_x -= 32;
		mlx->player.facing = 1;
	}
	if (key == 's')
	{
		mlx->player.pos_y += 32;
		mlx->player.facing = 0;
	}
	if (key == 'd')
	{
		mlx->player.pos_x += 32;
		mlx->player.facing = 2;
	}
}

int	handlekey(int key, t_mlx *mlx)
{
	if (key == 65307)
	{
		mlx_loop_end(mlx->mlx_ptr);
		return (0);
	}
	ft_setmove(key, mlx);
	if (iswall(mlx->map[mlx->player.pos_y / 32][mlx->player.pos_x / 32]) == -1)
		ft_goback(mlx);
	else if (iskey(key) == 1 || (key == 32
			&& mlx->map[mlx->player.pos_y / 32][mlx->player.pos_x / 32] == 'v'))
	{
		mlx->count[1] = mlx->count[0];
		mlx->count[0]++;
	}
	handledanger(mlx);
	if (key == 32)
		handlevent(mlx);
	if (isexit(mlx,
			mlx->map[mlx->player.pos_y / 32][mlx->player.pos_x / 32]) == -1)
		mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		ft_printf("format: ./so_long <file.ber>\n");
		exit(0);
	}
	mlx.mapfile = ft_strdup(av[1]);
	mlx.mlx_ptr = mlx_init();
	setdata(&mlx);
	if (ft_strlen(mlx.map[0]) * 32 > 1920 || ft_arraylen(mlx.map) * 32 > 1080)
	{
		ft_printf("map too big (for this screen)\n");
		freedata(&mlx);
		exit(0);
	}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
			ft_strlen(mlx.map[0]) * 32, ft_arraylen(mlx.map) * 32, "so_long");
	mlx_key_hook(mlx.win_ptr, handlekey, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, ft_close, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, handleloop, &mlx);
	mlx_loop(mlx.mlx_ptr);
	freedata(&mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handledanger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:52:09 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/17 17:28:51 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handlevent(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (mlx->map[mlx->player.pos_y / 32][mlx->player.pos_x / 32] != 'v')
		return ;
	while (mlx->map[j])
	{
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == 'v'
				&& (j != mlx->player.pos_y / 32 || i != mlx->player.pos_x / 32))
			{
				mlx->player.pos_x = i * 32;
				mlx->player.pos_y = j * 32;
				return ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	handledanger(t_mlx *mlx)
{
	if (mlx->map[mlx->player.pos_y / 32][mlx->player.pos_x / 32] == 'C')
		mlx->map[mlx->player.pos_y / 32][mlx->player.pos_x / 32] = 's';
}

int	ft_close(t_mlx *mlx)
{
	ft_printf("closed \n");
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	iskey(int key)
{
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
		return (1);
	return (-1);
}

int	endber(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 4)
		return (-1);
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
		return (1);
	return (-1);
}

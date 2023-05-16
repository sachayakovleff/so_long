/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklocation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:59:39 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/16 14:38:37 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_goback(t_mlx *mlx)
{
	if (mlx->player.facing == 0)
		mlx->player.pos_y -= 32;
	if (mlx->player.facing == 1)
		mlx->player.pos_x += 32;
	if (mlx->player.facing == 2)
		mlx->player.pos_x -= 32;
	if (mlx->player.facing == 3)
		mlx->player.pos_y += 32;
}

int	isexit(t_mlx *mlx, char c)
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
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	if (c == 'e')
		return (-1);
	return (1);
}

int	iswall(char c)
{
	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6'
		|| c == '7' || c == '8' || c == '9' || c == 'x')
	{
		return (-1);
	}
	else
		return (0);
}

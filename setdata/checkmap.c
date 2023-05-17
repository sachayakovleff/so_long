/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:53:28 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/17 17:14:30 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	walllist(char c)
{
	if (c == '1')
		return (1);
	return (-1);
}

int	wallline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (walllist(line[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	checkwallrect(t_mlx *mlx)
{
	int			i;
	const int	k = ft_strlen(mlx->map[0]) - 1;

	i = 0;
	while (mlx->map[i])
	{
		if (i == 0 && wallline(mlx->map[i]) == -1)
			return (-1);
		if (walllist(mlx->map[i][0]) == -1 || walllist(mlx->map[i][k]) == -1)
			return (-1);
		i++;
	}
	return (wallline(mlx->map[i - 1]));
}

int	checklinesize(t_mlx *mlx)
{
	int	i;
	int	count;

	count = ft_strlen(mlx->map[0]);
	i = 0;
	while (ft_strlen(mlx->map[i]) == count)
		i++;
	if (mlx->map[i] != NULL)
	{
		ft_printf("Error: Invalid map (not rect)\n");
		return (-1);
	}
	if (checkvent(mlx) == -1)
	{
		ft_printf("Error: Invalid vent number. Must be 0 or 2\n");
		return (-1);
	}
	return (1);
}

int	ft_checkmap(t_mlx *mlx)
{
	if (mlx->map == NULL)
	{
		ft_printf("Error: Can't open the map // ");
		ft_printf("Newline inside the map (not rect) // ");
		ft_printf("Consecutive newlines in %s \n", mlx->mapfile);
		return (-1);
	}
	if (checkchar(mlx) == -1)
		return (-1);
	if (checklinesize(mlx) == -1)
		return (-1);
	if (checkwallrect(mlx) == -1)
	{
		ft_printf("Error: Map must be encircled by walls/corner\n");
		return (-1);
	}
	if (checkplayer(mlx, 'P') == -1 || checkplayer(mlx, 'E') == -1)
	{
		ft_printf("Error: Invalid number of players/exit (1 player 1 exit)\n");
		return (-1);
	}
	return (1);
}

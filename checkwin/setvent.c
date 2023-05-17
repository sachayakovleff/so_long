/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:07:55 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/17 18:05:32 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	setvent(char **map, int i, int j)
{
	if (map[j][i - 1] == 'x' || map[j][i + 1] == 'x'
		|| map[j + 1][i] == 'x' || map[j - 1][i] == 'x')
	{
		i = 0;
		j = 0;
		while (map[j])
		{
			while (map[j][i])
			{
				if (map[j][i] == 'v')
					map[j][i] = 'x';
				i++;
			}
			i = 0;
			j++;
		}
		return (1);
	}
	return (0);
}

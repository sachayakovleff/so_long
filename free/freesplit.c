/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:31:22 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/08 17:39:09 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_destroy_image(void *mlx_ptr, void *img)
{
	if (img != NULL)
		mlx_destroy_image(mlx_ptr, img);
}

void	freesplit(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

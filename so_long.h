/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:07 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/17 16:47:22 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_player
{
	void	*playerimg[4][3];
	int		imgsize_x;
	int		imgsize_y;
	int		pos_y;
	int		pos_x;
	int		facing;
}				t_player;

typedef struct s_walls
{
	void	*groundimg[5];
	void	*walls_right[1];
	void	*walls_top[1];
	void	*walls_left[1];
	void	*walls_bot[1];
	void	*corner[4];
	int		imgsize_x;
	int		imgsize_y;
}				t_walls;

typedef struct s_map
{
	char	wallstop;
	char	wallsbot;
	char	wallsleft;
	char	wallsright;
	char	player;
	char	cornertopright;
	char	cornertopleft;
	char	cornerbotright;
	char	cornerbotleft;
	char	ground;
	char	vent;
	char	exit;
	char	key;
}				t_map;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		*mapfile;
	int			count[2];
	t_player	player;
	t_walls		walls;
	t_map		content;
}				t_mlx;

void	setmapchar(t_mlx *mlx);
void	setdata(t_mlx *mlx);
void	ft_setmap(t_mlx *mlx);
void	freedata(t_mlx *mlx);
void	freesplit(char **array);
int		ft_checkmap(t_mlx *mlx);
void	ft_display_walls(t_mlx *mlx, int i, int j);
void	ft_display_ground(t_mlx *mlx);
void	ft_display_danger(t_mlx *mlx, int u);
void	ft_display_player(t_mlx *mlx, int u);
void	getplayerpos(t_mlx *mlx);
int		isexit(t_mlx *mlx, char c);
int		iswall(char c);
void	ft_goback(t_mlx *mlx);
int		checkplayer(t_mlx *mlx, char c);
void	handledanger(t_mlx *mlx);
int		ft_validchar(char c);
int		checkchar(t_mlx *mlx);
int		checkvent(t_mlx *mlx);
void	handlevent(t_mlx *mlx);
void	ft_checkplayerxpm(t_mlx *mlx);
void	ft_checkwallsxpm(t_mlx *mlx, int i);
void	ft_checkgroundxpm(t_mlx *mlx, int i);
int		checkwin(t_mlx *mlx);
int		ft_arraylen(char	**str);
int		setvent(char **map);
int		ft_close(t_mlx *mlx);
int		iskey(int key);

#endif
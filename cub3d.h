/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:17:11 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/18 17:48:09 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define NUM_TEXTURES 4

typedef struct s_color {
	int	r;
	int	b;
	int	g;
}	t_color;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_texture {
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_keys {
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_cub3d {
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			win_width;
	int			win_height;
	t_player	player;
	t_texture	textures[NUM_TEXTURES];
	t_color		floor_color;
	t_color		ceiling_color;
	char		**map;
	int			map_width;
	int			map_height;
	t_keys		keys;
}	t_cub3d;

// INIT
void	init_game(t_cub3d *game);
void	init_player(t_cub3d *game);

// PARSING
void	parse_file(t_cub3d *game, const char *filename);
void	parse_textures(t_cub3d *game, char *line);

// EVENTS
int		handle_keypress(int keycode, t_cub3d *game);
int		handle_exit(t_cub3d *game);
int		handle_keyrelease(int keycode, t_cub3d *game);

// UTILS
void	error_exit(const char *msg);

// GNL
char	*recurs(int depth, int *ret, int fd);
int		get_next_line(int fd, char **line);

// LIBFT
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

#endif
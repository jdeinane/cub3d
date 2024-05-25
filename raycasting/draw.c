/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:20:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/25 21:07:32 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (2);
		else
			return (3);
	}
}

void	init_draw_params(t_draw_params *params, t_cub3d *game, \
							t_ray *ray, int line_height)
{
	double	wall_x;

	params->draw_start = get_draw_start(line_height, game->win_height);
	params->draw_end = get_draw_end(line_height, game->win_height);
	wall_x = get_wall_x(ray, &game->player);
	params->texture_x = get_texture_x(ray, wall_x);
	params->step = 1.0 * TEX_HEIGHT / line_height;
	params->texture_pos = (params->draw_start - game->win_height / 2 + \
							line_height / 2) * params->step;
}

void	draw_text_line(t_cub3d *game, int x, t_ray *ray, t_draw_params *params)
{
	int	y;
	int	texture_y;
	int	texture_index;
	int	color;

	y = params->draw_start;
	texture_index = get_texture_index(ray);
	while (y < params->draw_end)
	{
		texture_y = (int)params->texture_pos & (TEX_HEIGHT - 1);
		params->texture_pos += params->step;
		color = game->textures[texture_index].data[texture_y * \
					TEX_WIDTH + params->texture_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		game->img_data[y * game->win_width + x] = color;
		y++;
	}
}

void	draw_line(t_cub3d *game, int x, t_ray *ray)
{
	t_draw_params	params;
	int				line_height;

	line_height = get_line_height(ray, game->win_height);
	init_draw_params(&params, game, ray, line_height);
	draw_text_line(game, x, ray, &params);
}

void	draw_floor_and_ceiling(t_cub3d *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->win_height / 2)
	{
		x = -1;
		while (++x < game->win_width)
			game->img_data[y * game->win_width + x] = \
			(game->ceiling_color.r << 16) | (game->ceiling_color.g << 8) \
				| game->ceiling_color.b;
	}
	y = game->win_height / 2 - 1;
	while (++y < game->win_height)
	{
		x = -1;
		while (++x < game->win_width)
			game->img_data[y * game->win_width + x] = \
			(game->floor_color.r << 16) | (game->floor_color.g << 8) \
				| game->floor_color.b;
	}
}

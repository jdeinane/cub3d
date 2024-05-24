/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:56:07 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/24 22:17:47 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_cub3d *game, double move_speed)
{
	if (game->map[(int)(game->player.pos_y)][(int)(game->player.pos_x + \
			game->player.dir_x * move_speed)] == '0' &&
		game->map[(int)(game->player.pos_y + game->player.dir_y * move_speed)] \
			[(int)(game->player.pos_x)] == '0')
	{
		game->player.pos_x += game->player.dir_x * move_speed;
		game->player.pos_y += game->player.dir_y * move_speed;
	}
}

void	move_backward(t_cub3d *game, double move_speed)
{
	if (game->map[(int)(game->player.pos_y)][(int)(game->player.pos_x - \
			game->player.dir_x * move_speed)] == '0' &&
		game->map[(int)(game->player.pos_y - game->player.dir_y * move_speed)] \
			[(int)(game->player.pos_x)] == '0')
	{
		game->player.pos_x -= game->player.dir_x * move_speed;
		game->player.pos_y -= game->player.dir_y * move_speed;
	}
}

void	move_left(t_cub3d *game, double move_speed)
{
	double	move_x;
	double	move_y;

	move_x = game->player.dir_y * move_speed;
	move_y = -game->player.dir_x * move_speed;
	if (game->map[(int)(game->player.pos_y)] \
			[(int)(game->player.pos_x + move_x)] == '0' &&
		game->map[(int)(game->player.pos_y + move_y)] \
			[(int)(game->player.pos_x)] == '0')
	{
		game->player.pos_x += move_x;
		game->player.pos_y += move_y;
	}
}

void	move_right(t_cub3d *game, double move_speed)
{
	double	move_x;
	double	move_y;

	move_x = -game->player.dir_y * move_speed;
	move_y = game->player.dir_x * move_speed;
	if (game->map[(int)(game->player.pos_y)] \
			[(int)(game->player.pos_x + move_x)] == '0' &&
		game->map[(int)(game->player.pos_y + move_y)] \
			[(int)(game->player.pos_x)] == '0')
	{
		game->player.pos_x += move_x;
		game->player.pos_y += move_y;
	}
}

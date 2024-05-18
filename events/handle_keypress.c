/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:57:42 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/18 17:15:00 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_keypress(int keycode, t_cub3d *game)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 'w')
		game->keys.w = true;
	if (keycode == 'a')
		game->keys.a = true;
	if (keycode == 's')
		game->keys.s = true;
	if (keycode == 'd')
		game->keys.d = true;
	if (keycode == 65361)
		game->keys.left = true;
	if (keycode == 65363)
		game->keys.right = true;
	return (0);
}

int	handle_exit(t_cub3d *game)
{
	exit(0);
	return (0);
}

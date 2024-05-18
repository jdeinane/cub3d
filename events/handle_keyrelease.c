/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:12:07 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/18 17:14:33 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_keyrelease(int keycode, t_cub3d *game)
{
	if (keycode == 'w')
		game->keys.w = false;
	if (keycode == 'a')
		game->keys.a = false;
	if (keycode == 's')
		game->keys.s = false;
	if (keycode == 'd')
		game->keys.d = false;
	if (keycode == 65361)
		game->keys.left = false;
	if (keycode == 65363)
		game->keys.right = false;
	return (0);
}

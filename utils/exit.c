/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:11:51 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/25 22:20:35 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_exit(t_cub3d *game, const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	if (game)
		free_resources(game);
	exit(EXIT_FAILURE);
}

void	clean_exit(t_cub3d *game)
{
	free_resources(game);
	write(1, "Existing program\n", 16);
	exit(0);
}

int	handle_exit(t_cub3d *game)
{
	clean_exit(game);
	return (0);
}

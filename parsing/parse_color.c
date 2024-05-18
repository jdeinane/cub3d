/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:01:11 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/18 18:04:35 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	parse_color(t_color *color, char *line)
{
	char	**tokens;
	int		i;

	tokens = ft_split(line + 2, ',');
	if (!tokens[0] || !tokens[1] || !tokens[2])
	{
		free_tokens(tokens);
		error_exit("Invalid color format");
	}
	color->r = ft_atoi(tokens[0]);
	color->b = ft_atoi(tokens[1]);
	color->g = ft_atoi(tokens[2]);
	free_tokens(tokens);
}

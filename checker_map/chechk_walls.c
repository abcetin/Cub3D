/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechk_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:47:26 by acetin            #+#    #+#             */
/*   Updated: 2022/12/20 11:27:37 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	check_arg(char *map)
{
	char	*set;
	int		i;

	i = 0;
	set = " \t10NSEW";
	while (map[i])
	{
		if (!ft_strchr(set, map[i]))
			error_message("Invalid Argument");
		i++;
	}
}

void	check_y_column(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strtrim(str, " \t\r");
	if (!ft_strlen(temp))
		error_message("Error In Map Boundaries ");
	while (temp[i])
	{
		if (temp[i] != '1' && !white_space(temp[i]))
			error_message("Error In Map Boundaries ");
		i++;
	}
	free(temp);
}

int	white_space(char c)
{
	if ((c >= 9 && c <= 12) || c == 32)
		return (1);
	return (0);
}

void	check_x_cloumn(char *top_side, char *s2, char *bottom_side)
{
	int		i;

	i = 0;
	while (white_space(s2[i]))
		i++;
	while (s2[i])
	{
		if ((i == 0 && s2[i] == '0') || (s2[i + 1] == '\0' && s2[i] == '0'))
			error_message("Error In Map Boundaries ");
		if (s2[i] == '0' && (white_space(top_side[i])
				|| white_space(bottom_side[i])))
			error_message("Error In Map Boundaries ");
		if (s2[i] == '0' && ((i + 1 > ft_strlen(top_side)
					|| i + 1 > ft_strlen(bottom_side))
				|| (white_space(s2[i - 1])
					|| white_space(s2[i + 1]))))
			error_message("Error In Map Boundaries ");
		i++;
	}
}

void	check_walls(t_game ptr)
{
	int	y;
	int	player_count;

	y = -1;
	player_count = 0;
	while (ptr.map_.map_world[++y])
	{
		check_arg(ptr.map_.map_world[y]);
		player_count += char_count(ptr.map_.map_world[y], "NSEW");
		if (y == 0 || y == ptr.map_.height - 1)
			check_y_column(ptr.map_.map_world[y]);
		if (y != 0 && y != ptr.map_.height - 1)
			check_x_cloumn(ptr.map_.map_world[y - 1],
				ptr.map_.map_world[y], ptr.map_.map_world[y + 1]);
	}
}

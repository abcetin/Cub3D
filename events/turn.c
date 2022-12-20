/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:34:38 by acetin            #+#    #+#             */
/*   Updated: 2022/12/20 11:05:01 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	turn_left(t_game *ptr, int angle)
{
	ptr->player_.angle += angle;
	ptr->player_.delta_.x = cos(to_radians(fix_angle(ptr->player_.angle)));
	ptr->player_.delta_.y = -sin(to_radians(fix_angle(ptr->player_.angle)));
}

void	turn_right(t_game *ptr, int angle)
{
	ptr->player_.angle -= angle;
	ptr->player_.delta_.x = cos(to_radians(fix_angle(ptr->player_.angle)));
	ptr->player_.delta_.y = -sin(to_radians(fix_angle(ptr->player_.angle)));
}

int	collision(t_game ptr, int x, int y)
{
	int	condition1;
	int	condition2;
	int	condition3;
	int	condition4;

	condition1 = ptr.map_.map_world[y / CELL_SIZE]
	[x / CELL_SIZE] != '1';
	condition2 = ptr.map_.map_world[y / CELL_SIZE]
	[(x + PLAYER_SIZE) / CELL_SIZE] != '1';
	condition3 = ptr.map_.map_world[(y + PLAYER_SIZE) / CELL_SIZE]
	[x / CELL_SIZE] != '1';
	condition4 = ptr.map_.map_world[(y + PLAYER_SIZE) / CELL_SIZE]
	[(x + PLAYER_SIZE) / CELL_SIZE] != '1';
	if (condition1 && condition2 && condition3 && condition4)
		return (1);
	return (0);
}

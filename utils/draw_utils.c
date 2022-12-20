/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:52:56 by acetin            #+#    #+#             */
/*   Updated: 2022/12/13 11:52:56 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	sign(float x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	return (0);
}

void	line_bres(t_game ptr, t_int_coordinate pos1, t_int_coordinate pos2)
{
	int	delta_x;
	int	delta_y;
	int	pk;

	delta_x = abs(pos2.x - pos1.x);
	delta_y = -abs(pos2.y - pos1.y);
	pk = delta_x + delta_y;
	while (pos1.x != pos2.x || pos1.y != pos2.y)
	{
		img_pixel_put(&ptr.scene, pos1.x, pos1.y, 0x00ff00);
		if (2 * pk >= delta_y)
		{
			if (pos1.x == pos2.x || pos1.x >= 256)
				break ;
			pk += delta_y;
			pos1.x += sign(pos2.x - pos1.x);
		}
		if (2 * pk <= delta_x)
		{
			if (pos1.y == pos2.y || pos1.y >= 256)
				break ;
			pk += delta_x;
			pos1.y += sign(pos2.y - pos1.y);
		}
	}
}

void	draw_scene(t_game *ptr, t_coordinate pos, int y2, int color)
{
	while (pos.y < y2)
	{
		img_pixel_put(&ptr->scene, pos.x, pos.y, color);
		pos.y++;
	}
}

int	find_wall_direction(t_game ptr, t_coordinate ray_)
{
	if (!(lround(ray_.y) % CELL_SIZE))
	{
		if (ray_.y > (ptr.player_.coordinate_.y + 5))
			return (0);
		else
			return (1);
	}
	else if (!(lround(ray_.x) % CELL_SIZE))
	{
		if (ray_.x > (ptr.player_.coordinate_.x + 5))
			return (2);
		else
			return (3);
	}	
	return (-1);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

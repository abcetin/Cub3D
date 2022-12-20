/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:38:37 by acetin            #+#    #+#             */
/*   Updated: 2022/12/13 13:38:37 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_texture(t_game *ptr, t_coordinate pos, int x, t_image img)
{
	float			y_increment;
	t_coordinate	scene;
	int				i;

	y_increment = (pos.y * 2) / CELL_SIZE;
	scene.y = (SCREEN_HEIGHT / 2) - pos.y;
	scene.x = pos.x;
	i = 0;
	while (i < CELL_SIZE)
	{
		draw_scene(ptr, scene, scene.y + (y_increment),
			get_color(x, i, img));
		scene.y += y_increment;
		i++;
	}
}

void	draw_floor(t_game *ptr)
{
	int				i;
	t_coordinate	scene;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		scene.x = i;
		scene.y = (SCREEN_HEIGHT / 2) + ptr->ray[i]->wall_h;
		draw_scene(ptr, scene, SCREEN_HEIGHT, ptr->map_.color_floor);
	}
}

void	draw_sky(t_game *ptr)
{
	int				i;
	t_coordinate	scene;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		scene.x = i;
		scene.y = 0;
		draw_scene(ptr, scene, (SCREEN_HEIGHT / 2)
			- ptr->ray[i]->wall_h, ptr->map_.color_sky);
	}
}

void	draw_wall(t_game *ptr)
{
	int				i;
	t_coordinate	pos;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		pos.x = i;
		pos.y = ptr->ray[i]->wall_h;
		draw_texture(ptr, pos, (ptr->ray[i]->coord.x + ptr->ray[i]->coord.y),
			*(ptr->img[find_wall_direction(*ptr, ptr->ray[i]->coord)]));
	}
}

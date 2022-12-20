/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:39:01 by acetin            #+#    #+#             */
/*   Updated: 2022/12/13 13:39:01 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	draw_map_conditions(t_game ptr, t_coordinate temp, int x, int y)
{
	if (temp.x < ptr.map_.widht * CELL_SIZE
		&& temp.y < ptr.map_.height * CELL_SIZE
		&& ptr.map_.map_world[(int)temp.y / CELL_SIZE]
		[(int)temp.x / CELL_SIZE] == '1')
		img_pixel_put(&ptr.scene, x, y, get_color(temp.x, temp.y, *ptr.img[0]));
	if (temp.x < ptr.map_.widht * CELL_SIZE
		&& (temp.y < ptr.map_.height * CELL_SIZE && !((int)temp.y % CELL_SIZE)))
		img_pixel_put(&ptr.scene, x, y, 0xffffff);
	if (temp.y < ptr.map_.height * CELL_SIZE
		&& (temp.x < ptr.map_.widht * CELL_SIZE && !((int)temp.x % CELL_SIZE)))
		img_pixel_put(&ptr.scene, x, y, 0xffffff);
}

void	draw_map(t_game ptr)
{
	int				y;
	int				x;
	t_coordinate	temp;

	y = -1;
	temp.x = 0;
	temp.y = 0;
	if (ptr.player_.coordinate_.y > 128)
		temp.y = ptr.player_.coordinate_.y - 128;
	while (++y < CELL_SIZE * 8)
	{
		x = -1;
		if (ptr.player_.coordinate_.x > 128)
			temp.x = ptr.player_.coordinate_.x - 128;
		else
			temp.x = 0;
		while (++x < CELL_SIZE * 8)
		{
			draw_map_conditions(ptr, temp, x, y);
			temp.x++;
		}
		temp.y += 1;
	}
}

void	mini_ray(t_game ptr, t_coordinate mini)
{
	int					count;
	t_int_coordinate	player_coord;
	t_int_coordinate	ray_coord;

	count = 0;
	player_coord.x = mini.x + 5;
	player_coord.y = mini.y + 5;
	while (count < SCREEN_WIDTH)
	{
		if (ptr.player_.coordinate_.y > 128)
			ptr.ray[count]->coord.y -= fabs(ptr.player_.coordinate_.y - mini.y);
		if (ptr.player_.coordinate_.x > 128)
			ptr.ray[count]->coord.x -= fabs(ptr.player_.coordinate_.x - mini.x);
		ray_coord.x = ptr.ray[count]->coord.x;
		ray_coord.y = ptr.ray[count]->coord.y;
		line_bres(ptr, player_coord, ray_coord);
		count++;
	}
}

void	draw_player(t_game ptr)
{
	t_coordinate	temp;

	temp.x = ptr.player_.coordinate_.x;
	temp.y = ptr.player_.coordinate_.y;
	if (temp.x > 128)
		temp.x -= (temp.x - 128);
	if (temp.y > 128)
		temp.y -= (temp.y - 128);
	point_size(ptr, temp.x, temp.y, 0);
	mini_ray(ptr, temp);
}

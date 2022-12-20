/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:46:59 by acetin            #+#    #+#             */
/*   Updated: 2022/12/13 13:46:59 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_coordinate	s_delta(t_coordinate pos, float ang)
{
	t_coordinate		delta;
	t_int_coordinate	sign_;

	sign_.x = sign(cos(to_radians(ang)));
	sign_.y = sign(-sin(to_radians(ang)));
	if (sign_.x < 0)
	{
		delta.x = -fmod(pos.x, CELL_SIZE);
		if (delta.x == 0)
			delta.x = -32;
	}
	if (sign_.y < 0)
	{
		delta.y = -fmod(pos.y, CELL_SIZE);
		if (delta.y == 0)
			delta.y = -32;
	}
	if (sign_.x > 0)
		delta.x = (CELL_SIZE - fmod(pos.x, CELL_SIZE));
	if (sign_.y > 0)
		delta.y = (CELL_SIZE - fmod(pos.y, CELL_SIZE));
	return (delta);
}

int	check_map(char **map, t_rays ray)
{
	float				x;
	float				y;
	t_int_coordinate	sign_;

	sign_.x = sign(cos(to_radians(ray.angle)));
	sign_.y = sign(-sin(to_radians(ray.angle)));
	x = (ray.coord.x / CELL_SIZE);
	y = (ray.coord.y / CELL_SIZE);
	if (sign_.x < 0)
		x -= 0.001;
	if (sign_.y < 0)
		y -= 0.001;
	if (map[(int)y][(int)x] == '1' || x >= ft_strlen(map[(int)y]))
		return (1);
	return (0);
}

void	ray_collision(t_game ptr, t_rays *ray)
{
	t_coordinate		delta;
	t_coordinate		trig;

	trig.x = cos(to_radians(ray->angle));
	trig.y = -sin(to_radians(ray->angle));
	while (!check_map(ptr.map_.map_world, *ray))
	{
		delta = s_delta(ray->coord, ray->angle);
		if ((((delta.x) / trig.x) < (delta.y / trig.y)) || sign(trig.y) == 0)
		{
			ray->coord.x += delta.x;
			ray->coord.y += (-tan(to_radians(ray->angle))) * delta.x;
		}
		else
		{
			ray->coord.x += delta.y / (-tan(to_radians(ray->angle)));
			ray->coord.y += delta.y;
		}
	}
}

int	ray(t_game *ptr)
{
	int		count;
	float	angle;

	count = 0;
	ptr->ray = malloc(sizeof(t_rays *) * SCREEN_WIDTH);
	angle = ptr->player_.angle + 30;
	while (count < SCREEN_WIDTH)
	{
		ptr->ray[count] = malloc(sizeof(t_rays));
		ptr->ray[count]->angle = angle;
		ptr->ray[count]->coord.x = ptr->player_.coordinate_.x + 5;
		ptr->ray[count]->coord.y = ptr->player_.coordinate_.y + 5;
		ray_collision(*ptr, ptr->ray[count]);
		ptr->ray[count]->distance_ = (distance(*ptr, *ptr->ray[count])) * 1.81;
		ptr->ray[count]->wall_h = (CELL_SIZE * (1 << 9))
			/ ptr->ray[count]->distance_;
		angle -= ptr->angle_ray;
		count++;
	}
	ptr->ray[count] = NULL;
	return (0);
}

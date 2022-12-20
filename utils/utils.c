/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:15:35 by acetin            #+#    #+#             */
/*   Updated: 2022/12/13 13:15:35 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

float	distance(t_game ptr, t_rays ray)
{
	float			ret;
	t_coordinate	delta;
	t_coordinate	diff;

	delta.x = (cos(to_radians((ptr.player_.angle))));
	delta.y = (-sin(to_radians((ptr.player_.angle))));
	diff.x = (ray.coord.x - (ptr.player_.coordinate_.x + 5));
	diff.y = (ray.coord.y - (ptr.player_.coordinate_.y + 5));
	ret = fabs((delta.x * diff.x) + (delta.y * diff.y));
	if (ret < 1)
		ret += 0.8;
	return (ret);
}

void	point_size(t_game ptr, int x, int y, int color)
{
	int	sizex;
	int	sizey;
	int	temp;

	sizey = 0;
	temp = x;
	while (sizey < PLAYER_SIZE)
	{
		sizex = 0;
		x = temp;
		while (sizex < PLAYER_SIZE)
		{
			img_pixel_put(&ptr.scene, x++, y, color);
			sizex++;
		}
		sizey++;
		y++;
	}
}

float	fix_angle(float ang)
{
	if (ang == 360)
		return (0);
	else if (ang > 360)
		return (ang - 360);
	else if (ang < 0)
		return (360 + fmod(ang, 360));
	return (ang);
}

double	to_radians(double deg)
{
	double	ret;

	ret = (deg * M_PI) / 180;
	return (ret);
}

void	error_message(char *message)
{
	printf("\033[0;31m%s\n", message);
	exit(1);
}

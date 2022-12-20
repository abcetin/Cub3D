/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:34:35 by acetin            #+#    #+#             */
/*   Updated: 2022/12/15 14:36:28 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	move_up(t_game *ptr)
{
	float	x;
	float	y;

	x = ptr->player_.delta_.x * 3;
	y = ptr->player_.delta_.y * 3;
	if (collision(*ptr, ptr->player_.coordinate_.x + x,
			ptr->player_.coordinate_.y))
		ptr->player_.coordinate_.x += x;
	if (collision(*ptr, ptr->player_.coordinate_.x,
			ptr->player_.coordinate_.y + y))
		ptr->player_.coordinate_.y += y;
}

void	move_down(t_game *ptr)
{
	float	x;
	float	y;

	x = ptr->player_.delta_.x * 3;
	y = ptr->player_.delta_.y * 3;
	if (collision(*ptr, ptr->player_.coordinate_.x - x,
			ptr->player_.coordinate_.y))
		ptr->player_.coordinate_.x -= x;
	if (collision(*ptr, ptr->player_.coordinate_.x,
			ptr->player_.coordinate_.y - y))
		ptr->player_.coordinate_.y -= y;
}

void	move_left(t_game *ptr)
{
	float	x;
	float	y;

	x = cos(to_radians(ptr->player_.angle - 90)) * 3;
	y = -sin(to_radians(ptr->player_.angle - 90)) * 3;
	if (collision(*ptr, ptr->player_.coordinate_.x - x,
			ptr->player_.coordinate_.y))
		ptr->player_.coordinate_.x -= x;
	if (collision(*ptr, ptr->player_.coordinate_.x,
			ptr->player_.coordinate_.y - y))
		ptr->player_.coordinate_.y -= y;
}

void	move_right(t_game *ptr)
{
	float	x;
	float	y;

	x = cos(to_radians(ptr->player_.angle - 90)) * 3;
	y = -sin(to_radians(ptr->player_.angle - 90)) * 3;
	if (collision(*ptr, ptr->player_.coordinate_.x + x,
			ptr->player_.coordinate_.y))
		ptr->player_.coordinate_.x += x;
	if (collision(*ptr, ptr->player_.coordinate_.x,
			ptr->player_.coordinate_.y + y))
		ptr->player_.coordinate_.y += y;
}

void	mouse_hide_or_show(t_game *ptr)
{
	static int	i;

	if (i == 0)
	{
		mlx_mouse_hide(ptr->mlx, ptr->win);
		i = 1;
	}
	else
	{
		mlx_mouse_show(ptr->mlx, ptr->win);
		i = 0;
	}
}

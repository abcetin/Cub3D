/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:34:33 by acetin            #+#    #+#             */
/*   Updated: 2022/12/20 11:03:55 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	exit_screen(void)
{
	exit(0);
}

int	key_hook(int key, t_game *ptr)
{
	if (key == 53 || key == 65307)
		exit(0);
	if (key == 13 || key == 119)
		move_up(ptr);
	if (key == 1 || key == 115)
		move_down(ptr);
	if (key == 0 || key == 97)
		move_left(ptr);
	if (key == 2 || key == 100)
		move_right(ptr);
	if (key == 124 || key == 65363)
		turn_right(ptr, 5);
	if (key == 123 || key == 65361)
		turn_left(ptr, 5);
	if (key == 49)
		mouse_hide_or_show(ptr);
	game_life_cycle(ptr);
	return (0);
}

int	mouse_move(t_game *ptr)
{
	int	y;

	mlx_mouse_get_pos(ptr->win, &ptr->mouse.last_x, &y);
	mlx_hook(ptr->win, 2, 1L << 0, key_hook, ptr);
	if (ptr->mouse.first_x != ptr->mouse.last_x)
	{
		if (ptr->mouse.first_x > ptr->mouse.last_x)
			turn_left(ptr, 3);
		else
			turn_right(ptr, 3);
		ptr->mouse.first_x = ptr->mouse.last_x;
		if (ptr->mouse.last_x > SCREEN_WIDTH)
			mlx_mouse_move(ptr->win, 0, SCREEN_HEIGHT / 2);
		if (ptr->mouse.last_x < 0)
			mlx_mouse_move(ptr->win, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
	}
	game_life_cycle(ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:49:57 by acetin            #+#    #+#             */
/*   Updated: 2022/12/13 11:49:57 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_index(char *s1, char *set)
{
	int	i;
	int	j;

	i = -1;
	while (set[++i])
	{
		j = -1;
		while (s1[++j])
		{
			if (s1[j] == set[i])
				return (j);
		}
	}
	return (-1);
}

void	get_player_angle(t_game *ptr)
{
	if (ptr->map_.map_world[(int)ptr->player_.coordinate_.y / CELL_SIZE]
		[(int)ptr->player_.coordinate_.x / CELL_SIZE] == 'N')
		ptr->player_.angle = 90;
	if (ptr->map_.map_world[(int)ptr->player_.coordinate_.y / CELL_SIZE]
		[(int)ptr->player_.coordinate_.x / CELL_SIZE] == 'S')
		ptr->player_.angle = 270;
	if (ptr->map_.map_world[(int)ptr->player_.coordinate_.y / CELL_SIZE]
		[(int)ptr->player_.coordinate_.x / CELL_SIZE] == 'E')
		ptr->player_.angle = 0;
	if (ptr->map_.map_world[(int)ptr->player_.coordinate_.y / CELL_SIZE]
		[(int)ptr->player_.coordinate_.x / CELL_SIZE] == 'W')
		ptr->player_.angle = 180;
}

void	get_player_pos(t_game *ptr)
{
	ptr->player_.coordinate_.y = 0;
	ptr->player_.coordinate_.x = -1;
	while (ptr->map_.map_world[(int)ptr->player_.coordinate_.y])
	{
		ptr->player_.coordinate_.x = get_index(ptr->map_.map_world
			[(int)ptr->player_.coordinate_.y], "NWSE");
		if (ptr->player_.coordinate_.x > -1)
			break ;
		ptr->player_.coordinate_.y++;
	}
	if (ptr->player_.coordinate_.x < 0)
		error_message("Invalid Player Possition");
	ptr->player_.coordinate_.x *= CELL_SIZE;
	ptr->player_.coordinate_.y *= CELL_SIZE;
	get_player_angle(ptr);
}

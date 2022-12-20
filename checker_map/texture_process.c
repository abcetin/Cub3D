/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:35 by acetin            #+#    #+#             */
/*   Updated: 2022/12/20 12:08:10 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	detech_direction(char str)
{
	char	*dir;
	int		i;

	i = 0;
	dir = "NSWE";
	while (dir[i])
	{
		if (dir[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	is_exist_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_message("Texture Not Found");
	close(fd);
	return (1);
}

int	init_textures(t_game *ptr, char *str)
{
	int			dir;

	dir = detech_direction(str[0]);
	if (dir < 0)
		return (0);
	ptr->img[dir] = malloc(sizeof(t_image));
	is_exist_file(&str[3]);
	if (!ptr->img[dir] || !check_folder(&str[3], ".xpm"))
		error_message("Error");
	ptr->img[dir]->ptr = mlx_xpm_file_to_image(ptr->mlx, &str[3],
			&ptr->img[dir]->width, &ptr->img[dir]->height);
	ptr->img[dir]->data = mlx_get_data_addr(ptr->img[dir]->ptr,
			&ptr->img[dir]->bpp, &ptr->img[dir]->size, &ptr->img[dir]->endian);
	return (1);
}

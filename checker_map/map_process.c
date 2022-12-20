/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:47:49 by acetin            #+#    #+#             */
/*   Updated: 2022/12/20 13:41:39 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	init_color(t_game *ptr, char *str)
{
	char	**temp;

	if (str[0] == 'F')
	{
		temp = ft_split(str, ',');
		ptr->map_.color_floor = create_rgb(ft_atoi(temp[0]),
				ft_atoi(temp[1]), ft_atoi(temp[2]));
		free_double((void **)temp);
		return (1);
	}
	if (str[0] == 'C')
	{
		temp = ft_split(str, ',');
		ptr->map_.color_sky = create_rgb(ft_atoi(temp[0]),
				ft_atoi(temp[1]), ft_atoi(temp[2]));
		free_double((void **)temp);
		return (1);
	}
	return (0);
}

char	*ft_replace(char *str, char c)
{
	int		len;
	char	*ret;
	int		i;
	int		j;
	int		k;

	len = ft_strlen(str);
	ret = malloc(sizeof(char) * (len + (char_count(str, "\t") * 4)));
	i = 0;
	k = -1;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = -1;
			while (++j < 4)
				ret[++k] = ' ';
			++i;
		}
		if (str[i] != c)
			ret[++k] = str[i++];
	}
	ret[++k] = '\0';
	return (ret);
}

int	max_width(char **map)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (map[i])
	{
		if (ret < ft_strlen(map[i]))
			ret = ft_strlen(map[i]);
		i++;
	}
	return (ret);
}

void	init_map(t_game *ptr, int fd)
{
	char	*str;
	char	*temp;
	int		i;

	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		temp = ft_strtrim(str, "\r\n");
		if (is_print_str(*ptr, temp)
			&& !init_color(ptr, temp) && !init_textures(ptr, temp))
		{
			ptr->map_.map_world = ft_realloc(ptr->map_.map_world,
					(sizeof(char *) * (i + 2)));
			ptr->map_.map_world[i] = ft_replace(temp, '\t');
			ptr->map_.map_world[i + 1] = NULL;
			i++;
		}
		free(temp);
		free(str);
		str = get_next_line(fd);
	}
	ptr->map_.height = i;
	ptr->map_.widht = max_width(ptr->map_.map_world);
}

void	init_cub_folder(t_game *ptr, char *file_name)
{
	int	fd;
	int	i;

	if (!check_folder(file_name, ".cub"))
		error_message("Map Name Error");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_message("Map Error");
	ptr->map_.color_floor = -1;
	ptr->map_.color_sky = -1;
	init_map(ptr, fd);
	check_walls(*ptr);
	close(fd);
	if (ptr->map_.color_floor == -1 || ptr->map_.color_sky == -1)
		error_message("Color Value Error");
	i = 0;
	while (i < 4)
	{
		if (ptr->img[i] == NULL)
			error_message("Texture Error");
		i++;
	}
}

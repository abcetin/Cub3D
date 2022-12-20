/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:28:39 by acetin            #+#    #+#             */
/*   Updated: 2022/12/20 13:06:04 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	char_count(char *str, char *set)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (str[++i])
	{	
		if (ft_strchr(set, str[i]))
			ret++;
	}
	return (ret);
}

int	check_folder(char *file_name, char *extension)
{
	char	*temp;

	temp = ft_strnstr(file_name, extension, ft_strlen(file_name));
	if (temp && ft_strlen(temp) == 4)
		return (1);
	return (0);
}

int	is_print_str(t_game ptr, char *str)
{
	int	i;

	i = -1;
	if (ptr.map_.map_world)
		return (1);
	while (str[++i])
	{
		if (str[i] > 32)
			return (1);
	}
	return (0);
}

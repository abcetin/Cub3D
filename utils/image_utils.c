/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:14:46 by acetin            #+#    #+#             */
/*   Updated: 2022/12/13 14:22:24 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_color(int x, int y, t_image img)
{
	char	*ret;

	ret = img.data + ((y % CELL_SIZE)
			* img.size + (x % CELL_SIZE) * img.bpp / 8);
	return (*(int *)ret);
}

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	if (y < SCREEN_HEIGHT && y > 0 && x < SCREEN_WIDTH && x > 0)
		*(int *)(img->data + (y * img->size + x * (img->bpp >> 3))) = color;
}

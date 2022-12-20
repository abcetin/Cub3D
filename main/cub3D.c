/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:20:24 by acetin            #+#    #+#             */
/*   Updated: 2022/12/13 13:20:24 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_player(t_game *ptr)
{
	ptr->player_.speed = 5;
	get_player_pos(ptr);
	ptr->player_.delta_.x = cos(to_radians(ptr->player_.angle));
	ptr->player_.delta_.y = -sin(to_radians(ptr->player_.angle));
	ptr->angle_ray = (float)FOV / (float)SCREEN_WIDTH;
}

void	game_life_cycle(t_game *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->scene.ptr);
	mlx_clear_window(ptr->mlx, ptr->win);
	ptr->scene.ptr = mlx_new_image(ptr->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	ptr->scene.data = mlx_get_data_addr(ptr->scene.ptr, &ptr->scene.bpp,
			&ptr->scene.size, &ptr->scene.endian);
	if (ptr->ray[0])
		free_double((void **)ptr->ray);
	ray(ptr);
	draw_floor(ptr);
	draw_sky(ptr);
	draw_wall(ptr);
	draw_map(*ptr);
	draw_player(*ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->scene.ptr, 0, 0);
}

void	start(t_game *new_game, char *file)
{
	new_game->map_.map_world = NULL;
	new_game->img = ft_calloc(sizeof(t_image *), 4);
	init_cub_folder(new_game, file);
	init_player(new_game);
	new_game->mouse.first_x = 0;
	new_game->scene.ptr = mlx_new_image(new_game->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	new_game->scene.data = mlx_get_data_addr(new_game->scene.ptr,
			&new_game->scene.bpp, &new_game->scene.size,
			&new_game->scene.endian);
	new_game->map_.map_world[(int)new_game->player_.coordinate_.y / CELL_SIZE]
	[(int)new_game->player_.coordinate_.x / CELL_SIZE] = '0';
	ray(new_game);
	draw_floor(new_game);
	draw_sky(new_game);
	draw_wall(new_game);
	draw_map(*new_game);
	draw_player(*new_game);
}

int	main(int ac, char **av)
{
	t_game	new_game;

	if (ac != 2)
		error_message("Invalid Argument");
	new_game.mlx = mlx_init();
	start(&new_game, av[1]);
	new_game.win = mlx_new_window(new_game.mlx, 1080, 720, "CUB3D");
	mlx_put_image_to_window(new_game.mlx,
		new_game.win, new_game.scene.ptr, 0, 0);
	mlx_hook(new_game.win, 17, 0, exit_screen, NULL);
	mlx_hook(new_game.win, 2, 1L << 0, key_hook, &new_game);
	mlx_loop_hook(new_game.mlx, mouse_move, &new_game);
	mlx_loop(new_game.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_to_cube.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:51:37 by hbelle            #+#    #+#             */
/*   Updated: 2024/03/28 18:20:53 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "rendering.h"

static void	ft_keys_init(t_keys *keys);
static void	ft_init_cub_array(t_cub *cub, t_map *map);

/**
 * @brief Assigns the map data to the cub structure
 *
 * @param cub cub structure
 * @param map map structure
 * @return void
 */
void	ft_assign_to_cube(t_cub *cub, t_map *map)
{
	cub->map_array = ft_calloc(map->map_size_y, sizeof(t_tile *));
	if (!cub->map_array)
		ft_error_handle(map, "Error\n", "Can't allocate memory", 1);
	ft_init_cub_array(cub, map);
	cub->map_size.x = map->map_size_x;
	cub->map_size.y = map->map_size_y;
	cub->position.x = map->player_position[0] + 0.5;
	cub->position.y = map->player_position[1] + 0.5;
	cub->floor_c = (map->floor_c[0] << 16) + (map->floor_c[1] << 8)
		+ map->floor_c[2];
	cub->ceiling_c = (map->ceiling_c[0] << 16) + (map->ceiling_c[1] << 8)
		+ map->ceiling_c[2];
	if (map->player_direction[0] == 1)
		cub->orientation = 0;
	else if (map->player_direction[1] == 1)
		cub->orientation = PI_2;
	else if (map->player_direction[2] == 1)
		cub->orientation = PI;
	else if (map->player_direction[3] == 1)
		cub->orientation = 3 * PI_2;

	
	cub->frames = 0;
	ft_keys_init(&cub->keys);
	if (ft_mlx_init(cub))
	{
		// Precedents are not freed ==>> Memory leaks possible
		ft_game_quit(cub, 1);
		return ;
	}

	cub->minimap = BONUS;
	cub->info = FALSE;

	// cub->border_c = 0xFFCCCCCC;
	cub->border_c = 0;

	for (int i = 0; i < 128; i++)
	{
		cub->textures[i].empty = TRUE;
		cub->textures[i].no = NULL;
		cub->textures[i].no_anim_count = 0;
		cub->textures[i].no_anim_num = 0;
		cub->textures[i].no_anim = TRUE;
		cub->textures[i].so = NULL;
		cub->textures[i].so_anim_count = 0;
		cub->textures[i].so_anim_num = 0;
		cub->textures[i].so_anim = TRUE;
		cub->textures[i].we = NULL;
		cub->textures[i].we_anim_count = 0;
		cub->textures[i].we_anim_num = 0;
		cub->textures[i].we_anim = TRUE;
		cub->textures[i].ea = NULL;
		cub->textures[i].ea_anim_count = 0;
		cub->textures[i].ea_anim_num = 0;
		cub->textures[i].ea_anim = TRUE;
		cub->textures[i].anim_delay = 16;
		cub->textures[i].anim_counter = 0;
		cub->textures[i].map_color = 0x00000000;
	}

	cub->textures[(int) '1'].map_color = 0xFF000000;

	if (!BONUS)
		for (int i = 0; i < 128; i++)
		{
			cub->textures[i].no = ft_calloc(MAX_FRAME + 1, sizeof(t_frame));
			cub->textures[i].no_anim_count = 1;
			cub->textures[i].no[0] = ft_load_texture(cub, map->no);
			if (cub->textures[i].no[0].img == NULL)
			{
				// Precedents are not freed ==>> Memory leaks possible
				ft_error_handle(map, "Error\n", "Can't load texture", -42);
				ft_game_quit(cub, 1);
			}

			cub->textures[i].so = ft_calloc(MAX_FRAME + 1, sizeof(t_frame));
			cub->textures[i].so_anim_count = 1;
			cub->textures[i].so[0] = ft_load_texture(cub, map->so);
			if (cub->textures[i].so[0].img == NULL)
			{
				// Precedents are not freed ==>> Memory leaks possible
				ft_error_handle(map, "Error\n", "Can't load texture", -42);
				ft_game_quit(cub, 1);
			}
			
			cub->textures[i].we = ft_calloc(MAX_FRAME + 1, sizeof(t_frame));
			cub->textures[i].we_anim_count = 1;
			cub->textures[i].we[0] = ft_load_texture(cub, map->we);
			if (cub->textures[i].we[0].img == NULL)
			{
				// Precedents are not freed ==>> Memory leaks possible
				ft_error_handle(map, "Error\n", "Can't load texture", -42);
				ft_game_quit(cub, 1);
			}
			
			cub->textures[i].ea = ft_calloc(MAX_FRAME + 1, sizeof(t_frame));
			cub->textures[i].ea_anim_count = 1;
			cub->textures[i].ea[0] = ft_load_texture(cub, map->ea);
			if (cub->textures[i].ea[0].img == NULL)
			{
				// Precedents are not freed ==>> Memory leaks possible
				ft_error_handle(map, "Error\n", "Can't load texture", -42);
				ft_game_quit(cub, 1);
			}

			cub->textures[i].empty = FALSE;
			if (i == '0' || i == 'O' || i == 'N' || i == 'S' || i == 'E' || i == 'W')
				cub->textures[i].type = 0;
			else
				cub->textures[i].type = 1;
		}
	else
		for (int i = 0; i < 128; i++)
		{
			cub->textures[i].no = ft_calloc(MAX_FRAME + 1, sizeof(t_frame));
			cub->textures[i].no_anim_count = 0;
			for (int j = 0; j < MAX_FRAME; j++)
			{
				if (!map->text[i].no[j])
					continue ;
				cub->textures[i].no[j] = ft_load_texture(cub, map->text[i].no[j]);
				if (cub->textures[i].no[j].img == NULL)
				{
					// Precedents are not freed ==>> Memory leaks possible
					ft_error_handle(map, "Error\n", "Can't load texture", -42);
					ft_game_quit(cub, 1);
				}
				cub->textures[i].no_anim_count++;
			}
			
			cub->textures[i].so = ft_calloc(MAX_FRAME + 1, sizeof(t_frame));
			cub->textures[i].so_anim_count = 0;
			for (int j = 0; j < MAX_FRAME; j++)
			{
				if (!map->text[i].so[j])
					continue ;
				cub->textures[i].so[j] = ft_load_texture(cub, map->text[i].so[j]);
				if (cub->textures[i].so[j].img == NULL)
				{
					// Precedents are not freed ==>> Memory leaks possible
					ft_error_handle(map, "Error\n", "Can't load texture", -42);
					ft_game_quit(cub, 1);
				}
				cub->textures[i].so_anim_count++;
			}

			cub->textures[i].we = ft_calloc(MAX_FRAME + 1, sizeof(t_frame));
			cub->textures[i].we_anim_count = 0;
			for (int j = 0; j < MAX_FRAME; j++)
			{
				if (!map->text[i].we[j])
					continue ;
				cub->textures[i].we[j] = ft_load_texture(cub, map->text[i].we[j]);
				if (cub->textures[i].we[j].img == NULL)
				{
					// Precedents are not freed ==>> Memory leaks possible
					ft_error_handle(map, "Error\n", "Can't load texture", -42);
					ft_game_quit(cub, 1);
				}
				cub->textures[i].we_anim_count++;
			}

			cub->textures[i].ea = ft_calloc(MAX_FRAME + 1, sizeof(t_frame));
			cub->textures[i].ea_anim_count = 0;
			for (int j = 0; j < MAX_FRAME; j++)
			{
				if (!map->text[i].ea[j])
					continue ;
				cub->textures[i].ea[j] = ft_load_texture(cub, map->text[i].ea[j]);
				if (cub->textures[i].ea[j].img == NULL)
				{
					// Precedents are not freed ==>> Memory leaks possible
					ft_error_handle(map, "Error\n", "Can't load texture", -42);
					ft_game_quit(cub, 1);
				}
				cub->textures[i].ea_anim_count++;
			}

			cub->textures[i].empty = cub->textures[i].no_anim_count == 0
				&& cub->textures[i].so_anim_count == 0
				&& cub->textures[i].we_anim_count == 0
				&& cub->textures[i].ea_anim_count == 0;
			if (map->text[i].sp != -1)
				cub->textures[i].anim_delay = map->text[i].sp;
			if (map->text[i].mp != -1)
				cub->textures[i].map_color = map->text[i].mp;
			if (map->text[i].ty != -1)
				cub->textures[i].type = !!map->text[i].ty;
			else if (i == '0' || i == 'O' || i == 'N' || i == 'S' || i == 'E' || i == 'W')
				cub->textures[i].type = 0;
			else
				cub->textures[i].type = 1;
		}
}

/**
 * @brief Initialize the keys structure.
 * 
 * @note	Point: avoid `uninitialized values` errors.
 * 
 * @param keys 	The keys structure
*/
static void	ft_keys_init(t_keys *keys)
{
	keys->forward = FALSE;
	keys->backward = FALSE;
	keys->rot_left = FALSE;
	keys->rot_right = FALSE;
}

static void	ft_init_cub_array(t_cub *cub, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_size_y)
	{
		cub->map_array[i] = ft_calloc(map->map_size_x, sizeof(t_tile));
		if (!cub->map_array[i])
		{
			ft_error_handle(map, "Error\n", "Can't allocate memory", -42);
			ft_game_quit(cub, 1);
		}
		j = 0;
		while (j < map->map_size_x)
		{
			cub->map_array[i][j].type = map->map_array[i][j];
			j++;
		}
		i++;
	}
}

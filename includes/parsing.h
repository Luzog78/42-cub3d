/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:00:56 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/14 21:11:42 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

/**
 * @brief Structure for the map
 *
 * @param map_array the map array
 * @param map_array_copy copy of the map array for the flood fill algorithm
 * @param map_size_y size of the map in y
 * @param map_size_x size of the map in x
 * @param map_position position of the map in the file
 * @param no path of the north texture
 * @param so path of the south texture
 * @param we path of the west texture
 * @param ea path of the east texture
 * @param floor_c color of the floor
 * @param ceiling_c color of the ceiling
 * @param player_direction direction of the player
 * @param player_position position of the player
*/
typedef struct s_map
{
	char	**map_array;
	char	**map_array_copy;
	int		map_size_y;
	int		map_size_x;
	int		map_position;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_c[3];
	int		ceiling_c[3];
	int		player_direction[4];
	int		player_position[2];
}	t_map;


void	ft_acces_texture(t_map *map, char *line, int i);
void	ft_check_wall(t_map *map, int x, int y);
void	ft_find_player_position(t_map *map);
void	ft_check_args(int ac);
void	ft_check_map_file(t_map *map, char *map_file);
int		ft_check_texture(t_map *map, char *line);
void	ft_check_map_content(t_map *map, int fd);

#endif
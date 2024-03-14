/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:57:19 by hbelle            #+#    #+#             */
/*   Updated: 2024/03/14 11:17:56 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_args(int ac)
{
	if (ac <= 1)
	{
		ft_printf_error("Too few arguments\n");
		ft_printf_error("Usage: ./cub3d \"nameofamap.cub\"\n");
		exit(1);
	}
	else if (ac > 2)
	{
		ft_printf_error("Too many arguments\n");
		ft_printf_error("Usage: ./cub3d \"nameofamap.cub\"\n");
		exit(1);
	}
}

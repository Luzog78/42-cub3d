/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeterea <cpeterea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:49:55 by cpeterea          #+#    #+#             */
/*   Updated: 2024/02/24 11:34:23 by cpeterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[++i] != '\0')
		write(2, &s[i], 1);
	return (i);
}

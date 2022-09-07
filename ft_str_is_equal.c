/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:36:47 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 13:45:58 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_str_is_equal(char *str_1, char *str_2)
{
	if (ft_strlen(str_1) != ft_strlen(str_2))
		return (0);
	while (*str_1)
	{
		if (*str_1 != *str_2)
			return (0);
		str_1++;
		str_2++;
	}
	return (1);
}

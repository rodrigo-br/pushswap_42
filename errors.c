/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:25:07 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 14:25:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error_duplicated(void)
{
	ft_putstr_fd("ERROR: Duplicated numbers\n", 2);
	exit(0);
}

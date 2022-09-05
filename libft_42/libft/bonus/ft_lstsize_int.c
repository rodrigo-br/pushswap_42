/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:45:28 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 18:26:04 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_int(t_stack *lst)
{
	int		length;
	t_stack	*aux_lst;

	length = 0;
	aux_lst = lst;
	while (aux_lst)
	{
		aux_lst = aux_lst->next;
		length++;
	}
	return (length);
}

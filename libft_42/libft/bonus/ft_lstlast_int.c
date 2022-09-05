/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:56:19 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 18:25:56 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast_int(t_stack *lst)
{
	t_stack	*aux_lst;

	aux_lst = lst;
	if (!lst)
		return (lst);
	while (aux_lst->next)
		aux_lst = aux_lst->next;
	return (aux_lst);
}

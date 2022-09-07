/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:47:58 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 16:32:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*aux_free;

	if (!ft_lstsize_int(*b))
		return ;
	temp = ft_lstnew_int((*b)->content, (*b)->index);
	aux_free = *b;
	*b = (*b)->next;
	free(aux_free);
	ft_lstadd_front_int(a, temp);
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*aux_free;

	if (!ft_lstsize_int(*a))
		return ;
	temp = ft_lstnew_int((*a)->content, (*a)->index);
	aux_free = *a;
	*a = (*a)->next;
	free(aux_free);
	ft_lstadd_front_int(b, temp);
	ft_printf("pb\n");
}

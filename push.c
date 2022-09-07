/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:47:58 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 13:48:06 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	
	temp = ft_lstnew_int((*b)->content, (*b)->index);
	*b = (*b)->next;
	ft_lstadd_front_int(a, temp);
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	
	temp = ft_lstnew_int((*a)->content, (*a)->index);
	*a = (*a)->next;
	ft_lstadd_front_int(b, temp);
	ft_printf("pb\n");
}
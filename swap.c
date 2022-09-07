/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:49:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 16:25:10 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char id)
{
	t_stack	*aux;

	aux = ft_lstnew_int((*stack)->content, (*stack)->index);
	(*stack)->content = (*stack)->next->content;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->content = aux->content;
	(*stack)->next->index = aux->index;
	free(aux);
	ft_printf("s%c\n", id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:48:28 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 13:48:37 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **a)
{
	t_stack	*aux;
	t_stack	*temp_last;
	
	aux = *a;
	temp_last = ft_lstlast_int(*a);
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	ft_lstadd_front_int(a, temp_last);
	ft_printf("rra\n");
}

void	rotate_a(t_stack **a)
{
	t_stack	*aux;

	aux = *a;
	ft_lstadd_back_int(&aux, ft_lstnew_int(aux->content, aux->index));
	*a = (*a)->next;
	ft_printf("ra\n");
}

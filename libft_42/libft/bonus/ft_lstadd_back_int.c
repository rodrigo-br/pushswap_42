/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 03:32:45 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 18:25:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_int(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	if (!new)
		return ;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		aux = ft_lstlast_int(*lst);
		aux->next = new;
	}
}

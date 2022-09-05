/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:56:03 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 18:30:48 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_int(t_stack **lst, void (*del)(int))
{
	t_stack	*aux_lst;
	t_stack	*aux_free;

	if (lst == NULL)
		return ;
	aux_lst = *lst;
	while (aux_lst != NULL)
	{
		aux_free = aux_lst->next;
		ft_lstdelone_int(aux_lst, del);
		aux_lst = aux_free;
	}
	*lst = NULL;
}

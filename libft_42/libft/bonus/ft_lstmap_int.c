/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:12:04 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/06 21:32:33 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstmap_int(t_stack *lst, int (*f)(int), void (*del)(int))
{
	t_stack	*head;
	t_stack	*new_lst_aux;

	if (!del || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		new_lst_aux = ft_lstnew_int(f(lst->content), lst->index);
		if (!new_lst_aux)
		{
			if (head)
				ft_lstclear_int(&head, del);
			return (NULL);
		}
		ft_lstadd_back_int(&head, new_lst_aux);
		lst = lst->next;
	}
	return (head);
}

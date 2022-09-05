/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:13:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 18:26:01 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_int(int content)
{
	t_stack	*new_list;

	new_list = (t_stack *)malloc(sizeof(t_stack));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = 0;
	return (new_list);
}

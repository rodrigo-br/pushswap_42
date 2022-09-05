/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:27:07 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 18:30:43 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone_int(t_stack *lst, void (*del)(int))
{
	if (lst == NULL || !del)
		return ;
	del(lst->content);
	free(lst);
}

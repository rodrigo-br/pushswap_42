/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:27:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 14:35:58 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	map_lowest_index(t_stack *a)
{
	t_stack	*aux;
	int		index_min;
	int		index_counter;
	int		index_mapper;

	aux = a;
	index_min = MAXIMUM;
	index_counter = 0;
	while (aux)
	{
		if (aux->index <= index_min)
		{
			index_min = aux->index;
			index_mapper = index_counter;
		}
		index_counter++;
		aux = aux->next;
	}
	return (index_mapper);
}

int	map_highest_index(t_stack *a)
{
	t_stack	*aux;
	int		index_max;
	int		index_counter;
	int		index_mapper;

	aux = a;
	index_max = 2;
	index_counter = 0;
	while (aux)
	{
		if (aux->index >= index_max)
		{
			index_max = aux->index;
			index_mapper = index_counter;
		}
		index_counter++;
		aux = aux->next;
	}
	return (index_mapper);
}

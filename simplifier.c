/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:08:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 14:56:03 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*simplify_copy(int *copy, int *copy_sorted, int elements)
{
	int	i;
	int	ele;
	int	*new_copy;

	i = -1;
	new_copy = ft_calloc(elements, sizeof(int));
	while (++i < elements)
	{
		ele = -1;
		while (++ele < elements)
		{
			if (copy[i] == copy_sorted[ele])
			{
				new_copy[i] = ele;
			}
		}
	}
	return (new_copy);
}

int	*sort_copy(int *copy, int elements)
{
	int	i;
	int	aux;
	int	*new_copy;

	i = -1;
	new_copy = ft_calloc(elements, sizeof(int));
	while (++i < elements)
		new_copy[i] = copy[i];
	i = 0;
	while (i < elements - 1)
	{
		if (new_copy[i] > new_copy[i + 1])
		{
			aux = new_copy[i];
			new_copy[i] = new_copy[i + 1];
			new_copy[i + 1] = aux;
			i = -1;
		}
		i++;
	}
	return (new_copy);
}

int	*copy_stack_values(t_stack *stack, int elements)
{
	int	*new_copy;
	int	i;

	i = 0;
	new_copy = ft_calloc(elements, sizeof(int));
	while (i < elements)
	{
		new_copy[i] = stack->content;
		stack = stack->next;
		i++;
	}
	i = 0;
	return (new_copy);
}

void	simplifying_numbers(t_stack **stack, int elements)
{
	int		*copy;
	int		*copy_sorted;
	int		*copy_simplified;
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *stack;
	copy = copy_stack_values(*stack, elements);
	copy_sorted = sort_copy(copy, elements);
	copy_simplified = simplify_copy(copy, copy_sorted, elements);
	while (i < elements)
	{
		aux->index = copy_simplified[i];
		i++;
		aux = aux->next;
	}
	free(copy);
	free(copy_sorted);
	free(copy_simplified);
}

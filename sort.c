/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:06:43 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 20:18:30 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_tree_elements(t_stack **a)
{
	int	index_mapper;

	while (!is_sorted(*a))
	{
		index_mapper = map_highest_index(*a);
		if (index_mapper == 0)
			rotate_a(a);
		else if (index_mapper == 1)
			reverse_rotate_a(a);
		else
			swap(a, 'a');
	}
}

void	handle_four_elements(t_stack **a, t_stack **b)
{
	int	lowest_index;

	lowest_index = map_lowest_index(*a);
	if (is_sorted(*a))
		return ;
	if (lowest_index == 0)
	{
		push_b(a, b);
		handle_tree_elements(a);
		push_a(a, b);
	}
	else if (lowest_index == 1)
	{
		rotate_a(a);
		handle_four_elements(a, b);
	}
	else
	{
		reverse_rotate_a(a);
		handle_four_elements(a, b);
	}
}

void	handle_five_elements(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) && !ft_lstsize_int(*b))
		return ;
	if (map_lowest_index(*a) == 0 && ft_lstsize_int(*b) < 2)
	{
		push_b(a, b);
		handle_four_elements(a, b);
		push_a(a, b);
	}
	else if (map_lowest_index(*a) <= 2 && ft_lstsize_int(*b) < 2)
	{
		rotate_a(a);
		handle_five_elements(a, b);
	}
	else if (map_lowest_index(*a) > 2 && ft_lstsize_int(*b) < 2)
	{
		reverse_rotate_a(a);
		handle_five_elements(a, b);
	}
	else
	{
		handle_tree_elements(a);
		push_a(a, b);
		push_a(a, b);
	}
}

void	handle_many_elements(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_lstsize_int(*a);
	max_bits = 0;
	while ((size >> max_bits))
		max_bits++;
	while (max_bits--)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}

void	sort_numbers(t_stack **a, t_stack **b, int n)
{
	if (n == 2)
		swap(a, 'a');
	else if (n == 3)
		handle_tree_elements(a);
	else if (n == 4)
		handle_four_elements(a, b);
	else if (n == 5)
		handle_five_elements(a, b);
	else
		handle_many_elements(a, b);
}

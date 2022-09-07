/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:06:43 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 14:16:45 by ralves-b         ###   ########.fr       */
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
	int	lowest_index;

	lowest_index = map_lowest_index(*a);
	if (lowest_index == 0 && ft_lstsize_int(*b) < 2)
	{
		push_b(a, b);
		handle_five_elements(a, b);
	}
	else if (lowest_index <= 2 && ft_lstsize_int(*b) < 2)
	{
		rotate_a(a);
		handle_five_elements(a, b);
	}
	else if (lowest_index > 2 && ft_lstsize_int(*b) < 2)
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

void	sort_numbers(t_stack **a, t_stack **b, int n)
{
	(void)b;
	if (n == 2)
		swap(a, 'a');
	else if (n == 3)
		handle_tree_elements(a);
	else if (n == 4)
		handle_four_elements(a, b);
	else if (n == 5)
		handle_five_elements(a, b);
}

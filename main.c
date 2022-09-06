/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:05:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/06 23:35:24 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *head);
void	swap_a(t_stack **stack);

// int	map_lowest_index(t_stack *a)
// {
// 	t_stack	*aux;
// 	int		index_min;
// 	int		index_counter;
// 	int		index_mapper;

// 	aux = a;
// 	index_min = 0;
// 	index_counter = 0;
// 	while (aux)
// 	{
// 		if (aux->index >= index_min)
// 		{
// 			index_min = aux->index;
// 			index_mapper = index_counter;
// 		}
// 		index_counter++;
// 		aux = aux->next;
// 	}
// 	return (index_mapper);
// }

// void	handle_four_elements(t_stack **a, t_stack **b)
// {
	
// }

void	exit_error_duplicated(void)
{
	ft_putstr_fd("ERROR: Duplicated numbers\n", 2);
	exit(0);
}

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
			swap_a(a);
	}
}

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
}

void	swap_a(t_stack **stack)
{
	t_stack	*aux;

	aux = ft_lstnew_int((*stack)->content, (*stack)->index);
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = aux->content;
	ft_printf("sa\n");
}

void	sort_numbers(t_stack **a, t_stack **b, int n)
{
	(void)b;
	if (n == 2)
		swap_a(a);
	else if (n == 3)
		handle_tree_elements(a);
	// else if (n == 4)
	// 	handle_four_elements(a, b);
}

int	is_sorted(t_stack *head)
{
	int	minimum;

	minimum = MINIMUM;
	while (head)
	{
		if (head->content < minimum)
			return (0);
		minimum = head->content;
		head = head->next;
	}
	return (-1);
}

void	fill_stack_a(t_stack **head, char **argv)
{
	*head = ft_lstnew_int(ft_atoi(*argv), 0);
	argv++;
	while (*argv)
	{
		ft_lstadd_back_int(head, ft_lstnew_int(ft_atoi(*argv), 0));
		argv++;
	}
}

int	check_argv_error(char **argv)
{
	int	i;

	while (*argv)
	{
		i = 0;
		if (ft_atolli(*argv) > 2147483647
			|| ft_atolli(*argv) < -2147483648 || ft_strlen(*argv) > 11)
			return (-1);
		while ((*argv)[i])
		{
			if ((*argv)[i] == '-' || (*argv)[i] == '+')
				i++;
			if (!ft_isdigit((*argv)[i]))
				return (-1);
			i++;
		}
		argv++;
	}
	return (0);
}

void	test_duplicated(char **argv)
{
	int	i;
	int	counter;

	i = 0;
	while (argv[i])
	{
		counter = 0;
		while (argv[counter])
		{
			if (counter != i)
			{
				if (!ft_strncmp(argv[i], argv[counter], ft_strlen(argv[i])))
					exit_error_duplicated();
			}
			counter++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		elements;

	stack_a = NULL;
	stack_b = NULL;
	elements = argc - 1;
	if (elements == 0 || check_argv_error(argv + 1))
	{
		ft_putstr_fd("Invalid number/type of args", 2);
		return (-1);
	}
	test_duplicated(argv + 1);
	fill_stack_a(&stack_a, argv + 1);
	if (is_sorted(stack_a))
		return (0);
	simplifying_numbers(&stack_a, elements);
	sort_numbers(&stack_a, &stack_b, elements);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}

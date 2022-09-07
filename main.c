/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:05:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 20:12:26 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

void	print_index(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->index);
		stack = stack->next;
	}
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

void	free_all(t_stack **a, t_stack **b)
{
	t_stack	*aux_lst;
	t_stack	*aux_free;

	free(*b);
	*b = NULL;
	if (*a == NULL)
		return ;
	aux_lst = *a;
	while (aux_lst)
	{
		aux_free = aux_lst->next;
		free(aux_lst);
		aux_lst = aux_free;
	}
	*a = NULL;
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
	free_all(&stack_a, &stack_b);
	return (0);
}

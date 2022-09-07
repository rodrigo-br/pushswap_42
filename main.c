/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:05:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 14:31:44 by ralves-b         ###   ########.fr       */
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
	print_stack(stack_a);
	return (0);
}

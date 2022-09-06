/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:05:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/06 15:27:02 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap_a(t_stack **stack)
{
	t_stack	*aux;

	aux = ft_lstnew_int((*stack)->content);
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = aux->content;
	ft_printf("sa\n");
}

void	sort_numbers(t_stack **a, t_stack **b, int n)
{
	(void)b;
	if (n == 2)
		swap_a(a);
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
	ft_putstr_fd("Already sorted\n", 1);
	return (-1);
}

void	fill_stack_a(t_stack **head, char **argv)
{
	*head = ft_lstnew_int(ft_atoi(*argv));
	argv++;
	while (*argv)
	{
		ft_lstadd_back_int(head, ft_lstnew_int(ft_atoi(*argv)));
		argv++;
	}
}

int	check_argv_error(char **argv)
{
	int	i;

	argv++;
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		elements;

	stack_a = NULL;
	stack_b = NULL;
	elements = argc - 1;
	if (elements == 0 || check_argv_error(argv))
	{
		ft_putstr_fd("Invalid number/type of args", 2);
		return (-1);
	}
	fill_stack_a(&stack_a, argv + 1);
	if (is_sorted(stack_a))
		return (0);
	sort_numbers(&stack_a, &stack_b, elements);
	while (stack_a)
	{
		ft_printf("\n%d", stack_a->content);
		stack_a = stack_a->next;
	}
}

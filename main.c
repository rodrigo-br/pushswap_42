/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:05:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 19:26:24 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *head)
{
	int	minimum;

	minimum = MINIMUM;
	while (head)
	{
		if (head->content < minimum)
		{
			ft_putstr_fd("Need to sort", 1);
			return (0);
		}
		minimum = head->content;
		head = head->next;
	}
	ft_putstr_fd("Already sorted", 1);
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
	if (argc == 1 || check_argv_error(argv))
	{
		ft_putstr_fd("Invalid number/type of args", 2);
		return (-1);
	}
	fill_stack_a(&stack_a, argv + 1);
	if (is_sorted(stack_a))
		return (0);
	//sort_numbers(stack_a, stack_b);
}

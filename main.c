/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:05:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/08 00:46:37 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (*b)
	{
		free(*b);
		*b = NULL;
	}
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
	if (validate_errors(elements, argv + 1))
		return (0);
	fill_stack_a(&stack_a, argv + 1);
	if (is_sorted(stack_a))
	{
		free_all(&stack_a, &stack_b);
		return (0);
	}
	simplifying_numbers(&stack_a, elements);
	sort_numbers(&stack_a, &stack_b, elements);
	free_all(&stack_a, &stack_b);
	return (0);
}

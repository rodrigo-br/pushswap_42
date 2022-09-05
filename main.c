/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:05:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 18:57:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(t_stack **head, char **argv)
{
	t_stack	*new_list;
	t_stack	**aux_list;

	aux_list = head;
	argv++;
	new_list = ft_lstnew_int(ft_atoi(*argv));
	*aux_list = new_list;
	argv++;
	while (*argv)
	{
		ft_lstadd_back_int(aux_list, ft_lstnew_int(ft_atoi(*argv)));
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
		while((*argv)[i])
		{
			if ((*argv)[i] == '-' || (*argv)[i] == '+')
				i++;
			if (!ft_isdigit((*argv)[i]))
			{
				ft_putstr_fd("Use only integer values as argumments", 2);
				return (-1);
			}
			i++;
		}
		argv++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*head;
	// t_stack stack_b;
	head = NULL;
	(void)argc;
	if (check_argv_error(argv))
		return (-1);
	fill_stack_a(&head, argv);
	while (head)
	{
		ft_printf("%d\n", head->content);
		head = head->next;
	}
}
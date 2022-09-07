/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:54:24 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 14:02:30 by ralves-b         ###   ########.fr       */
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
			return (0);
		minimum = head->content;
		head = head->next;
	}
	return (-1);
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
				if (ft_str_is_equal(argv[i], argv[counter]))
					exit_error_duplicated();
			}
			counter++;
		}
		i++;
	}
}

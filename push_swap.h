/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:04:16 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/07 14:27:41 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_42/printf/ft_printf.h"

# define MINIMUM -2147483648
# define MAXIMUM 2147483647

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

// New Libft functions
void			ft_lstadd_back_int(t_stack **lst, t_stack *new);
void			ft_lstadd_front_int(t_stack **lst, t_stack *new);
void			ft_lstclear_int(t_stack **lst, void (*del)(int));
void			ft_lstdelone_int(t_stack *lst, void (*del)(int));
void			ft_lstiter_int(t_stack *lst, void (*f)(int));
t_stack			*ft_lstlast_int(t_stack *lst);
t_stack			*ft_lstmap_int(t_stack *lst, int (*f)(int), void (*del)(int));
t_stack			*ft_lstnew_int(int content, int index);
int				ft_lstsize_int(t_stack *lst);
long long int	ft_atolli(const char *nptr);
int				ft_n_in(int n, int *array, int n_membs);
int				ft_str_is_equal(char *str_1, char *str_2);

// Push_swap actions
void			push_b(t_stack **a, t_stack **b);
void			push_a(t_stack **a, t_stack **b);
void			reverse_rotate_a(t_stack **a);
void			rotate_a(t_stack **a);
void			swap(t_stack **stack, char id);

// Validators
int				check_argv_error(char **argv);
void			test_duplicated(char **argv);
int				is_sorted(t_stack *head);

// Simplifier
void			simplifying_numbers(t_stack **stack, int elements);

// Sort caller
void			sort_numbers(t_stack **a, t_stack **b, int n);

// Errors
void			exit_error_duplicated(void);

// Mappers
int				map_lowest_index(t_stack *a);
int				map_highest_index(t_stack *a);

#endif
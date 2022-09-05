/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:04:16 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/05 18:30:20 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_42/printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

void	ft_lstadd_back_int(t_stack **lst, t_stack *new);
void	ft_lstadd_front_int(t_stack **lst, t_stack *new);
void	ft_lstclear_int(t_stack **lst, void (*del)(int));
void	ft_lstdelone_int(t_stack *lst, void (*del)(int));
void	ft_lstiter_int(t_stack *lst, void (*f)(int));
t_stack	*ft_lstlast_int(t_stack *lst);
t_stack	*ft_lstmap_int(t_stack *lst, int(*f)(int), void (*del)(int));
t_stack	*ft_lstnew_int(int content);
int		ft_lstsize_int(t_stack *lst);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:41:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/04 18:19:22 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	rev_rotate_stack(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	check_stack(t_list *a)
{
	if (check_if_sorted(a))
		exit(0);
	if (check_for_dup(a))
	{
		ft_lstclear(&a);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ft_lstsize(a) == 2)
	{
		sa(&a);
		exit(0);
	}
	else if (ft_lstsize(a) == 3)
	{
		three_sort(&a);
		exit(0);
	}
}

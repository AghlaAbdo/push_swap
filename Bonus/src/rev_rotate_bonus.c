/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:58:13 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/09 20:52:14 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rev_rotate_stack(t_list **stack)
{
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_list **a)
{
	rev_rotate_stack(a);
}

void	rrb(t_list **b)
{
	rev_rotate_stack(b);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
}

void	rev_rotate(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap && *b != cheap->target)
		rrr(a, b);
}

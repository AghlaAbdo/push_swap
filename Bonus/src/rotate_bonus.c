/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:03:52 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/10 10:17:26 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	rotate_stack(t_list **stack)
{
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_list **a)
{
	rotate_stack(a);
}

void	rb(t_list **b)
{
	rotate_stack(b);
}

void	rr(t_list **a, t_list **b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	rotate(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap && *b != cheap->target)
		rr(a, b);
}

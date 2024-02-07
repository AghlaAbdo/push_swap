/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:18:45 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/07 11:22:12 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list **src, t_list **dst)
{
	t_list	*to_push;

	if (!src || !*src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = to_push;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
	}
	else
	{
		to_push->next = *dst;
		to_push->next->prev = to_push;
		*dst = to_push;
	}
}

void	swap_stack(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	rotate(t_list **a, t_list **b, t_list *cheap)
{
	while ((*a)->num != cheap->num && (*b)->num != cheap->target->num)
		rr(a, b);
}

void	rev_rotate(t_list **a, t_list **b, t_list *cheap)
{
	while ((*a)->num != cheap->num && (*b)->num != cheap->target->num)
		rrr(a, b);
}

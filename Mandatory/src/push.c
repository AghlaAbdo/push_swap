/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:07:35 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/07 15:05:01 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_stack(t_list **src, t_list **dst)
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

void	pb(t_list **a, t_list **b)
{
	push_stack(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_list **a, t_list **b)
{
	push_stack(b, a);
	ft_putstr_fd("pa\n", 1);
}

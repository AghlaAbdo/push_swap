/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:18:45 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/05 11:16:58 by aaghla           ###   ########.fr       */
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

void	swap_stack(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	third = (*lst)->next->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	*lst = second;
}

void	rotate(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap && *b != cheap->target)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

void	rev_rotate(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap && *b != cheap->target)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

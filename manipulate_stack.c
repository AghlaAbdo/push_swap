/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:52:58 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/02 22:55:57 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*last;
	t_list	*first;
	
	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	last->next = first;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first->prev = last;
	first->next = NULL;
}

void	rev_rotate_stack(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	printf("last = %d\n", last->num);
	printf("last->prev = %d\n", last->prev->num);
	printf("last->nex = %d\n", last->next->num);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	swap_stack(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	ft_lstadd_front(lst, second);
}

void	push_a(t_list **src, t_list **dst)
{
	t_list	*to_push;
	
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

void	rr(t_list **a, t_list **b)
{
	rotate_stack(a);
	rotate_stack(b);
	printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	printf("rrr\n");
}

void	ra(t_list **a)
{
	rotate_stack(a);
	printf("ra\n");
}

void	rb(t_list **b)
{
	rotate_stack(b);
	printf("ra\n");
}

void	rra(t_list **a)
{
	rev_rotate_stack(a);
	printf("rra\n");
}

void	rrb(t_list **b)
{
	rev_rotate_stack(b);
	printf("rra\n");
}

void	pb(t_list **a, t_list **b)
{
	push_a(a, b);
	printf("pb\n");
}

void	pa(t_list **a, t_list **b)
{
	push_a(b, a);
	printf("pa\n");
}

void	sa(t_list **a)
{
	swap_stack(a);
	printf("sa\n");
}
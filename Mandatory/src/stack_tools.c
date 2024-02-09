/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:41:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/09 12:54:55 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_stack(t_list *a)
{
	if (check_for_dup(a))
	{
		ft_lstclear(&a);
		force_exit();
	}
	if (check_if_sorted(a))
	{
		ft_lstclear(&a);
		exit(0);
	}
	if (ft_lstsize(a) == 2)
	{
		sa(&a);
		ft_lstclear(&a);
		exit(0);
	}
	else if (ft_lstsize(a) == 3)
	{
		three_sort(&a);
		ft_lstclear(&a);
		exit(0);
	}
	return (0);
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

void	set_target_a(t_list *a, t_list *b)
{
	t_list		*target;
	t_list		*current_b;
	long long	match;

	while (a)
	{
		match = LLONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num && current_b->num > match)
			{
				match = current_b->num;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match == LLONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	set_target_b(t_list *a, t_list *b)
{
	t_list		*target;
	t_list		*current_a;
	long long	match;

	while (b)
	{
		match = LLONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < match)
			{
				match = current_a->num;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (match == LLONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

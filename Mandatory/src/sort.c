/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:12:08 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/04 18:22:59 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bring_to_top(t_list **stack, t_list *cheap, char c)
{
	t_list	*temp;

	temp = *stack;
	while (*stack != cheap)
	{
		if (c == 'a')
		{
			if (cheap->is_above)
				ra(stack);
			else
			{
				rra(stack);
			}
		}
		else if (c == 'b')
		{
			if (cheap->is_above)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	bring_min_top(t_list **a)
{
	t_list	*min;

	min = find_min(*a);
	while (*a != min)
	{
		if (min->is_above)
			ra(a);
		else
			rra(a);
	}
}

void	push_to_b(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = get_cheap(*a);
	if (cheap->is_above && cheap->target->is_above)
		rotate(a, b, cheap);
	else if (!(cheap->is_above) && !(cheap->target->is_above))
		rev_rotate(a, b, cheap);
	bring_to_top(a, cheap, 'a');
	bring_to_top(b, cheap->target, 'b');
	pb(a, b);
}

void	push_to_a(t_list **a, t_list **b)
{
	bring_to_top(a, (*b)->target, 'a');
	pa(a, b);
}

void	three_sort(t_list **a)
{
	t_list	*max;
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		temp = temp->next;
	}
	max = find_max(*a);
	if (*a == max)
		ra(a);
	if ((*a)->next == max)
	{
		rra(a);
	}
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

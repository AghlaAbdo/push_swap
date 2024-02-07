/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:15:27 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/06 18:16:40 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_list *stack)
{
	int	i;
	int	mid;

	if (!stack)
		return ;
	i = 0;
	mid = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->is_above = TRUE;
		else
			stack->is_above = FALSE;
		stack = stack->next;
		i++;
	}
}

// t_list	*find_max(t_list *stack)
// {
// 	long			max;
// 	t_list	*max_node;

// 	if (!stack)
// 		return (NULL);
// 	max = LONG_MIN;
// 	while (stack)
// 	{
// 		if (stack->num > max)
// 		{
// 			max = stack->num;
// 			max_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (max_node);
// }

// t_list	*find_min(t_list *stack)
// {
// 	long			min;
// 	t_list	*min_node;
 
// 	if (!stack)
// 		return (NULL);
// 	min = LONG_MAX;
// 	while (stack)
// 	{
// 		if (stack->num < min)
// 		{
// 			min = stack->num;
// 			min_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (min_node); 
// }

t_list	*find_max(t_list *stack)
{
	t_list	*max;
	int		n;

	n = stack->num;
	max = stack;
	while (stack)
	{
		if (stack->num > n)
		{
			n = stack->num;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_list	*find_min(t_list *stack)
{
	t_list	*min;
	int		n;

	n = stack->num;
	min = stack;
	while (stack)
	{
		if (stack->num < n)
		{
			n = stack->num;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	cost_calc(t_list *a, t_list *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_lstsize(a);
	b_len = ft_lstsize(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->is_above))
			a->cost = a_len - (a->index);
		if (a->target->is_above)
			a->cost += a->target->index;
		else
			a->cost += b_len - (a->target->index);
		a = a->next;
	}
}

t_list	*get_cheap(t_list *stack)
{
	t_list		*cheap;
	long long	n;

	n = LLONG_MAX;
	while (stack)
	{
		if ((long long)stack->cost < n)
		{
			cheap = stack;
			n = (long long)stack->cost;
		}
		stack = stack->next;
	}
	return (cheap);
}

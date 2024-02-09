/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:41:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/09 20:58:04 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*init_nums(char **str)
{
	t_list		*list;
	long long	num;
	int			i;

	i = 0;
	list = NULL;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > 2147483647 || num < -2147483648 || check_overflow(str[i++]))
		{
			free_arr(str);
			ft_lstclear(&list);
			force_exit();
		}
		if (ft_lstadd_back(&list, ft_lstnew((int)num)))
		{
			free_arr(str);
			ft_lstclear(&list);
			force_exit();
		}
	}
	return (list);
}

void	check_stack(t_list *a)
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

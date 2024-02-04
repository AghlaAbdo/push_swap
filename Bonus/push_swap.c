/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:28:36 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/04 22:54:04 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(void)
{
	system("leaks checker");
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

void	sort_stack(t_list **a, t_list **b)
{
	int	count;

	count = ft_lstsize(*a);
	if (count-- > 3)
		pb(a, b);
	if (count-- > 3)
		pb(a, b);
	while (count-- > 3)
	{
		set_index(*a);
		set_index(*b);
		set_target_a(*a, *b);
		cost_calc(*a, *b);
		push_to_b(a, b);
	}
	three_sort(a);
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_target_b(*a, *b);
		push_to_a(a, b);
	}
	set_index(*a);
	bring_min_top(a);
}
#include <stdio.h>

void	check_intruction(t_list *stack, char *line)
{
	(void)stack;
	if (!line)
		return ;
	if (ft_strcmp(line, "sa\n") && ft_strcmp(line, "sb\n") && ft_strcmp(line, "ss\n")
		&& ft_strcmp(line, "pa\n") && ft_strcmp(line, "pb\n") && ft_strcmp(line, "ra\n")
		&& ft_strcmp(line, "ra\n") && ft_strcmp(line, "rb\n") && ft_strcmp(line, "rr\n")
		&& ft_strcmp(line, "rra\n") && ft_strcmp(line, "rrb\n") && ft_strcmp(line, "rrr\n"))
		force_exit();
}

int	main(int ac, char **av)
{
	char	**str_nums;
	char	*str;
	char	*line;
	t_list	*a;
	t_list	*b;

	atexit(f);
	b = NULL;


	
	if (ac == 1)
		return (0);
	str = join_nums(ac, av);
	str_nums = ft_split(str, ' ');
	free(str);
	check_valid_nums(str_nums);
	a = init_nums(str_nums);
	free_arr(str_nums);
	check_stack(a);
	line = get_next_line(0);
	check_intruction(a, line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(0);
		check_intruction(a, line);
	}
	sort_stack(&a, &b);
	ft_lstclear(&a);
	return (0);
}

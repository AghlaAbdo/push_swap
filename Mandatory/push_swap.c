/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:28:36 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/07 23:43:45 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	f(void)
// {
// 	system("leaks push_swap");
// }

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
	// if (b->num < b->next->num)
	// 	rb(b);
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

void	sort_arr(int **arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if ((*arr)[i] < (*arr)[j])
			{
				temp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = temp;
			}
		}
	}
	// printf("here in sort\n");
}

int	get_med(t_list *stack)
{
	int	*arr;
	int	med;
	int	i;

	i = 0;
	med = ft_lstsize(stack);
	// printf("here in get_med\n");
	arr = (int *)malloc(ft_lstsize(stack) * sizeof(int));
	while (stack)
	{
		arr[i++] = stack->num;
		stack = stack->next;
	}
	i = 0;
	// while (i < med)
	// 	printf("| %d |\n", arr[i++]);
	sort_arr(&arr, med);
	// printf("AFTER Sort:");
	// while (i < med)
	// 	printf("| %d |\n", arr[i++]);
	// printf("\n       _________\n");
	med = arr[med / 2];
	// printf("med = %d | med num = %d\n", med, arr[med]);
	return (med);
}

void	sort_stack(t_list **a, t_list **b)
{
	int	count;
	int	med;

	count = ft_lstsize(*a);
	if (count-- > 3)
		pb(a, b);
	if (count-- > 3)
		pb(a, b);
	while (count-- > 3)
	{
		med = get_med(*a);
		if ((*a)->num > med)
			pb(a, b);
		else
			ra(a);
		// set_index(*a);
		// set_index(*b);
		// set_target_a(*a, *b);
		// cost_calc(*a, *b);
		// push_to_b(a, b);
	}
	three_sort(a);
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_target_b(*a, *b);
		// cost_calc(*b, *a);
		push_to_a(a, b);
	}
	bring_min_top(a);
}

void	free_exit(char **av)
{
	free(av);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	char	*str;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!av[1][0] || (!av[1][1] && !(av[1][0] >= '0' && av[1][0] <= '9'))
		|| check_overflow(av[1]))
		force_exit();
	str = join_nums(ac, av);
	av = ft_split(str, ' ');
	free(str);
	if (!av || !av[0])
		free_exit(av);
	check_valid_nums(av);
	a = init_nums(av);
	free_arr(av);
	check_stack(a);
	sort_stack(&a, &b);
	ft_lstclear(&a);
	return (0);
}

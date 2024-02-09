/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:28:36 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/09 10:46:03 by aaghla           ###   ########.fr       */
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
}

int	get_med(t_list *stack)
{
	int	*arr;
	int	med;
	int	i;

	i = 0;
	med = ft_lstsize(stack);
	arr = (int *)malloc(ft_lstsize(stack) * sizeof(int));
	while (stack)
	{
		arr[i++] = stack->num;
		stack = stack->next;
	}
	i = 0;
	sort_arr(&arr, med);
	med = arr[med / 2];
	return (med);
}

void	sort_stack(t_list **a, t_list **b)
{
	int	count;
	int	med;
	int	i;

	count = ft_lstsize(*a);
	while (count-- > 3)
	{
		i = 0;
		med = get_med(*a);
		while (ft_lstsize(*a) > 3 && i++ < ft_lstsize(*a))
		{
			if ((*a)->num <= med)
				pb(a, b);
			else
				ra(a);
		}
	}
	three_sort(a);
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_target_b(*a, *b);
		cost_calc(*b, *a);
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

void	sort_low(t_list **a, t_list **b)
{
	int	count;

	count = ft_lstsize(*a);
	if (count-- > 3)
		pb(a, b);
	if (count-- > 3)
		pb(a, b);
	while (count-- > 3)
	{
		set_index(*b);
		set_index(*a);
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
		cost_calc(*b, *a);
		push_to_a(a, b);
	}
	bring_min_top(a);
}

int	main(int ac, char **av)
{
	char	*str;
	t_list	*a;
	t_list	*b;
	t_list	*temp;

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
	if (ft_lstsize(a) < 300)
		sort_low(&a, &b);
	else
		sort_stack(&a, &b);
	temp = a;
	// printf("\n\nAfter sort:\n");
	// while (temp)
	// {
	// 	printf("| %d |\n", temp->num);
	// 	temp = temp->next;
	// }
	ft_lstclear(&a);
	return (0);
}

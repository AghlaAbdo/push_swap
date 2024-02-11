/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:28:36 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/10 11:52:14 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int **arr, int n)
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

static int	get_med(t_list **a, t_list **b)
{
	t_list	*temp;
	int		*arr;
	int		med;
	int		i;

	temp = *a;
	i = 0;
	med = ft_lstsize(temp);
	arr = (int *)malloc(ft_lstsize(temp) * sizeof(int));
	if (!arr)
	{
		ft_lstclear(a);
		ft_lstclear(b);
		force_exit();
	}
	while (temp)
	{
		arr[i++] = temp->num;
		temp = temp->next;
	}
	sort_arr(&arr, med);
	med = arr[med / 2];
	free(arr);
	return (med);
}

static void	sort_low(t_list **a, t_list **b)
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
	from_b_to_a(a, b);
}

static void	sort_high(t_list **a, t_list **b)
{
	int	count;
	int	med;
	int	i;
	int	n;

	count = ft_lstsize(*a);
	while (count-- > 3)
	{
		i = 0;
		med = get_med(a, b);
		n = ft_lstsize(*a);
		while (n > 3 && i++ < n)
		{
			if ((*a)->num <= med)
				pb(a, b);
			else
				ra(a);
		}
	}
	three_sort(a);
	from_b_to_a(a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!av[1][0] || (!av[1][1] && !(av[1][0] >= '0' && av[1][0] <= '9'))
		|| check_overflow(av[1]))
		force_exit();
	a = handle_args(ac, av);
	check_stack(a);
	if (ft_lstsize(a) < 300)
		sort_low(&a, &b);
	else
		sort_high(&a, &b);
	ft_lstclear(&a);
	return (0);
}

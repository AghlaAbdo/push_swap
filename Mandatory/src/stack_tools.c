/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:41:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/07 15:00:37 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_stack(t_list *a)
{
	if (check_for_dup(a))
	{
		ft_lstclear(&a);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (check_if_sorted(a))
		exit(0);
	if (ft_lstsize(a) == 2)
	{
		sa(&a);
		exit(0);
	}
	else if (ft_lstsize(a) == 3)
	{
		three_sort(&a);
		exit(0);
	}
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

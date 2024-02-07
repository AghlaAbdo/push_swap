/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:41:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/07 16:45:15 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	check_stack(t_list *a)
{
	if (check_for_dup(a))
	{
		ft_lstclear(&a);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	rotate(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap && *b != cheap->target)
		rr(a, b);
}

void	rev_rotate(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap && *b != cheap->target)
		rrr(a, b);
}

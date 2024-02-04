/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:03:52 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/04 18:53:21 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}

void	ra(t_list **a)
{
	rotate_stack(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **b)
{
	rotate_stack(b);
	ft_putstr_fd("rb\n", 1);
}

void	rra(t_list **a)
{
	rev_rotate_stack(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	rev_rotate_stack(b);
	ft_putstr_fd("rrb\n", 1);
}

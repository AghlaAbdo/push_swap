/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:07:35 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/04 18:47:12 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_list **a, t_list **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putstr_fd("rr\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	push_a(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_list **a, t_list **b)
{
	push_a(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	sa(t_list **a)
{
	swap_stack(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **b)
{
	swap_stack(b);
	ft_putstr_fd("sb\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:42:27 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/02 11:25:03 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "Libft/libft.h"
#include <libc.h>
#include <limits.h>

void	rotate_stack(t_list **lst);
void	rev_rotate_stack(t_list **lst);
void	swap_stack(t_list **lst);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list **a);
void	pa(t_list **a, t_list **b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:18:45 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/10 10:17:33 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	swap_stack(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	third = (*lst)->next->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	*lst = second;
}

void	sa(t_list **a)
{
	swap_stack(a);
}

void	sb(t_list **b)
{
	swap_stack(b);
}

void	ss(t_list **a, t_list **b)
{
	swap_stack(a);
	swap_stack(b);
}

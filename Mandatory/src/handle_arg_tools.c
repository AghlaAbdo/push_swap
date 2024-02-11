/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:25:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/10 11:31:20 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	force_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_for_dup(t_list *stack)
{
	t_list	*current;

	while (stack)
	{
		current = stack->next;
		while (current)
		{
			if (stack->num == current->num)
				return (1);
			current = current->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_if_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	from_b_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_target_b(*a, *b);
		cost_calc(*b, *a);
		push_to_a(a, b);
	}
	set_index(*a);
	bring_min_top(a);
}

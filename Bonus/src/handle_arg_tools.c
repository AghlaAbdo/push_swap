/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:25:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/05 09:48:36 by aaghla           ###   ########.fr       */
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

void	check_if_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
		{
			its_ko();
		}
		stack = stack->next;
	}
	ft_putstr_fd("OK\n", 1);
	exit(0);
}

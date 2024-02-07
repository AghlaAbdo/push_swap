/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg_tools_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:25:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/07 16:44:52 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	force_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_list	*handle_args(int ac, char **av)
{
	char	*str;
	t_list	*a;

	str = join_nums(ac, av);
	av = ft_split(str, ' ');
	free(str);
	if (!av || !av[0])
	{
		free(av);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	check_valid_nums(av);
	a = init_nums(av);
	free_arr(av);
	return (a);
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

void	check_if_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
		{
			its_ko(stack);
		}
		temp = temp->next;
	}
	ft_lstclear(stack);
	ft_putstr_fd("OK\n", 1);
	exit(0);
}

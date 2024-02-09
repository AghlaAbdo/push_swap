/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg_tools_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:25:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/09 16:04:48 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	force_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_empty_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (!av[i][j])
			force_exit();
		i++;
	}
}

t_list	*handle_args(int ac, char **av)
{
	char	*str;
	t_list	*a;

	check_empty_args(ac, av);
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

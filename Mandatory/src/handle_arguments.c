/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:08:57 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/09 12:58:35 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_valid_nums(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		if (arr[i][j] == '-')
			j++;
		if (!arr[i][j])
		{
			free_arr(arr);
			force_exit();
		}
		while (arr[i][j])
		{
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
			{
				free_arr(arr);
				force_exit();
			}
			j++;
		}
		i++;
	}
}

char	*join_nums(int ac, char **av)
{
	char	*nums;
	int		i;

	i = 1;
	nums = ft_strdup("");
	while (i < ac)
	{
		nums = ft_strjoin(nums, av[i]);
		if (!nums)
			force_exit();
		nums = ft_strjoin(nums, " ");
		if (!nums)
			force_exit();
		i++;
	}
	return (nums);
}

int	check_overflow(char *str)
{
	int	i;
	int	count;

	// printf("here?\n");
	i = 0;
	count = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i] && str[i] >= '0' && str[i++] <= '9')
		count++;
	if (count > 10)
		return (1);
	else
		return (0);
}

t_list	*init_nums(char **str)
{
	t_list		*list;
	long long	num;
	int			i;

	i = 0;
	num = ft_atoi(str[i++]);
	if (num > 2147483647 || num < -2147483648)
	{
		free_arr(str);
		force_exit();
	}
	list = ft_lstnew(num);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > 2147483647 || num < -2147483648 || check_overflow(str[i++]))
		{
			free_arr(str);
			ft_lstclear(&list);
			force_exit();
		}
		ft_lstadd_back(&list, ft_lstnew((int)num));
	}
	return (list);
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
	bring_min_top(a);
}
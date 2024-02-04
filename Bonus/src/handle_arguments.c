/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:08:57 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/04 18:20:26 by aaghla           ###   ########.fr       */
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
		while (arr[i][j])
		{
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
				force_exit();
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
		nums = ft_strjoin(nums, " ");
		i++;
	}
	return (nums);
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
		num = ft_atoi(str[i++]);
		if (num > 2147483647 || num < -2147483648)
		{
			free_arr(str);
			ft_lstclear(&list);
			force_exit();
		}
		ft_lstadd_back(&list, ft_lstnew((int)num));
	}
	return (list);
}
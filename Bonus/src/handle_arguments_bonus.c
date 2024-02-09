/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:08:57 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/09 17:59:22 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
	list = NULL;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > 2147483647 || num < -2147483648 || check_overflow(str[i++]))
		{
			free_arr(str);
			ft_lstclear(&list);
			force_exit();
		}
		if (ft_lstadd_back(&list, ft_lstnew((int)num)))
		{
			free_arr(str);
			ft_lstclear(&list);
			force_exit();
		}
	}
	return (list);
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

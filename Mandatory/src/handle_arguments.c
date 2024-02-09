/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:08:57 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/09 16:02:55 by aaghla           ###   ########.fr       */
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

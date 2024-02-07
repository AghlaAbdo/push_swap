/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:28:36 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/07 16:44:33 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	f(void)
{
	system("leaks checker");
}

static void	check_intruction(t_list **a, t_list **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else
		force_exit();
}

void	its_ko(t_list **stack)
{
	ft_lstclear(stack);
	ft_putstr_fd("KO\n", 1);
	exit(0);
}

static void	validate_args(int ac, char **av)
{
	if (ac == 1)
		exit(0);
	if (!av[1][0] || (!av[1][1] && !(av[1][0] >= '0' && av[1][0] <= '9'))
		|| check_overflow(av[1]))
		force_exit();
}

int	main(int ac, char **av)
{
	char	*str;
	t_list	*a;
	t_list	*b;

	// atexit(f);
	a = NULL;
	b = NULL;
	validate_args(ac, av);
	a = handle_args(ac, av);
	check_stack(a);
	str = get_next_line(0);
	if (str)
		check_intruction(&a, &b, str);
	while (str)
	{
		free(str);
		str = get_next_line(0);
		if (str)
			check_intruction(&a, &b, str);
	}
	if (b)
		its_ko(&a);
	check_if_sorted(&a);
	ft_lstclear(&a);
	return (0);
}

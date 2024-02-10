/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:28:36 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/10 10:17:39 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	f(void)
{
	system("leaks checker");
}

void	clear_stacks_exit(t_list **a, t_list **b, char *inst)
{
	free(inst);
	ft_lstclear(a);
	ft_lstclear(b);
	force_exit();
}

static void	check_intruction(t_list **a, t_list **b, char *inst)
{
	if (!ft_strcmp(inst, "sa\n"))
		sa(a);
	else if (!ft_strcmp(inst, "sb\n"))
		sb(b);
	else if (!ft_strcmp(inst, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(inst, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(inst, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(inst, "ra\n"))
		ra(a);
	else if (!ft_strcmp(inst, "rb\n"))
		rb(b);
	else if (!ft_strcmp(inst, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(inst, "rra\n"))
		rra(a);
	else if (!ft_strcmp(inst, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(inst, "rrr\n"))
		rrr(a, b);
	else
		clear_stacks_exit(a, b, inst);
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

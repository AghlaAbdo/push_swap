/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:41:39 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/10 10:17:29 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	check_stack(t_list *a)
{
	if (check_for_dup(a))
	{
		ft_lstclear(&a);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

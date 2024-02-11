/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:42:27 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/10 10:48:41 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <limits.h>

# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	int				num;
	int				index;
	int				cost;
	int				is_above;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list	*handle_args(int ac, char **av);
void	check_valid_nums(char **arr);
char	*join_nums(int ac, char **av);
void	free_arr(char **str);
void	force_exit(void);
int		check_overflow(char *str);
t_list	*init_nums(char **str);
int		check_for_dup(t_list *stack);
void	check_if_sorted(t_list **stack);
void	check_stack(t_list *a);
void	bring_to_top(t_list **stack, t_list *cheap, char c);
void	bring_min_top(t_list **a);
void	push_to_b(t_list **a, t_list **b);
void	push_to_a(t_list **a, t_list **b);
void	three_sort(t_list **a);
void	set_index(t_list *stack);
t_list	*find_max(t_list *stack);
t_list	*find_min(t_list *stack);
void	cost_calc(t_list *a, t_list *b);
t_list	*get_cheap(t_list *stack);
void	its_ko(t_list **a, t_list **b);
t_list	*ft_lstnew(int num);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
int		ft_lstadd_back(t_list **lst, t_list *new);
void	rotate(t_list **a, t_list **b, t_list *cheap);
void	rev_rotate(t_list **a, t_list **b, t_list *cheap);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

#endif
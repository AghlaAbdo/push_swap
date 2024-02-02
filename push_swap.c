/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:28:36 by aaghla            #+#    #+#             */
/*   Updated: 2024/02/02 22:39:11 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newnode(int num)
{
	t_list			*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->num = num;
	head->next = NULL;
	head->prev = NULL;
	return (head);
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
	t_list	*list;
	int		num;
	int		i;

	i = 0;
	num = ft_atoi(str[i++]);
	list = ft_lstnew(num);
	while (str[i])
	{
		num = ft_atoi(str[i++]);
		ft_lstadd_back(&list, ft_lstnew(num));
	}
	return (list);
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

void	f(void)
{
	system("leaks push_swap");
}

void	set_index(t_list *stack)
{
	int	i;
	int	mid;
	
	if (!stack)
		return ;
	i = 0;
	mid = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i > mid)
			stack->is_above = TRUE;
		else
			stack->is_above = FALSE;
		stack = stack->next;
	}
}

t_list	*find_max(t_list *stack)
{
	t_list	*max;
	int		n;

	n = stack->num;
	max = stack;
	while (stack)
	{
		if (stack->num > n)
		{
			n = stack->num;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

void	set_target_a(t_list *a, t_list *b)
{
	t_list		*target;
	t_list		*current_b;
	long long	match;

	while (a)
	{
		match = LLONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num && current_b->num > match)
			{
				match = current_b->num;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match == LLONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

t_list	*find_min(t_list *stack)
{
	t_list	*min;
	int		n;

	n = stack->num;
	min = stack;
	while (stack)
	{
		if (stack->num < n)
		{
			n = stack->num;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	set_target_b(t_list *a, t_list *b)
{
	t_list		*target;
	t_list		*current_a;
	long long	match;

	while (b)
	{
		match = LLONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < match)
			{
				match = current_a->num;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (match == LLONG_MAX)
		{
			b->target = find_min(a);
			printf("targer of b n: %d = %d in a\n", b->num, b->target->num);
		}
		else
		{
			b->target = target;
			printf("targer of b n: %d = %d in a\n", b->num, b->target->num);
		}
		b = b->next;
	}
}

void    cost_calc(t_list *a, t_list *b)
{
    int a_len;
    int b_len;
    
    a_len = ft_lstsize(a);
    b_len = ft_lstsize(b);
    while (a)
    {
        a->cost = a->index;
		if (!(a->is_above))
			a->cost = a_len - a->index;
		if (a->target->is_above)
			a->cost += a->target->index;
		else
			a->cost += b_len - a->target->index;
		a = a->next;
    }
}

t_list	*get_cheap(t_list *stack)
{
	t_list		*cheap;
	long long	n;

	n = LLONG_MAX;
	while (stack)
	{
		if (stack->num < n)
		{
			cheap = stack;
			n = stack->num;
		}
		stack = stack->next;
	}
	return (cheap);
}


void	rotate(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap && *b != cheap->target)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

void	rev_rotate(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap && *b != cheap->target)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	bring_to_top(t_list **stack, t_list *cheap, char c)
{
	t_list	*temp;
	
	temp = *stack;
	while ((*stack)->num != cheap->num)
	{
		printf("stack n = %d\ncheap n = %d\n", (*stack)->num, cheap->num);
		if (c == 'a')
		{
			if (cheap->is_above)
				ra(stack);
			else
			{
				while (temp)
				{
					printf("| %d |\n", temp->num);
					temp = temp->next;
				}
				for(int i = 0; i < 20; i++)
				{
					printf("| a = %d |\n", (*stack)->num);
					rra(stack);
				}
				printf("target n = %d\n", cheap->num);
				return ;
			}
		}
		else if (c == 'b')
		{
			if (cheap->is_above)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	push_to_b(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = get_cheap(*a);
	if (cheap->is_above && cheap->target->is_above)
		rotate(a, b, cheap);
	else if (!(cheap->is_above) && !(cheap->target->is_above))
		rev_rotate(a, b, cheap);
	bring_to_top(a, cheap, 'a');
	bring_to_top(b, cheap->target, 'b');
	pb(a, b);
}

void	push_to_a(t_list **a, t_list **b)
{
	bring_to_top(a, (*b)->target, 'a');
	pa(a, b);
}

void	three_sort(t_list **a)
{
	t_list	*max;
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		temp = temp->next;
	}
	max = find_max(*a);
	if (*a == max)
		ra(a);
	 if ((*a)->next == max)
	{
		rra(a);
	}
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	bring_min_top(t_list **a)
{
	t_list *min;
	
	min = find_min(*a);
	while (*a != min)
	{
		if (min->is_above)
			ra(a);
		else
			rra(a);
	}
}

void	init_stack(t_list **a, t_list **b)
{
	int	count;

	count = ft_lstsize(*a);
	if (count-- > 3)
	{
		pb(a, b);
		
	}
	if (count-- > 3)
		pb(a, b);
	while (count-- > 3)
	{
		set_index(*a);
		set_index(*b);
		set_target_a(*a, *b);
		cost_calc(*a, *b);
		push_to_b(a, b);
	}
	three_sort(a);
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_target_b(*a, *b);
		push_to_a(a, b);
	}
	set_index(*a);
	bring_min_top(a);
}

int	main(int ac, char **av)
{
	char	**str_nums;
	char	*str;
	t_list	*nums;
	t_list	*stack_b;
	t_list *temp;

	atexit(f);
	printf("7 / 2 = %d\n", 7 /2);
	stack_b = NULL;
	if (ac == 1)
		return (0);
	str = join_nums(ac, av);
	str_nums = ft_split(str, ' ');
	free(str);
	nums = init_nums(str_nums);
	init_stack(&nums, &stack_b);
	temp = nums;
	while (nums)
	{
		printf("%d\n", nums->num);
		nums = nums->next;
	}




	free_arr(str_nums);
	ft_lstclear(&temp);
	ft_lstclear(&stack_b);

}
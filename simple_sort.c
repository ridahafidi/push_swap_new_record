/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:44:47 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/09 04:06:12 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_val(t_list *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static int	get_index(t_list *stack, long min_val)
{
	int	i;

	i = 0;
	while (stack->value != min_val)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	min_up(t_list **stack_a, int stack_size, int min_index,
		t_list **stack_b)
{
	if (min_index <= (stack_size / 2))
	{
		while (min_index > 0)
		{
			(rotate(stack_a), ft_putstr_fd("ra\n", 1));
			min_index--;
		}
	}
	else
	{
		min_index = stack_size - min_index;
		while (min_index > 0)
		{
			(reverse_rotate(stack_a), ft_putstr_fd("rra\n", 1));
			min_index--;
		}
	}
	(push(stack_a, stack_b), ft_putstr_fd("pb\n", 1));
}

static void	get_min_to_top_and_push(t_list **stack_a, t_list **stack_b,
		int min_index)
{
	int	stack_size;
	int	max_index;

	stack_size = get_stack_size(*stack_a);
	if (stack_size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			(swap(stack_a), ft_putstr_fd("sa\n", 1));
	}
	if (stack_size == 3)
	{
		max_index = fetch_max_index(*stack_a);
		if (max_index == 0)
			(rotate(stack_a), ft_putstr_fd("ra\n", 1));
		else if (max_index == 1)
			(reverse_rotate(stack_a), ft_putstr_fd("rra\n", 1));
		if ((*stack_a)->value > (*stack_a)->next->value)
			(swap(stack_a), ft_putstr_fd("sa\n", 1));
	}
	if (stack_size > 3)
		min_up(stack_a, stack_size, min_index, stack_b);
}

void	simple_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		min_index;
	long	min_val;

	stack_b = NULL;
	while (get_stack_size(*stack_a) >= 2 && check_sorted_stack(*stack_a))
	{
		min_val = get_min_val(*stack_a);
		min_index = get_index(*stack_a, min_val);
		get_min_to_top_and_push(stack_a, &stack_b, min_index);
	}
	while (!empty_stack(stack_b))
		(push(&stack_b, stack_a), ft_putstr_fd("pa\n", 1));
}

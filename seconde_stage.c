/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seconde_stage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:54:49 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 02:14:03 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_list *stack, long *max_val)
{
	int	i;
	int	max_index;

	i = 0;
	max_index = 0;
	while (stack)
	{
		if (stack->value > *max_val)
		{
			*max_val = stack->value;
			max_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_index);
}

static void	get_max_to_top(int *max_index, t_list **stack_b, int size)
{
	if (*max_index <= size / 2)
	{
		while (*max_index > 0)
		{
			(rotate(stack_b), ft_putstr_fd("rb\n", 1));
			*max_index -= 1;
		}
	}
	else
	{
		*max_index = size - *max_index;
		while (*max_index > 0)
		{
			(reverse_rotate(stack_b), ft_putstr_fd("rrb\n", 1));
			*max_index -= 1;
		}
	}
}

void	seconde_stage(t_list **stack_a, t_list **stack_b)
{
	int		max_index;
	long	max_value;
	int		size;

	while (!empty_stack(*stack_b))
	{
		max_value = (*stack_b)->value;
		max_index = get_max_index(*stack_b, &max_value);
		size = get_stack_size(*stack_b);
		get_max_to_top(&max_index, stack_b, size);
		(push(stack_b, stack_a), ft_putstr_fd("pa\n", 1));
	}
}

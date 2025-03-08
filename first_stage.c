/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_stage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:53:46 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 01:49:20 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_val_index_in_arr(long val, t_var *var, int *arr)
{
	int	index;

	index = 0;
	while (index < var->end)
	{
		if (val == arr[index])
			return (index);
		index++;
	}
	return (-1);
}

static void	update(t_var *var, int stack_a_size)
{
	if (var->offset < stack_a_size - 1)
		var->offset++;
	if (var->start < var->offset - 1)
		var->start++;
}

void	first_stage(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
	int	val_index;
	int	stack_a_size;

	var->start = 0;
	stack_a_size = get_stack_size(*stack_a);
	while (!empty_stack(*stack_a))
	{
		val_index = get_val_index_in_arr((*stack_a)->value, var, arr);
		if (val_index < var->start)
		{
			update(var, stack_a_size);
			(push(stack_a, stack_b), ft_putstr_fd("pb\n", 1));
		}
		else if (val_index <= var->offset)
		{
			(push(stack_a, stack_b), ft_putstr_fd("pb\n", 1));
			if (get_stack_size(*stack_b) > 1)
				(rotate(stack_b), ft_putstr_fd("rb\n", 1));
			update(var, stack_a_size);
		}
		else
			(rotate(stack_a), ft_putstr_fd("ra\n", 1));
	}
}

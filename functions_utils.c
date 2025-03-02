/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:04:03 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/02 00:55:38 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_list *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

int	get_min_value_index(t_list *stack)
{
	int	index;
	int	i;
	int	min;

	index = 0;
	i = 0;
	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
		{
			min = stack->value;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int	empty_stack(t_list *stack)
{
	if (!stack)
		return (1);
	return (0);
}
void	print_stack(t_list *stack)
{
	while(stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:04:03 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/05 01:19:21 by rhafidi          ###   ########.fr       */
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
int	check_sorted_stack(t_list *stack)
{
	int	prev_val;

	prev_val = stack->value;
	while (stack->next)
	{
		stack = stack->next;
		if (prev_val < stack->value)
			prev_val = stack->value;
		else
			return (-1);
	}
	return (0);
}
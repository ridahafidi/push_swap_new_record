/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 00:42:39 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 01:55:19 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_sorted_array(t_list *stack_a, int stack_len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * stack_len);
	if (!arr)
		return (NULL);
	while (i < stack_len)
	{
		arr[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
	quick_sort(arr, 0, stack_len - 1);
	return (arr);
}

static void	collect_var(t_var *var)
{
	if (var->size <= 150)
		var->div = 6;
	else
		var->div = 14;
	var->mid = (var->size / 2) - 1;
	var->offset = var->size / var->div;
	var->start = 0;
	var->end = var->size;
	var->count_bottom = 0;
	var->expected_max = 0;
	var->max_index_arr = 0;
}

static void	chunk_sort(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
	collect_var(var);
	first_stage(stack_a, stack_b, var, arr);
	seconde_stage(stack_a, stack_b);
}

void	sort_stack(t_list **stack_a)
{
	t_list	*stack_b;
	t_var	var;
	int		*sorted_array;

	stack_b = NULL;
	var.size = get_stack_size(*stack_a);
	sorted_array = create_sorted_array(*stack_a, var.size);
	if (!sorted_array || !var.size)
		return ;
	chunk_sort(stack_a, &stack_b, &var, sorted_array);
	free(sorted_array);
}

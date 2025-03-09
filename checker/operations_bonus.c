/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:30:21 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/09 03:48:57 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_list **stack)
{
	t_list	*tmp_first;

	if (get_stack_size(*stack) > 1)
	{
		tmp_first = *stack;
		*stack = (*stack)->next;
		tmp_first->next = (*stack)->next;
		(*stack)->next = tmp_first;
	}
}

void	ss(t_list **stack1, t_list **stack2)
{
	swap(stack1);
	swap(stack2);
}

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*tmp_stack1;

	if (get_stack_size(*stack1) > 0)
	{
		if (!(*stack1)->next)
		{
			tmp_stack1 = *stack1;
			*stack1 = NULL;
			tmp_stack1->next = *stack2;
			(*stack2) = tmp_stack1;
			return ;
		}
		tmp_stack1 = *stack1;
		*stack1 = (*stack1)->next;
		tmp_stack1->next = *stack2;
		(*stack2) = tmp_stack1;
	}
}

void	rotate(t_list **stack)
{
	t_list	*tmp_stack;
	t_list	*last_node;

	if (get_stack_size(*stack) > 1)
	{
		tmp_stack = *stack;
		last_node = *stack;
		*stack = (*stack)->next;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = tmp_stack;
		tmp_stack->next = NULL;
	}
}

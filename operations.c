/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:26:56 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 00:47:05 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp_first;

	tmp_first = *stack;
	*stack = (*stack)->next;
	tmp_first->next = (*stack)->next;
	(*stack)->next = tmp_first;
}

void	ss(t_list **stack1, t_list **stack2)
{
	swap(stack1);
	swap(stack2);
}

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*tmp_stack1;

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

void	rotate(t_list **stack)
{
	t_list	*tmp_stack;
	t_list	*last_node;

	tmp_stack = *stack;
	last_node = *stack;
	*stack = (*stack)->next;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = tmp_stack;
	tmp_stack->next = NULL;
}

void	rr(t_list **stack1, t_list **stack2)
{
	rotate(stack1);
	rotate(stack2);
}

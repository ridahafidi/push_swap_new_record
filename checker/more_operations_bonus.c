/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:48:09 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/09 03:49:29 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rr(t_list **stack1, t_list **stack2)
{
	rotate(stack1);
	rotate(stack2);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (get_stack_size(*stack) > 1)
	{
		before_last = *stack;
		while (before_last->next->next)
			before_last = before_last->next;
		last = before_last->next;
		last->next = *stack;
		before_last->next = NULL;
		*stack = last;
	}
}

void	rrr(t_list **stack1, t_list **stack2)
{
	reverse_rotate(stack1);
	reverse_rotate(stack2);
}

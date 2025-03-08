/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:59:03 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/07 23:59:36 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	last->next = *stack;
	before_last->next = NULL;
	*stack = last;
}

void	rrr(t_list **stack1, t_list **stack2)
{
	reverse_rotate(stack1);
	reverse_rotate(stack2);
}

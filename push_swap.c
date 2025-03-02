/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:04:55 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/02 01:00:15 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac > 1)
	{
		stack_a = fill_stack_a(av);
		if (!stack_a)
			return (0);
		sort_stack(&stack_a);
		while(stack_a)
		{
			printf("%d\n", stack_a->value);
			stack_a = stack_a->next;
		}
	}
	else
		ft_putstr_fd("wrong usage\n", 2);
	return (0);
}

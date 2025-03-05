/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:04:55 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/05 02:21:26 by rhafidi          ###   ########.fr       */
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
		if (!check_sorted_stack(stack_a))
		{
			printf("its already sorted dumbass\n");
			free(stack_a);
			exit(1);
		}
		else
			sort_stack(&stack_a);
		// print_stack(stack_a);
		//check for the stack given if sroted exit if not chunk sort it or simple sort 
		//fix a simple sort function for size < 10 args
		//check pasrsing
		//check leaks
	}
	else
		ft_putstr_fd("wrong usage\n", 2);
	return (0);
}

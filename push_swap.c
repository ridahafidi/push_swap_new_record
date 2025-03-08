/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:04:55 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 01:45:37 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		stack_size;

	if (ac > 1)
	{
		stack_a = fill_stack_a(av);
		if (!stack_a)
			return (0);
		stack_size = get_stack_size(stack_a);
		if (!check_sorted_stack(stack_a))
		{
			ft_putstr_fd("give a SEQUENCE of UNSORTED numbers\n",
				2);
			ft_lstclear(&stack_a);
			exit(1);
		}
		if (stack_size <= 10)
			simple_sort(&stack_a);
		else
			sort_stack(&stack_a);
		ft_lstclear(&stack_a);
	}
	else
		ft_putstr_fd("ERROR: wrong usage\n", 2);
	return (0);
}

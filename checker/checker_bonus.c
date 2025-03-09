/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:03:47 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/09 04:12:24 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_sorted_stack(t_list *stack)
{
	int	prev_val;

	if (!stack)
		return (-1);
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

void	exit_and_clear(t_list **stack_a, t_list **stack_b, char *operation)
{
	ft_putstr_fd("Error\n", 2);
	free(operation);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	exit(1);
}

void	exec_operations(t_list **stack_a, t_list **stack_b, int operation_len,
		char *operation)
{
	if (!ft_strncmp(operation, "pa", operation_len))
		push(stack_b, stack_a);
	else if (!ft_strncmp(operation, "pb", operation_len))
		push(stack_a, stack_b);
	else if (!ft_strncmp(operation, "sa", operation_len))
		swap(stack_a);
	else if (!ft_strncmp(operation, "sb", operation_len))
		swap(stack_b);
	else if (!ft_strncmp(operation, "ss", operation_len))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(operation, "ra", operation_len))
		rotate(stack_a);
	else if (!ft_strncmp(operation, "rb", operation_len))
		rotate(stack_b);
	else if (!ft_strncmp(operation, "rr", operation_len))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(operation, "rra", operation_len))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(operation, "rrb", operation_len))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(operation, "rrr", operation_len))
		rrr(stack_a, stack_b);
	else
		exit_and_clear(stack_a, stack_b, operation);
}

void	read_and_execute(t_list **stack_a, t_list **stack_b)
{
	char	*operation;
	int		operation_len;

	operation = get_next_line(0);
	while (operation)
	{
		operation_len = ft_strlen(operation) - 1;
		if (operation_len == 1)
			exit_and_clear(stack_a, stack_b, operation);
		exec_operations(stack_a, stack_b, operation_len, operation);
		free(operation);
		operation = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac > 1)
	{
		stack_a = fill_stack_a(av);
		stack_b = NULL;
		if (!stack_a)
			return (0);
		read_and_execute(&stack_a, &stack_b);
		if (!check_sorted_stack(stack_a) && !stack_b)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
	}
	else
		exit(0);
	return (0);
}

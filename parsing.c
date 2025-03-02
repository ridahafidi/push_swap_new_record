/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:04:05 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/02 01:00:44 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (is_digit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

static void	handle_parsing(t_list **stack, char *str)
{
	char	**parsed_str;
	int		i;

	i = 0;
	parsed_str = ft_split(str, ' ');
	while (parsed_str[i])
	{
		if (!valid_nbr(parsed_str[i]))
		{
			if (*stack)
				ft_lstadd_front(stack, ft_lstnew(ft_atoi(parsed_str[i])),
					parsed_str);
			if (!*stack)
				*stack = ft_lstnew(ft_atoi(parsed_str[i]));
		}
		else
		{
			ft_lstclear(stack);
			free_array(parsed_str);
			ft_putstr_fd("ERROR: There is an invalid argument\n", 2);
			exit(0);
		}
		i++;
	}
	free_array(parsed_str);
}

t_list	*fill_stack_a(char **av)
{
	int		i;
	t_list	*stack;

	stack = NULL;
	i = 1;
	while (av[i])
	{
		if (!valid_nbr(av[i]))
		{
			if (stack)
				ft_lstadd_front(&stack, ft_lstnew(ft_atoi(av[i])), NULL);
			if (!stack)
				stack = ft_lstnew(ft_atoi(av[i]));
		}
		else
			handle_parsing(&stack, av[i]);
		i++;
	}
	return (stack);
}

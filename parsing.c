/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:04:05 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 02:32:15 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_max_min(char *str)
{
	long	max_int;
	int		nbr_len;
	long	min_int;
	long	number;

	nbr_len = 0;
	while(str[nbr_len])
		nbr_len++;
	max_int = 2147483647;
	min_int = -2147483648;
	number = ft_atoi(str);
	if (number > max_int || number < min_int || nbr_len > 13)
		return (1);
	else
		return (0);
}

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
	if (handle_max_min(str))
		return (1);
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
				ft_lstadd_back(stack, ft_lstnew(ft_atoi(parsed_str[i])),
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
				ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i])), NULL);
			if (!stack)
				stack = ft_lstnew(ft_atoi(av[i]));
		}
		else
			handle_parsing(&stack, av[i]);
		i++;
	}
	return (stack);
}

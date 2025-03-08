/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:10:08 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 04:15:21 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list	*ft_lstnew(int content)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (root == NULL)
		return (NULL);
	root->value = content;
	root->next = NULL;
	return (root);
}

static void	clear_up(t_list **lst, t_list *new)
{
	ft_lstclear(lst);
	free(new);
}

void	check_duplicated(t_list **lst, t_list *new, char **parsed_str)
{
	t_list	*tmp_lst;

	tmp_lst = *lst;
	while (tmp_lst)
	{
		if (tmp_lst->value == new->value)
		{
			if (!parsed_str)
			{
				clear_up(lst, new);
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			else
			{
				clear_up(lst, new);
				free_array(parsed_str);
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
		}
		tmp_lst = tmp_lst->next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new, char **parsed_str)
{
	t_list	*tmp_lst;

	tmp_lst = *lst;
	check_duplicated(lst, new, parsed_str);
	while (tmp_lst->next)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = new;
	new->next = NULL;
}

void	ft_lstclear(t_list **lst)
{
	if (!(*lst))
		return ;
	if (*lst)
		ft_lstclear(&(*lst)->next);
	(*lst)->value = 0;
	free(*lst);
	*lst = NULL;
}

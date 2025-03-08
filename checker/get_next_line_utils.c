/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:03:47 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 06:01:26 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_data	*findlastnode(t_data *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	new_line(t_data *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->save[i] && i < BUFFER_SIZE)
		{
			if (list->save[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

size_t	length_to_newline(t_data *list)
{
	int		i;
	size_t	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->save[i] && i < BUFFER_SIZE)
		{
			if (list->save[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	copy_the_line(char *line, t_data *list)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->save[i] && list->save[i] != '\n')
		{
			line[j] = list->save[i];
			i++;
			j++;
		}
		if (list->save[i] == '\n')
		{
			line[j] = list->save[i];
			break ;
		}
		list = list->next;
	}
}

void	free_malloc(t_data **list, t_data *newnode, char *buff)
{
	t_data	*tmp;

	if (!(*list))
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->save);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (newnode->save[0])
		*list = newnode;
	else
	{
		free(buff);
		free(newnode);
	}
}

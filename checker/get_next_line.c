/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:03:40 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/08 06:02:00 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	append_to_list(t_data **list, char *buff)
{
	t_data	*new_node;
	t_data	*last_node;

	last_node = findlastnode(*list);
	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->save = buff;
	new_node->next = NULL;
}

void	create_list(t_data **list, int fd)
{
	char	*buffer;
	ssize_t	readbytes;

	while (!new_line(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[readbytes] = '\0';
		append_to_list(list, buffer);
	}
}

char	*get_line(t_data **list)
{
	size_t	line_length;
	char	*line;

	line_length = length_to_newline(*list);
	line = malloc(sizeof(char) * (line_length + 1));
	if (!line)
		return (NULL);
	line[line_length] = '\0';
	copy_the_line(line, *list);
	return (line);
}

void	trimlist(t_data **list)
{
	t_data	*lastnode;
	t_data	*newnode;
	char	*buff;
	int		i;
	int		j;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	newnode = malloc(sizeof(t_data));
	if (!buff || !newnode)
		return ;
	lastnode = findlastnode(*list);
	i = 0;
	j = 0;
	while (lastnode->save[i] && lastnode->save[i] != '\n')
		i++;
	i++;
	while (lastnode->save[i])
		buff[j++] = lastnode->save[i++];
	buff[j] = '\0';
	newnode->save = buff;
	newnode->next = NULL;
	free_malloc(list, newnode, buff);
}

char	*get_next_line(int fd)
{
	static t_data	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	line = get_line(&list);
	trimlist(&list);
	return (line);
}

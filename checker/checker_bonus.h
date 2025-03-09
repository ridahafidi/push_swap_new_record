/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:49:11 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/09 00:13:12 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	long			value;
	struct s_list	*next;
}					t_list;

typedef struct v_list
{
	char			*save;
	struct v_list	*next;
}					t_data;

t_list				*fill_stack_a(char **av);
long				ft_atoi(const char *nptr);
void				ft_putstr_fd(char *str, int fd);
int					is_digit(char c);
int					is_space(char c);
int					ft_strlen(char *str);
void				ft_lstadd_back(t_list **lst, t_list *new,
						char **parsed_str);
char				**ft_split(const char *s, char c);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(int content);
void				free_array(char **str);
void				swap(t_list **stack);
void				ss(t_list **stack1, t_list **stack2);
void				push(t_list **stack1, t_list **stack2);
void				rotate(t_list **stack);
void				rr(t_list **stack1, t_list **stack2);
void				reverse_rotate(t_list **stack);
void				rrr(t_list **stack1, t_list **stack2);
int					new_line(t_data *list);
void				free_malloc(t_data **list, t_data *newnode, char *buff);
t_data				*findlastnode(t_data *list);
size_t				length_to_newline(t_data *list);
void				copy_the_line(char *line, t_data *list);
char				*get_next_line(int fd);
int					is_newline(char c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
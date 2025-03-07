/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:04:58 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/07 22:44:38 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_var
{
	int	size;
	int	div;
	int	offset;
	int	start;
	int	end;
	int	mid;
	int	count_bottom;
	int	expected_max;
	int	max_index_arr;
}				t_var;

int					ft_atoi(const char *nptr);
void				ft_lstadd_back(t_list **lst, t_list *new,
						char **parsed_str);
t_list				*ft_lstnew(int content);
void				ft_putstr_fd(char *str, int fd);
void				ft_lstclear(t_list **lst);
char				**ft_split(const char *s, char c);
int					is_digit(char c);
int					is_space(char c);
int					ft_strlen(char *str);
void				free_array(char **str);
t_list				*fill_stack_a(char **av);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				push(t_list **stack1, t_list **stack2);
void				ss(t_list **stack1, t_list **stack2);
void				rr(t_list **stack1, t_list **stack2);
void				reverse_rotate(t_list **stack);
int					get_stack_size(t_list *stack);
int					empty_stack(t_list *stack);
void				quick_sort(int *arr, int start, int end);
void 				sort_stack(t_list **stack_a);
void	print_stack(t_list *stack);
int	check_sorted_stack(t_list *stack);
void				simple_sort(t_list **stack_a);
#endif
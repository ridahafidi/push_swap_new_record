/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 00:42:39 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/05 02:14:26 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *create_sorted_array(t_list *stack_a, int stack_len)
{
    int *arr;
    int i;
    
    i = 0;
    arr = malloc(sizeof(int) * stack_len);
    if (!arr)
        return (NULL);
    while (i < stack_len)
    {
        arr[i] = stack_a->value;
        stack_a = stack_a->next;
        i++;
    }
    quick_sort(arr, 0, stack_len - 1);
    return (arr);
}

void   collect_var(t_var *var)
{
    if (var->size <= 150)
        var->div = 6;
    else
        var->div = 14;
    var->mid = (var->size / 2) - 1;
    var->offset = var->size / var->div;
    var->start = 0;
    var->end = var->size;
    var->count_bottom = 0;
    var->expected_max = 0;
    var->max_index_arr = 0;
}

int get_val_index_in_arr(int val, t_var *var, int *arr)
{
    int index;

    index = 0;
    while (index < var->end)
    {
        if (val == arr[index])
            return (index);
        index++;
    }
    return (-1);
}

void    update(t_var *var, int stack_a_size)
{
    if (var->offset < stack_a_size - 1)
        var->offset++;
    if (var->start < var->offset - 1)
        var->start++;
}

void    first_stage(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    int val_index;
    int stack_a_size;
    
    var->start = 0;
    stack_a_size = get_stack_size(*stack_a);
    while(!empty_stack(*stack_a))
    {
        val_index = get_val_index_in_arr((*stack_a)->value, var, arr);
        if (val_index < var->start)
        {
            update(var, stack_a_size);
            (push(stack_a, stack_b), ft_putstr_fd("pb\n", 1));
        }
        else if (val_index <= var->offset)
        {
            (push(stack_a, stack_b), ft_putstr_fd("pb\n", 1));
            if (get_stack_size(*stack_b) > 1)
                (rotate(stack_b), ft_putstr_fd("rb\n", 1));
            update(var, stack_a_size);
        }
        else
            (rotate(stack_a), ft_putstr_fd("ra\n", 1));
    }
}

// line between first stage and seconde stage code

int get_max_index(t_list *stack, int *max_val)
{
    int i;
    int max_index;

    i = 0;
    max_index = 0;
    while (stack)
    {
        if (stack->value > *max_val)
        {
            *max_val = stack->value;
            max_index = i;
        }
        stack = stack->next;
        i++;
    }
    return (max_index);
}

void    get_max_to_top(int *max_index, t_list **stack_b, int size)
{
     if (*max_index <= size / 2)
    {
        while (*max_index > 0)
        {
            (rotate(stack_b), ft_putstr_fd("rb\n", 1));
            *max_index -= 1;
        }
    }
    else
    {
        *max_index = size - *max_index;
        while (*max_index > 0)
        {
            (reverse_rotate(stack_b), ft_putstr_fd("rrb\n", 1));
            *max_index -= 1;
        }
    }
}
void    seconde_stage(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    int max_index;
    int max_value;
    int size;
    
    while(!empty_stack(*stack_b))
    {
        max_value = (*stack_b)->value;
        max_index = get_max_index(*stack_b, &max_value);
        size = get_stack_size(*stack_b);
        get_max_to_top(&max_index, stack_b, size);
        (push(stack_b, stack_a), ft_putstr_fd("pa\n", 1));
    }
}

void  chunk_sort(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    collect_var(var);
    first_stage(stack_a, stack_b, var, arr);
    seconde_stage(stack_a, stack_b, var, arr);
}

void sort_stack(t_list **stack_a)
{
    t_list  *stack_b;
    t_var   var;
    int     *sorted_array;

    stack_b = NULL;
    var.size = get_stack_size(*stack_a);
    sorted_array = create_sorted_array(*stack_a, var.size);
    if (!sorted_array || !var.size)
        return ;
    chunk_sort(stack_a, &stack_b, &var, sorted_array);
    free(sorted_array);
}
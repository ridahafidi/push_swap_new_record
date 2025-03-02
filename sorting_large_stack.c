/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 00:42:39 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/02 01:02:29 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *create_sorted_array(t_list *stack_a, int stack_len)
{
    int *arr;
    int i;
    
    i = 0;
    arr = malloc(sizeof(int) * stack_len);
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
    var->div = var->size / 2;
    var->mid = (var->size / 2) - 1;
    var->offset = var->size / var->div;
    var->start = var->mid - var->offset;
    var->end = var->mid + var->offset;
    var->count_bottom = 0;
    var->expected_max = 0;
    var->max_index_arr = 0;
}

void    pb_and_check(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    push(stack_a, stack_b);
    if ((*stack_b)->next)
    {
        if ((*stack_b)->value < arr[var->mid])
            rotate(stack_b);
    }
}

void    look_top_in_range(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    int i;

    i = var->start;
    while (i <= var->end)
    {
        if (arr[i] == (*stack_a)->value)
            pb_and_check(stack_a, stack_b, var, arr);
        i++;
    }
}

void    get_value_to_top(t_list **stack_a, t_var *var, int *arr)
{
    int value_index;
    t_list  *tmp_stack_a;

    value_index = 0;
    tmp_stack_a = *stack_a;
    while (tmp_stack_a && tmp_stack_a->value != *arr)
    {
        value_index++;
        tmp_stack_a = tmp_stack_a->next;
    }
    if (value_index <= var->mid)
    {
        while ((*stack_a)->value != *arr)
            rotate(stack_a);   
    }
    else
    {
        while ((*stack_a)->value != *arr)
            reverse_rotate(stack_a);
    }
}

void    look_in_stack(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    t_list  *tmp_stack_a;
    int i;

    i = var->start;
    tmp_stack_a = *stack_a;
    while (i < var->end)
    {
        tmp_stack_a = *stack_a;
        while (tmp_stack_a)
        {
            if (tmp_stack_a->value == arr[i])
            {
                get_value_to_top(stack_a, var, &arr[i]);
                pb_and_check(stack_a, stack_b, var, arr);
            }
            tmp_stack_a = tmp_stack_a->next;
        }
        i++;
    }
}

t_var   *update_range(t_var *var)
{
    var->start = var->offset - var->start;
    if (var->start < 0)
        var->start = 0;
    var->end = var->offset + var->end;
    if (var->end >= var->size)
        var->end = var->size - 1;
    return (var);    
}

void    first_stage(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    if (empty_stack(*stack_a))
        return ;
    look_top_in_range(stack_a, stack_b, var, arr);
    look_in_stack(stack_a, stack_b, var, arr);
    first_stage(stack_a, stack_b, update_range(var), arr);
}

// line between first stage and seconde stage code

void    find_and_push(t_list **stack_a, t_list **stack_b, t_var *var)
{
    t_list *tmp_stack_b;
    int     i;

    i = 0;
    tmp_stack_b = *stack_b;
    while (tmp_stack_b->value != var->expected_max)
    {
        tmp_stack_b = tmp_stack_b->next;
        i++;
    }
    while ((*stack_b)->value != var->expected_max)
    {
        if (i <= var->mid)
            rotate(stack_b);
        else
            reverse_rotate(stack_b);
    }
    push(stack_b, stack_a);
}

int found_max(int expected_max, t_list *stack_b)
{
    while (stack_b)
    {
        if (expected_max == stack_b->value)
            return (0);
        stack_b = stack_b->next;
    }
    return (1);
}

void    no_max_stack_b(t_list **stack_a, t_var *var, int *arr)
{
    var->max_index_arr -= 1;
    var->expected_max = arr[var->max_index_arr];
    var->count_bottom -= 1;
    reverse_rotate(stack_a);
}

void    max_on_top_b(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    var->max_index_arr -= 1;
    var->expected_max = arr[var->max_index_arr];
    push(stack_b, stack_a);
}

int get_bottom_value(t_list *stack_a)
{
    while (stack_a->next)
        stack_a = stack_a->next;
    return (stack_a->value);
}

void    max_out_top(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    int bottom_a;
    
    bottom_a = get_bottom_value(*stack_a);
    if (!var->count_bottom)
    {
        push(stack_b, stack_a);
        rotate(stack_a);
        var->count_bottom += 1;
    }
    else
    {
        if (bottom_a < (*stack_b)->value)
            {
                push(stack_b, stack_a);
                rotate(stack_a);
                var->count_bottom += 1;
            }
        else
            {
                find_and_push(stack_a, stack_b, var);
                var->max_index_arr -= 1;
                var->expected_max = arr[var->max_index_arr];
            }
    }
}

void    seconde_stage(t_list **stack_a, t_list **stack_b, int *arr, t_var *var)
{
    var->max_index_arr = var->size - 1;
    var->expected_max = arr[var->max_index_arr];
    find_and_push(stack_a, stack_b, var);
    var->max_index_arr -= 1;
    var->expected_max = arr[var->max_index_arr];
    while(!empty_stack(*stack_b))
    {
        if (found_max(var->expected_max, *stack_b))
            no_max_stack_b(stack_a, var, arr);
        if (var->expected_max == (*stack_b)->value)
            max_on_top_b(stack_a, stack_b, var, arr);
        else
            max_out_top(stack_a, stack_b, var, arr);
    }
    while (var->count_bottom > 0)
    {
        reverse_rotate(stack_a);
        var->count_bottom--;
    }
}

void  chunk_sort(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    collect_var(var);
    first_stage(stack_a, stack_b, var, arr);
    seconde_stage(stack_a, stack_b, arr, var);
}

void sort_stack(t_list **stack_a)
{
    t_list  *stack_b;
    t_var   var;
    int     *sorted_array;

    stack_b = NULL;
    var.size = get_stack_size(*stack_a);
    sorted_array = create_sorted_array(*stack_a, var.size);
    chunk_sort(stack_a, &stack_b, &var, sorted_array);
    free(sorted_array);
}
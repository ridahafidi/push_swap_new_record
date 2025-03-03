/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 00:42:39 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/03 02:36:20 by rhafidi          ###   ########.fr       */
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
    var->div = 18;
    var->mid = (var->size / 2) - 1;
    var->offset = var->size / var->div;
    var->start = var->mid - var->offset;
    var->end = var->mid + var->offset;
    var->count_bottom = 0;
    var->expected_max = 0;
    var->max_index_arr = 0;
}


void   update_range(t_var *var)
{
    var->start = var->start - var->offset;
    if (var->start < 0)
        var->start = 0;
    var->end = var->offset + var->end;
    if (var->end >= var->size)
        var->end = var->size - 1;
}

void    push_b_and_rotate(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    if (!empty_stack(*stack_a))
    {
        (push(stack_a, stack_b), ft_putstr_fd("pb\n", 1));
        if ((*stack_b)->next)
        {
            if ((*stack_b)->value <= arr[var->mid])
                (rotate(stack_b), ft_putstr_fd("rb\n", 1));
        }
    }
}

void    look_top_in_range(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    int i;

    i = var->start;
    while(!empty_stack(*stack_a) && i <= var->end)
    {
        if ((*stack_a)->value == arr[i])
            push_b_and_rotate(stack_a, stack_b, var, arr);
        i++;
    }
}

int get_val_index(t_list *stack, int value)
{
    int val_i;

    val_i = 0;
    while(stack)
    {
        if (stack->value == value)
            return (val_i);
        val_i++;
        stack = stack->next;
    }
    return (-1);
}

void    get_it_top(t_list **stack_a, t_var *var, int *arr, int i)
{
    int value;
    int value_index;

    value = arr[i];
    value_index = get_val_index(*stack_a, value);
    if (value_index > -1)
    {
        if (value_index <= (get_stack_size(*stack_a) / 2))
            {
                while ((*stack_a)->value != value)
                    (rotate(stack_a), ft_putstr_fd("ra\n", 1));
            }
        else
            {
                while ((*stack_a)->value != value)
                    (reverse_rotate(stack_a), ft_putstr_fd("rra\n", 1));
            }
    }
}
void    look_in_stack(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    int i;
    t_list *tmp_stack_a;
    
    i = var->start;
    tmp_stack_a = *stack_a;
    while(tmp_stack_a)
    {
        i = 0;
        while(i <= var->end)
        {
            if (arr[i] == tmp_stack_a->value)
            {
                get_it_top(stack_a, var, arr, i);
                push_b_and_rotate(stack_a, stack_b, var ,arr);
            }
            i++;
        }
        if (!tmp_stack_a)
            break;
        tmp_stack_a = tmp_stack_a->next;
    }
}

void    first_stage(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    while(!empty_stack(*stack_a))
    {
        look_top_in_range(stack_a, stack_b, var, arr);
        look_in_stack(stack_a, stack_b, var, arr);
        update_range(var);
    }
}

// line between first stage and seconde stage code

void    get_max_to_top(t_list **stack_b, t_var *var, int max_val)
{
    int val_index;

    val_index = get_val_index(*stack_b, max_val);
    if (val_index > -1)
    {
        if (val_index <= (get_stack_size(*stack_b) / 2))
        {
            while ((*stack_b)->value != max_val)
                (rotate(stack_b), ft_putstr_fd("rb\n", 1));
        }
        else
        {
            while ((*stack_b)->value != max_val)
                (reverse_rotate(stack_b), ft_putstr_fd("rrb\n", 1));
        }
    }
    else
        return ;
}

void    find_max_push(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    int max_val;

    max_val = arr[var->size - 1];
    get_max_to_top(stack_b, var, max_val);
    push(stack_b, stack_a);
    var->max_index_arr = var->size - 2;
    var->expected_max = arr[var->max_index_arr];
    var->count_bottom = 0;
}

int found_max(t_list *stack_b, int max_val)
{
    while (stack_b)
    {
        if (stack_b->value == max_val)
            return (1);
        stack_b = stack_b->next;
    }
    return (0);
}

void    max_not_found(t_list **stack_a, t_var *var, int *arr)
{
    (reverse_rotate(stack_a), ft_putstr_fd("rra\n", 1));
    var->count_bottom -= 1;
    var->max_index_arr -= 1;
    var->expected_max = arr[var->max_index_arr];
}

void    max_in_top(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    if (!empty_stack(*stack_b))
    {
        (push(stack_b, stack_a), ft_putstr_fd("pa\n", 1));
        var->max_index_arr -= 1;
        var->expected_max = arr[var->max_index_arr];
    }
    else
        return ;
}

int get_bottom_val(t_list *stack)
{
    while (stack->next)
        stack = stack->next;
    return (stack->value);
}

void    count_not_zero(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    int bottom_val;

    bottom_val = get_bottom_val(*stack_a);
    if(bottom_val < (*stack_b)->value)
    {
        (push(stack_b, stack_a), ft_putstr_fd("pa\n", 1));
        (rotate(stack_a), ft_putstr_fd("ra\n", 1));
        var->count_bottom += 1;
    }
    else
    {
        get_max_to_top(stack_b, var, var->expected_max);
        (push(stack_b, stack_a), ft_putstr_fd("pa\n", 1));
        var->max_index_arr -= 1;
        var->expected_max = arr[var->max_index_arr];
    }
}

void    max_not_in_top(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    if (!empty_stack(*stack_b))
    {
        if (!var->count_bottom)
        {
            (push(stack_b, stack_a), ft_putstr_fd("pa\n", 1));
            (rotate(stack_a), ft_putstr_fd("ra\n", 1));
            var->count_bottom += 1;
        }
        else
            count_not_zero(stack_a, stack_b, var, arr);
    }
}

void    seconde_stage(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    find_max_push(stack_a, stack_b, var, arr);
    while (!empty_stack(*stack_b))
    {
        if (!found_max(*stack_b, arr[var->max_index_arr]))
            max_not_found(stack_a, var, arr);
        else
        {
            if (var->expected_max == (*stack_b)->value)
                max_in_top(stack_a, stack_b, var, arr);
            else
                max_not_in_top(stack_a, stack_b, var, arr);
        }
    }
    while (var->count_bottom > 0)
    {
        reverse_rotate(stack_a);
        var->count_bottom -= 1;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 00:42:39 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/01 02:03:21 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *create_stack_b(t_list *stack_a, int stack_len)
{
    int i;
    t_list *stack_b;

    i = 0;
    stack_b = NULL;
    while(i < stack_len)
    {
        if (stack_b)
            ft_lstadd_front(stack_b, malloc(sizeof(t_list)), NULL);
        if (!stack_b)
            stack_b = malloc(sizeof(t_list));
        i++;
    }
    return (stack_b);
}

int *create_sorted_array(t_list *stack_a, int stack_len)
{
    int arr[stack_len];
    int i;
    
    i = 0;
    while (i < stack_len)
    {
        arr[i] = stack_a->value;
        stack_a = stack_a->next;
        i++;
    }
    quick_sort(arr, 0, stack_len);
    return (arr);
}

t_var   *collect_var(t_var *var)
{
    var->div = var->size / 2;
    var->mid = (var->size / 2) - 1;
    var->offset = var->size / var->div;
    var->start = var->mid - var->offset;
    var->end = var->mid + var->offset;
    return (var);
}

// int    look_for_top_inrange(t_list *stack_a, int *arr, t_var *var)
// {
//     int i;

//     i = var->start;
//     while (i <= var->end)
//     {
//         if (arr[i] == stack_a->value)
//             return (1);
//         i++;
//     }
//     return (0);
// }

// void    top_out_range(t_list **stack_a, t_list **stack_b, int *arr, t_var *var)
// {
//     int i;
//     int val_index;
//     t_list *tmp_stack_a;

//     i = var->start;
//     val_index = 0;
//     tmp_stack_a = *stack_a;
//     while(tmp_stack_a)
//     {
//         if (arr[i] == tmp_stack_a->value)
//         {
//             if (val_index <= var->mid)
//             {
//                 while((*stack_a)->value != arr[i])
//                     reverse_rotate(stack_a);
//             }
//             else
//             {
//                 while((*stack_a)->value != arr[i])
//                     rotate(stack_a);
//             }
//             (push(stack_a, stack_b), ft_putstr_fd(1, "pb"));
//             if ((*stack_b)->next && (*stack_b)->value > arr[var->mid])
//                 (rotate(stack_b), ft_putstr_fd(1, "rb"));
//         }
//         val_index++;
//         tmp_stack_a = tmp_stack_a->next;
//     }
// }

// void    first_stage(t_list **stack_a, t_list **stack_b, int *arr, t_var *var)
// {
//     int i;
//     int iter;

//     iter = var->end - var->start;
//     if (look_for_top_inrange(*stack_a, arr, var))
//     {
//         (push(stack_a, stack_b), ft_putstr_fd(1, "pb"));
//         if ((*stack_b)->next && (*stack_b)->value > arr[var->mid])
//             (rotate(stack_b), ft_putstr_fd(1, "rb"));
//     }
//      else
//     top_out_range(stack_a, stack_b, arr, var);
// }
// reconsider the implementation ghda!

t_list  *chunk_sort(t_list **stack_a, t_list **stack_b, t_var *var, int *arr)
{
    var = collect_var(var);
    first_stage(stack_a, stack_b, var, arr);
    
}

t_list *sort_stack(t_list **stack_a)
{
    t_list  *stack_b;
    t_var   *var;
    t_list  *sorted_stack_a;
    int     *sorted_array;

    var->size = get_stack_size(*stack_a);
    stack_b = create_stack_b(*stack_a, var->size);
    sorted_array = create_sorte_array(*stack_a, var->size);
    sorted_stack_a = chunk_sort(stack_a, &stack_b, var, sorted_array);
}
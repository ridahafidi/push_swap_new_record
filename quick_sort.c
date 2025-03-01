/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 00:05:48 by rhafidi           #+#    #+#             */
/*   Updated: 2025/03/01 00:06:06 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

static int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = end;
	j = start;
	i = j - 1;
	while (j < pivot)
	{
		if (arr[j] < arr[pivot])
		{
			i++;
			ft_swap(arr, i , j);
		}
		j++;
	}
	if (j == pivot)
	{
		ft_swap(arr, i + 1, pivot);
		pivot = i + 1;
	}
	return (pivot);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = partition(arr, start, end);
	quick_sort(arr, start, pivot - 1);
	quick_sort(arr, pivot + 1, end);
}

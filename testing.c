#include "push_swap.h"
#define MAX_VALUE 10000
#include <time.h>

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
			ft_swap(arr, i, j);
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

int	main(void)
{
	int arr[500];
	srand(time(NULL));

	// Generate 500 random numbers
	for (int i = 0; i < 500; i++)
	{
		arr[i] = (rand() % MAX_VALUE) + 1;
	}

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d, ", arr[i]);
	quick_sort(arr, 0, ((sizeof(arr) / sizeof(int)) - 1));
	printf("\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d, ", arr[i]);
}
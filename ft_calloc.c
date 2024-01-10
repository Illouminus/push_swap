/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:41:17 by edouard           #+#    #+#             */
/*   Updated: 2024/01/10 17:41:58 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *loc;

	if (nmemb == 0 || size == 0)
	{
		size = 1;
		nmemb = size;
	}
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	loc = malloc(nmemb * size);
	if (!loc)
		return (NULL);
	ft_bzero(loc, nmemb * size);
	return (loc);
}

void ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/* int main()
{
	size_t count, size;
	int *array;

	count = 10;
	size = sizeof(int);
	array = (int *)ft_calloc(count, size);
	if (array == NULL)
	{
		printf("Test 1 failed: memory allocation failed\n");
	}
	else
	{
		for (size_t i = 0; i < count; i++)
		{
			if (array[i] != 0)
			{
				printf("Test 1 failed: memory not set to zero at index %zu\n",
					i);
				free(array);
				return (1);
			}
		}
		printf("Test 1 passed\n");
		free(array);
	}

	count = 0;
	size = sizeof(int);
	array = (int *)ft_calloc(count, size);
	if (array != NULL)
	{
		printf("Test 2 failed: memory should not be allocated\n");
		free(array);
	}
	else
	{
		printf("Test 2 passed\n");
	}

	return (0);
} */
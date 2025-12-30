/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:07:40 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/30 20:44:24 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->a.size - 1)
	{
		if (state->a.array[i] > state->a.array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_min_index(t_state *state)
{
	int	i;
	int	min_idx;

	i = 0;
	min_idx = 0;
	while (i < state->a.size)
	{
		if (state->a.array[i] < state->a.array[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

void	apply_indexing(t_state *state, int *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (i < state->a.size)
	{
		j = 0;
		while (j < state->a.size)
		{
			if (tmp[j] == state->a.array[i])
			{
				state->a.array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	sort_temp_array(int size, int *tmp)
{
	int	i;
	int	swapped;
	int	swap;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if (tmp[i] > tmp[i + 1])
			{
				swap = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = swap;
				swapped = 1;
			}
			i++;
		}
	}
}

int	index_stack(t_state *state)
{
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * state->a.size);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, state->a.array, (sizeof(int) * state->a.size));
	sort_temp_array(state->a.size, tmp);
	apply_indexing(state, tmp);
	free(tmp);
	return (1);
}

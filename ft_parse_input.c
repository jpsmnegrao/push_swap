/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:30:58 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/30 16:34:14 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_state(t_state *state)
{
	state->a.array = NULL;
	state->b.array = NULL;
	state->a.size = 0;
	state->b.size = 0;
	state->total_size = 0;
	state->current_chunk = 0;
	state->chunk_size = 0;
	state->flags = 0;
	state->move_count = 0;
}

static char	**ft_get_input_list(int argc, char *argv[])
{
	char	**list;

	if (argc > 2)
		return (&argv[1]);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			return (NULL);
		return (list);
	}
	return (NULL);
}

static int	ft_init_stacks(t_state *state, char **list)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (list[state->a.size])
		state->a.size++;
	if (state->a.size == 0)
		return (0);
	state->total_size = state->a.size;
	state->a.array = ft_calloc(state->a.size, sizeof(int));
	state->b.array = ft_calloc(state->a.size, sizeof(int));
	if (!state->a.array || !state->b.array)
		return (0);
	while (i < state->a.size)
	{
		state->a.array[i] = ft_atoi(list[i], &error);
		if (error)
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_input(int argc, char *argv[], t_state *state)
{
	char	**list;
	int		res;

	res = 1;
	if (argc <= 1)
		return (0);
	ft_init_state(state);
	list = ft_get_input_list(argc, argv);
	if (!list || !list[0])
		res = 0;
	else if (!ft_init_stacks(state, list))
		res = 0;
	else if (ft_check_dups(state->a.array, state->a.size))
		res = 0;
	if (argc == 2 && list)
		ft_free_split(list);
	return (res);
}

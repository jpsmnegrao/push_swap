/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:30:58 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/22 21:07:15 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_get_input_list(int argc, char *argv[])
{
	char	**list;

	if (argc > 2)
		return (&argv[1]);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			ft_error();
		return (list);
	}
	if (argc <= 1)
		ft_error();
	return (NULL);
}

static void	ft_init_stack_a(t_stack *a, char **list)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (list[size])
		size++;
	a->size = size;
	a->array = malloc(sizeof(int) * size);
	while (i < size)
	{
		a->array[i] = ft_atoi(list[i]);
		i++;
	}
	a->size = i;
}

int	ft_parse_input(int argc, char *argv[], t_state *state)
{
	char	**list;
	t_stack	*a;
	t_stack	*b;

	a = &state->a;
	b = &state->b;
	list = ft_get_input_list(argc, argv);
	ft_init_stack_a(a, list);
	state->b.size = 0;
	state->b.array = malloc(sizeof(int) * state->a.size);
	if (!state->b.array)
		ft_error();
	if (ft_check_dups(a->array, a->size))
		ft_error();
	if (argc == 2)
		ft_free_split(list);
	b->size = 0;
	return (1);
}

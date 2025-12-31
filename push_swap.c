/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:18:16 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/31 00:28:47 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	if (argc < 2)
		return (0);
	state.a.array = NULL;
	state.b.array = NULL;
	if (ft_parse_input(argc, argv, &state) == 0)
	{
		ft_free_arrays(&state);
		ft_error();
	}
	ft_print_stacks(&state);
	if (index_stack(&state) == 0)
	{
		ft_free_arrays(&state);
		ft_error();
	}
	if (is_sorted(&state))
	{
		ft_free_arrays(&state);
		return (0);
	}
	if (state.a.size == 2)
		sa(&state, 1);
	else if (state.a.size == 3)
		sort_three(&state);
	else if (state.a.size <= 5)
		sort_five(&state);
	else if (state.a.size > 5)
		sort_large(&state);
	ft_print_stacks(&state);
	ft_free_arrays(&state);
	return (0);
}

// REMOVE FT_PRINT_STACKS BEFORE SUBMISSION

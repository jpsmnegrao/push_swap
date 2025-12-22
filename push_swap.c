/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:18:16 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/22 21:12:42 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_state state;

	a = state->a;
	b = state->b;
	if (ft_parse_input(argc, argv, &state) == 0)
		ft_error();
	ft_print_stacks(&state);
	sa(&state, 1);
	sb(&state, 1);
	ft_print_stacks(&state);
	ss(&state, 1);
	ft_print_stacks(&state);
	return (0);
}

// REMOVE FT_PRINT_STACKS BEFORE SUBMISSION

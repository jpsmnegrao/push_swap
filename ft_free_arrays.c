/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:52:32 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/29 18:40:47 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arrays(t_state *state)
{
	if (state->a.array)
	{
		free(state->a.array);
		state->a.array = NULL;
	}
	if (state->b.array)
	{
		free(state->b.array);
		state->b.array = NULL;
	}
}

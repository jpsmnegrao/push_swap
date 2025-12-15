/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:20:34 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/15 22:46:56 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}	t_stack;

typedef struct s_state
{
	t_stack	a;
	t_stack	b;
	int		total_size;
	int		current_chunk;
	int		chunk_size;
	int		flags;
	int		move_count;	
}	t_state;

// Operations

// Validation

// Sorting

// Utilities

// 

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_checkduplicates(int *arr, int size);
char	**ft_split(const char *s, char c);
void	ft_free_split(char **arr);
void	ft_error(void);

#endif
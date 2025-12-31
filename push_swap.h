/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:20:34 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/31 00:26:50 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

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

// PARSING AND INITIALIZATION

int		ft_check_dups(int *arr, int size);
void	ft_error(void);
int		ft_parse_input(int argc, char *argv[], t_state *state);

// UTILITIES

int		ft_atoi(const char *str, int *error);
void	*ft_calloc(size_t count, size_t size);
void	ft_free_split(char **arr);
void	ft_free_arrays(t_state *state);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(const char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);

// INSTRUCTIONS

/* op_push.c */
void	pa(t_state *state, int print);
void	pb(t_state *state, int print);

/* op_rev_rotate.c */
void	rra(t_state *state, int print);
void	rrb(t_state *state, int print);
void	rrr(t_state *state, int print);

/* op_rotate.c */
void	ra(t_state *state, int print);
void	rb(t_state *state, int print);
void	rr(t_state *state, int print);

/* op_swap.c */
void	sa(t_state *state, int print);
void	sb(t_state *state, int print);
void	ss(t_state *state, int print);

// SORTING ALGORITHM

/* Algorithm utilities */
int		is_sorted(t_state *state);
int		is_min_index(t_state *state);
int		get_max_pos(t_stack *b);
void	apply_indexing(t_state *state, int *tmp);
void	sort_temp_array(int size, int *tmp);
int		index_stack(t_state *state);
int		get_chunk_size(int n);
void	push_to_b(t_state *state);

/* Algorithm */
void	sort_three(t_state *state);
void	sort_five(t_state *state);
void	sort_large(t_state *state);

// DEBUGGER
void	ft_print_stacks(t_state *state);

#endif
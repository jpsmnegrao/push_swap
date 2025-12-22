/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaim-so <jpaim-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:34:15 by jpaim-so          #+#    #+#             */
/*   Updated: 2025/12/22 19:43:07 by jpaim-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_count(const char *s, char c)
{
	int		i;
	size_t	count;
	int		is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		else if (s[i] == c)
			is_word = 0;
		i++;
	}
	return (count);
}

static char	*fill_word(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, str, i + 1);
	return (word);
}

static void	memfree(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

static int	get_next_word(const char *s, char c, size_t *i, char **out)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
	if (!s[*i])
		return (1);
	*out = fill_word(s + *i, c);
	if (*out == NULL)
		return (0);
	*i += ft_strlen(*out);
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	split = ft_calloc((words + 1), sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		if (!get_next_word(s, c, &i, &split[j]))
		{
			memfree(split);
			return (NULL);
		}
		j++;
	}
	split[j] = NULL;
	return (split);
}

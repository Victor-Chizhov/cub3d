/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:26:38 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/31 18:09:38 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_of_words(char const *str, char sep)
{
	int	count;
	int	prev_sep;
	int	i;

	count = 0;
	prev_sep = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			prev_sep = 0;
		}
		else if (str[i] != sep && prev_sep == 0)
		{
			prev_sep = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char	*new_word(char const *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**new;

	new = malloc(sizeof(char *) * (count_of_words(s, c) + 1));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			new[j] = new_word(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}	
	new[j] = 0;
	return (new);
}

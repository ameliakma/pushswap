/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:20:38 by akhalfou          #+#    #+#             */
/*   Updated: 2026/03/12 19:49:50 by akhalfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_word(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
		{
			count++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (count);
}

int	count_size(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

void	ft_free(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*fill_word(const char *s, char sep, int *i)
{
	int		k;
	int		size;
	char	*word;

	size = count_size(&s[*i], sep);
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	k = 0;
	while (s[*i] && s[*i] != sep)
		word[k++] = s[(*i)++];
	word[k] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			tab[j] = fill_word(s, c, &i);
			if (!tab[j++])
				return (ft_free(tab, j - 1), NULL);
		}
	}
	tab[j] = NULL;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:56:32 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/19 00:20:23 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		split_count(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	f;

	i = 0;
	j = 0;
	f = 0;
	arr = (char**)malloc(sizeof(char*) * (split_count(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		f = i;
		while (s[i] != c && s[i])
			i++;
		// printf("%zu %zu\n", i, f);
		if (i == f)
			break ;
		arr[j] = (char*)malloc(i - f + 1);
		printf("%zu", sizeof(arr[j]));
		strncpy(arr[j], &s[f], i - f);
		arr[j][i - f] = '\0';
		printf("%s\n", arr[j]);
		j++;
	}
	arr[j] = (char*)malloc(sizeof(char));
	arr[j][0] = '\0';
	return (arr);
}

int		main(int argc, char **argv)
{
	char	**out;
	size_t	i;

	i = 0;
	out = ft_strsplit("split  ||this|for|me|||||!|", '|');
	while (out[i][0])
	{
		printf("%s\n", out[i]);
		i++;
	}
	return (1);
}

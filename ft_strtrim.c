/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:15:56 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/18 23:38:44 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	char	*strcp;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s);
	if (s)
	{
		while (is_space(s[start]) && s[start])
			start++;
		while (is_space(s[end - 1]) && s[end - 1])
			end--;
		if (start >= end)
			end = start;
		strcp = (char*)malloc(end - start + 1);
		if (strcp != NULL)
		{
			strcp[end - start] = '\0';
			ft_strncpy(strcp, &s[start], end - start);
			return (strcp);
		}
	}
	return (NULL);
}

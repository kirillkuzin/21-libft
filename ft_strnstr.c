/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:04:22 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/17 00:05:29 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*find;

	str = (char*)malloc(sizeof(char) * len);
	str = ft_strncpy(str, haystack, len - 1);
	str[len - 1] = '\0';
	find = ft_strstr(str, needle);
	if (find)
		return ((char*)&haystack[ft_strlen(str) - ft_strlen(find)]);
	else
		return (NULL);
}

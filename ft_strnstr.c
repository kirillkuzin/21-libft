/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:19:18 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/13 23:01:23 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{

	char	*str;
	char	*c;
	//int		i;
	
	str = (char*)malloc(sizeof(char) * len);
	ft_strncpy(str, haystack, len - 1);
	str[len - 1] = '\0';
	//i = len - ft_strlen(ft_strstr(str, needle)) - 1;
	///printf("%d", i);
	c = ((char*)&haystack[len - 1 - ft_strlen(ft_strstr(str, needle))]);
	printf("%s", c);
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:58:11 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/17 00:04:07 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t  i;
    size_t  j;
	char	tst[50] = {0};

    i = 0;
    j = 0;
	while (dst[i])
        i++;
    while (j < dstsize - 1 && src[j])
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';
	printf("%s", &dst[0]);
	printf("%lu", strlcat(tst, src, dstsize));
	printf("%s", tst);
	printf("%lu", ft_strlen(src) + j - 3);
	return (ft_strlen(src) + j - 3);
}

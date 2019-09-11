/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:23:48 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/11 19:10:47 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

void	*ft_memmove(void *destination, const void *src, size_t n)
{
	unsigned char	*buf;
	unsigned char	*dst;
	size_t			i;

	i = 0;
	dst = (unsigned char*)(destination);
	buf = (unsigned char*)malloc(n);
	ft_memcpy(buf, src, n);
	ft_memcpy(dst, buf, n);
	free(buf);
	return (dst);
}

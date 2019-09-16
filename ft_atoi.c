/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:51:26 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/16 22:44:05 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	char	*s;
	int		result;
	int		negative;

	s = (char*)(str);
	negative = 0;
	while (*s == '\n' || *s == '\v' || *s == '\t' || \
				*s == '\r' || *s == '\f' || *s == ' ')
		s++;
	if (*s == '-')
		negative = 1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - 48);
		s++;
	}
	if (negative == 1)
		result = -result;
	return (result);
}

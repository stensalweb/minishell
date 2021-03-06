/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:13:28 by vgrankul          #+#    #+#             */
/*   Updated: 2019/11/04 16:03:55 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	while (n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else if (*s1 != *s2)
			return (0);
	}
	return (1);
}

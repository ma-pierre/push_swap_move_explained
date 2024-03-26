/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:48:43 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/14 21:08:04 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoll(const char *str)
{
	long long int	i;
	long long int	res;
	int				mp;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	mp = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mp *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i] - 48));
		i++;
	}
	return (res * mp);
}

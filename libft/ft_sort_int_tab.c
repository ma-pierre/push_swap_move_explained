/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:26:49 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/17 18:03:48 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapp(long long int *a, long long int *b)
{
	long long int	s;

	s = *a;
	*a = *b;
	*b = s;
}

long long int	*ft_sort_int_tab(long long int *tab, int size, int is_sorted)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size -3)
	{
		j = i + 1;
		while (j <= size -2)
		{
			if (tab[i] > tab[j])
			{
				ft_swapp(&tab[i], &tab[j]);
				is_sorted++;
			}	
			j++;
		}
		i++;
	}
	if (is_sorted == 0)
	{
		free(tab);
		return (0);
	}
	return (tab);
}

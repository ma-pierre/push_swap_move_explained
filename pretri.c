/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:49:27 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/16 19:39:38 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fillstack(int ac, t_stack **a, long long int *tab)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_saddback(a, ft_snew(tab[i])) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_even_or_odd(int number)
{
	if (number % 2 == 0)
		return (2);
	else
		return (1);
}

void	ft_pretri(t_stack **a, t_stack **b, int tablen, long long int *tab)
{
	int	count;
	int	median;

	count = 0;
	median = (tablen - 1) / 2;
	if (ft_even_or_odd(tablen - 1) == 1)
		median += 1;
	while ((*a)->next)
	{
		if ((*a)->argvalue == tab[tablen - 1] && (*a)->next)
			ft_rotate(a, 1);
		if ((*a)->argvalue != tab[tablen - 1])
		{
			ft_push(a, b, 2);
			if ((*b) && (*b)->argvalue < tab[median])
				ft_rotate(b, 2);
		}
		count++;
	}
}

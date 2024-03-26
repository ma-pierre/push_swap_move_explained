/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:22:25 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/17 18:05:57 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	sort_small(t_stack **a, int ac)
{
	if (ac == 3)
		ft_swap(a, 1);
	if (ac == 4)
		ft_sort3(a);
}

int	sort_all(t_stack *a, t_stack *b, int ac, long long int *tab)
{
	if (ac == 3 || ac == 4)
		sort_small(&a, ac);
	if (ac == 6)
		ft_sort5(&a, &b);
	if (ac != 4 && ac != 6 && ac != 3)
	{
		ft_pretri(&a, &b, ac -1, tab);
		while (b)
		{
			define_cost(&a, &b);
			define_min_cost(&b, 0, 0);
			if (find_cheapest_and_move(&a, &b) == -1)
			{
				free(tab);
				ft_clear(&a);
				ft_clear(&b);
				return (-1);
			}
		}
		from_min_to_max(&a);
	}
	free(tab);
	ft_clear(&a);
	ft_clear(&b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;
	long long int	*tab;

	tab = ft_parsing(ac, av);
	if (!tab)
		return (0);
	a = ft_snew(tab[0]);
	b = NULL;
	if (fillstack(ac - 1, &a, tab) == -1)
		return (0);
	tab = ft_sort_int_tab(tab, ac, 0);
	if (tab == NULL)
	{
		ft_clear(&a);
		ft_clear(&b);
		return (0);
	}
	sort_all(a, b, ac, tab);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:33:22 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/17 18:28:56 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_arg_isdigit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
		{
			j++;
			if (av[i][j] == '\0')
				return (-1);
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

long long int	*ft_convert_arg(int ac, char **av, long long int *tab)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (++i < ac - 1)
	{
		tab[i] = ft_atoll(av[j]);
		if ((tab[i] > 2147483647) || (tab[i] < -2147483648))
			return (free(tab), NULL);
		j++;
	}
	i = -1;
	while (++i <= ac - 2)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab[i] == tab[j])
				return (free(tab), NULL);
			j++;
		}
	}
	return (tab);
}

long long int	*ft_parsing(int ac, char **av)
{
	long long int	*tab;

	if (ac <= 1)
		return (NULL);
	if (ft_arg_isdigit(ac, av) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	tab = malloc(sizeof(long long int *) * (ac - 1));
	if (!tab)
		return (NULL);
	tab = ft_convert_arg(ac, av, tab);
	if (tab == NULL)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (NULL);
	}
	if (ac <= 2)
	{	
		free(tab);
		return (NULL);
	}
	return (tab);
}

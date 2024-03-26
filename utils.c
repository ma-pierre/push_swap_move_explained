/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:01:48 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/14 21:06:46 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_define_position(t_stack **s)
{
	t_stack	*tmp;
	int		i;

	tmp = *s;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	stack_len(t_stack **a)
{
	int		len;
	t_stack	*tmp;

	tmp = *a;
	len = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	ft_absolute(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

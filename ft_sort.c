/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:40:23 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/17 17:45:48 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **head)
{
	if (((*head)->next->next->argvalue > (*head)->argvalue
			&& (*head)->next->next->argvalue < (*head)->next->argvalue)
		|| ((*head)->argvalue < (*head)->next->argvalue
			&& (*head)->argvalue > (*head)->next->next->argvalue))
		ft_rev_rotate(head, 1);
	if (((*head)->next->argvalue < (*head)->argvalue
			&& (*head)->next->argvalue > (*head)->next->next->argvalue)
		|| ((*head)->next->next->argvalue > (*head)->next->argvalue
			&& (*head)->next->next->argvalue < (*head)->argvalue))
		ft_rotate(head, 1);
	if ((*head)->next->next->argvalue > (*head)->argvalue
		&& (*head)->argvalue > (*head)->next->argvalue)
		ft_swap(head, 1);
}

int	ft_findmin(t_stack **s)
{
	int		i;
	int		pos;
	t_stack	*temp;

	i = (*s)->argvalue;
	temp = (*s)->next;
	while (temp)
	{
		if (i > temp->argvalue)
		{
			i = temp->argvalue;
		}
		temp = temp->next;
	}
	pos = 0;
	temp = (*s);
	while ((temp->argvalue != i))
	{
		pos++;
		temp = temp->next;
	}
	return (pos);
}

int	ft_findmax(t_stack **s)
{
	int		i;
	int		pos;
	t_stack	*temp;

	i = (*s)->argvalue;
	temp = (*s)->next;
	while (temp)
	{
		if (i < temp->argvalue)
		{
			i = temp->argvalue;
		}
		temp = temp->next;
	}
	pos = 0;
	temp = (*s);
	while ((temp->argvalue != i))
	{
		pos++;
		temp = temp->next;
	}
	return (pos);
}

int	ft_sort5(t_stack **a, t_stack **b)
{
	int	i;
	int	pos;

	pos = ft_findmin(a);
	i = 0;
	while ((i++) < pos)
		ft_rotate(a, 1);
	ft_push(a, b, 2);
	pos = ft_findmin(a);
	i = 0;
	while ((i++) < pos)
		ft_rotate(a, 1);
	if (ft_push(a, b, 2) == -1)
		return (-1);
	ft_sort3(a);
	if (ft_push(b, a, 1) == -1)
		return (-1);
	if (ft_push(b, a, 1) == -1)
		return (-1);
	return (0);
}

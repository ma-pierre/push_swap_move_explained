/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:21:12 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/16 20:08:26 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head, int abr)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *head;
	tmp2 = (*head)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*head = tmp2;
	if (abr == 1)
		ft_putstr_fd("sa\n", 1);
	if (abr == 2)
		ft_putstr_fd("sb\n", 1);
}

int	ft_push(t_stack **a, t_stack **b, int ab)
{
	t_stack	*pushed;
	t_stack	*tmp;

	tmp = *a;
	pushed = ft_snew((*a)->argvalue);
	if (!pushed)
		return (-1);
	if (*b == NULL)
	*b = pushed;
	else
	{
		pushed->next = *b;
		*b = pushed;
	}
	*a = (*a)->next;
	free(tmp);
	if (ab == 1)
		ft_putstr_fd("pa\n", 1);
	if (ab == 2)
		ft_putstr_fd("pb\n", 1);
	return (0);
}

void	ft_rotate(t_stack **head, int abr)
{
	t_stack	*tail;

	tail = *head;
	while (tail->next != NULL)
	tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
	if (abr == 1)
		ft_putstr_fd("ra\n", 1);
	if (abr == 2)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rev_rotate(t_stack **head, int abr)
{
	t_stack	*tail;
	t_stack	*futuretail;

	tail = *head;
	futuretail = NULL;
	while (tail->next != NULL)
	{
		futuretail = tail;
		tail = tail->next;
	}
	futuretail->next = NULL;
	tail->next = *head;
	*head = tail;
	if (abr == 1)
		ft_putstr_fd("rra\n", 1);
	if (abr == 2)
		ft_putstr_fd("rrb\n", 1);
}

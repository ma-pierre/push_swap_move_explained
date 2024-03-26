/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:25:11 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/16 20:10:11 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_saddback(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return (-1);
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next != 0)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	else
		*lst = new;
	return (0);
}

t_stack	*ft_snew(int argvalue)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->argvalue = argvalue;
	new->next = NULL;
	return (new);
}

void	ft_sclear(t_stack **head)
{
	t_stack	*dup;
	t_stack	*temp;

	if (!head)
		return ;
	dup = *head;
	while (dup)
	{
		temp = dup;
		dup = temp->next;
		free(temp);
	}
	*head = 0;
}

void	ft_clear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*dup;

	dup = *stack;
	while (dup)
	{
		tmp = dup;
		dup = tmp->next;
		free(tmp);
	}
	*stack = 0;
}

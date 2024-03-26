/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:44:16 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/16 20:10:27 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_sup(t_stack **a, int b)
{
	t_stack	*tmp;
	int		i;
	int		sup;

	tmp = (*a);
	sup = 2147483647;
	while (tmp)
	{
		if (tmp->argvalue > b && tmp->argvalue < sup)
		sup = tmp->argvalue;
		tmp = tmp->next;
	}
	tmp = (*a);
	i = 0;
	while (tmp->argvalue != sup)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	define_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = *b;
	size_a = stack_len(a);
	size_b = stack_len(b);
	ft_define_position(a);
	ft_define_position(b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = ((size_b - tmp_b->pos) * -1);
		tmp_b->cost_a = pos_sup(a, tmp_b->argvalue);
		if (tmp_b->cost_a > (size_a / 2))
			tmp_b->cost_a = ((size_a - tmp_b->cost_a) * -1);
		tmp_b = tmp_b->next;
	}
}

void	define_min_cost(t_stack **b, int abs_a, int abs_b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp)
	{
		abs_a = ft_absolute(tmp->cost_a);
		abs_b = ft_absolute(tmp->cost_b);
		if (tmp->cost_a < 0 && tmp->cost_b < 0)
		{	
			if (tmp->cost_a <= tmp->cost_b)
				tmp->min_cost = abs_a;
			else
				tmp->min_cost = abs_b;
		}
		else if (tmp->cost_a > 0 && tmp->cost_b > 0)
		{
			if (tmp->cost_a >= tmp->cost_b)
				tmp->min_cost = tmp->cost_a;
			else
				tmp->min_cost = tmp->cost_b;
		}
		else
			tmp->min_cost = ft_absolute(tmp->cost_b) + ft_absolute(tmp->cost_a);
		tmp = tmp->next;
	}
}

int	find_cheapest_and_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		pos_of_cheapest;

	min = 2147483647;
	tmp = *b;
	while (tmp)
	{
		if (tmp->min_cost < min)
		{
			min = tmp->min_cost;
			pos_of_cheapest = tmp->pos;
		}
		tmp = tmp->next;
	}
	tmp = *b;
	while (tmp->pos != pos_of_cheapest)
		tmp = tmp->next;
	if (ft_do_move_neg(a, b, tmp->cost_b, tmp->cost_a) == -1)
		return (-1);
	return (0);
}

void	from_min_to_max(t_stack **a)
{
	int	pos_min;
	int	len;

	len = stack_len(a);
	pos_min = ft_findmin(a);
	if (pos_min > len / 2)
	{
		while (pos_min++ < len)
			ft_rev_rotate(a, 1);
	}
	else
	{
		while (pos_min-- > 0)
			ft_rotate(a, 1);
	}
}

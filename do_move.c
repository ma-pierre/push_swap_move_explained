/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:49:52 by mapierre          #+#    #+#             */
/*   Updated: 2024/03/26 23:21:08 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, 3);
	ft_rotate(b, 3);
	ft_putstr_fd("rr\n", 1);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a, 3);
	ft_rev_rotate(b, 3);
	ft_putstr_fd("rrr\n", 1);
}

int	ft_do_move_neg(t_stack **a, t_stack **b, int cb, int ca)
{
	while (cb < 0 && ca < 0)
	{
		ft_rrr(a, b);
		cb++;
		ca++;
	}
	while (cb < 0)
	{
		ft_rev_rotate(b, 2);
		cb++;
	}
	while (ca < 0)
	{
		ft_rev_rotate(a, 1);
		ca++;
	}
	if (ft_do_move_pos(a, b, ca, cb) == -1)
		return (-1);
	return (0);
}

int	ft_do_move_pos(t_stack **a, t_stack **b, int ca, int cb)
{
	while (cb > 0 && ca > 0)
	{
		ft_rr(a, b);
		ca--;
		cb--;
	}
	while (cb > 0)
	{
		ft_rotate(b, 2);
		cb--;
	}
	while (ca > 0)
	{
		ft_rotate(a, 1);
		ca--;
	}
	if (ft_push(b, a, 1) == -1)
		return (-1);
	return (0);
}

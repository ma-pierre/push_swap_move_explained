/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:33:33 by mapierre          #+#    #+#             */
/*   Updated: 2023/02/24 08:28:38 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("test");
	b = ft_lstnew("ytest");
	ft_lstadd_front(&a, b);
	while (b != NULL)
	{
		printf("%s", ((char *)b->content));
		b = b->next;
	}
}*/

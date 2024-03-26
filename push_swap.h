/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:47:58 by mapierre          #+#    #+#             */
/*   Updated: 2023/05/17 17:58:32 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack	t_stack;

struct	s_stack
{
	int		argvalue;
	int		pos;
	int		pos_in_a;
	int		cost_b;
	int		cost_a;
	int		min_cost;
	t_stack	*next;
};

long long int	*ft_parsing(int ac, char **av);
long long int	*ft_convert_arg(int ac, char **av, long long int *tab);
int				ft_arg_isdigit(int ac, char **av);
int				ft_findmin(t_stack **s);
void			ft_swap(t_stack **head, int abr);
int				ft_push(t_stack **a, t_stack **b, int ab);
void			ft_rotate(t_stack **head, int abr);
void			ft_rev_rotate(t_stack **head, int abr);
int				ft_saddback(t_stack **lst, t_stack *new);
t_stack			*ft_snew(int argvalue);
void			ft_sort3(t_stack **head);
int				ft_sort5(t_stack **a, t_stack **b);
void			ft_sclear(t_stack **head);
int				fillstack(int ac, t_stack **a, long long int *tab);
int				ft_even_or_odd(int number);
void			ft_clear(t_stack **stack);
int				ft_findmax(t_stack	**s);
void			ft_pretri(t_stack **a, t_stack **b, int tablen,
					long long int *tab);
int				pos_sup(t_stack **a, int b);
int				stack_len(t_stack **a);
void			ft_define_position(t_stack **s);
void			define_cost(t_stack **a, t_stack **b);
void			define_min_cost(t_stack **b, int abs_a, int abs_b);
int				find_cheapest_and_move(t_stack **a, t_stack **b);
int				ft_absolute(int i);
int				ft_do_move_neg(t_stack **a, t_stack **b, int cb, int ca);
int				ft_do_move_pos(t_stack **a, t_stack **b, int ca, int cb);
void			ft_rrr(t_stack **a, t_stack **b);
void			ft_rr(t_stack **a, t_stack **b);
void			from_min_to_max(t_stack **a);
int				sort_all(t_stack *a, t_stack *b, int ac, long long int *tab);
void			sort_small(t_stack **a, int ac);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:26:53 by haouadia          #+#    #+#             */
/*   Updated: 2023/03/13 21:26:58 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack **b)
{
	t_stack	*save;

	if (*b == NULL)
		return ;
	save = (*b)->next->next;
	ft_lstadd_front(b, (*b)->next);
	(*b)->next->next = save;
	write(1, "sb\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*save_a;
	t_stack	*save_b;

	if (*a == NULL)
		return ;
	save_a = (*a);
	*a = (*a)->next;
	save_b = (*b);
	ft_lstadd_front(b, save_a);
	(*b)->next = save_b;
	write(1, "pb\n", 3);
}

void	ft_rb(t_stack **b)
{
	t_stack	*save;

	if (!(*b))
		return ;
	save = *b;
	(*b) = (*b)->next;
	save->next = NULL;
	ft_lstadd_back(b, save);
	write(1, "rb\n", 3);
}

void	ft_rrb(t_stack **b)
{
	t_stack	*save;
	t_stack	*temp;

	if (!(*b))
		return ;
	temp = (*b);
	while (temp->next->next)
		temp = temp->next;
	save = temp->next;
	temp->next = NULL;
	ft_lstadd_front(b, save);
	write(1, "rrb\n", 4);
}

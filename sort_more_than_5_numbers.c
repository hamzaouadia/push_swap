/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:46:58 by haouadia          #+#    #+#             */
/*   Updated: 2023/03/03 21:47:00 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(int i, int *tab, t_stack **a, t_stack **b)
{
	int	key_num;
	int	size_a;
	int	pos;

	size_a = ft_lstsize(*a);
	while (i <= size_a)
	{
		key_num = tab[i];
		while (ft_lstsize(*b) <= i)
		{
			pos = search_for_pos(*a, key_num, ft_lstsize(*a));
			if (pos <= ft_lstsize(*a) / 2)
			{
				while (pos--)
					ft_ra(a);
			}
			else
			{
				while (pos++ < ft_lstsize(*a))
					ft_rra(a);
			}
			ft_pb(a, b);
		}
		i += ft_chunk(size_a);
	}
}

void	push_rest_to_b(t_stack **a, t_stack **b)
{
	int	pos;

	while (*a)
	{
		pos = search_for_small(*a);
		if (pos <= ft_lstsize(*a) / 2)
		{
			while (pos--)
				ft_ra(a);
		}
		else if (pos > ft_lstsize(*a) / 2)
		{
			while (pos++ < ft_lstsize(*a))
				ft_rra(a);
		}
		ft_pb(a, b);
	}
}

void	else_conditions(t_stack **a, t_stack **b, t_var *var)
{
	while (var->pos++ < ft_lstsize(*b))
	{
		if ((*b)->nb == var->tab[var->size_a])
		{
			ft_pa(a, b);
			var->pos--;
			var->key = 1;
		}
		ft_rrb(b);
	}
}

void	repush_conditions(t_stack **a, t_stack **b, t_var *var)
{
	if (var->pos <= ft_lstsize(*b) / 2)
	{
		while (var->pos-- > 0)
		{
			if ((*b)->nb == var->tab[var->size_a])
			{
				ft_pa(a, b);
				var->key = 1;
			}
			else
				ft_rb(b);
		}
	}
	else
		else_conditions(a, b, var);
}

void	ft_sort_more_than_5(t_stack **a, t_stack **b)
{
	t_var	var;

	var.tab = stack_to_tab(*a);
	var.size_a = ft_lstsize(*a);
	sort_tab(var.tab, var.size_a);
	var.i = ft_chunk(var.size_a) - 1;
	push_chunks_to_b(var.i, var.tab, a, b);
	push_rest_to_b(a, b);
	var.size_a = var.size_a - 2;
	while (*b)
	{
		var.pos = search_for_big(*b);
		var.key = 0;
		repush_conditions(a, b, &var);
		ft_pa(a, b);
		if (var.key == 1)
		{
			ft_sa(a);
			var.size_a--;
		}
		var.size_a--;
	}
	free(var.tab);
}

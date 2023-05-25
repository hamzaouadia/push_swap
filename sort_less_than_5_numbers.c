/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_5_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:46:38 by haouadia          #+#    #+#             */
/*   Updated: 2023/03/03 21:46:40 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_and_less(t_stack **a)
{
	if (ft_sheck_sort(*a) == 0)
		return ;
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a);
	if (ft_lstsize(*a) == 2)
		return ;
	if ((*a)->nb > (*a)->next->next->nb)
		ft_rra(a);
	if ((*a)->next->nb > (*a)->next->next->nb)
	{
		ft_sa(a);
		ft_ra(a);
	}
}

int	find_in_tab(int *tab, t_stack *a, int c)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = ft_lstsize(a);
	while (i < l)
	{
		j = i + 1;
		while (j < l)
		{
			if ((tab[j] < tab[i]) && c == 0)
				break ;
			if ((tab[j] > tab[i]) && c == 1)
				break ;
			j++;
		}
		if (j == l)
			break ;
		i++;
	}
	free (tab);
	return (i);
}

int	*stack_to_tab(t_stack *a)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * ft_lstsize(a));
	if (!tab)
		exit (0);
	while (a)
	{
		tab[i] = a->nb;
		a = a->next;
		i++;
	}
	return (tab);
}

void	push_to_b(t_stack **a, t_stack **b, int i)
{
	if (i < 3)
	{
		while (i-- > 0)
			ft_ra(a);
		ft_pb(a, b);
	}
	else
	{
		while (i++ < ft_lstsize(*a))
			ft_rra(a);
		ft_pb(a, b);
	}
}

void	ft_sort_5_and_less(t_stack **a, t_stack **b)
{
	int	*tab;
	int	i;

	if (ft_sheck_sort(*a) == 0)
		return ;
	tab = stack_to_tab(*a);
	i = find_in_tab(tab, *a, 1);
	push_to_b(a, b, i);
	tab = stack_to_tab(*a);
	i = find_in_tab(tab, *a, 0);
	push_to_b(a, b, i);
	ft_sort_3_and_less(a);
	ft_pa(a, b);
	ft_pa(a, b);
	ft_ra(a);
}

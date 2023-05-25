/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:30:12 by haouadia          #+#    #+#             */
/*   Updated: 2023/03/13 21:30:15 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_spl(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

int	search_for_pos(t_stack *a, int key_num, int size)
{
	int	i;

	i = 0;
	while (--size)
	{
		if (a->nb <= key_num)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

int	search_for_big(t_stack *b)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = b->nb;
	while (b)
	{
		if (nb < b->nb)
		{
			nb = b->nb;
			i = j;
		}
		j++;
		b = b->next;
	}
	return (i);
}

int	search_for_small(t_stack *a)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = a->nb;
	while (a)
	{
		if (nb > a->nb)
		{
			nb = a->nb;
			i = j;
		}
		j++;
		a = a->next;
	}
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	char	**str;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	i = ac - 1;
	while (i)
	{
		str = ft_split(av[i], ' ');
		f_stack_a(&a, str);
		free_spl(str);
		i--;
	}
	if (ft_sheck_sort(a) == 0)
		return (0);
	i = ft_lstsize(a);
	if (i <= 3)
		ft_sort_3_and_less(&a);
	else if (i <= 5)
		ft_sort_5_and_less(&a, &b);
	else if (i <= 500)
		ft_sort_more_than_5(&a, &b);
}

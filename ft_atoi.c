/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:13:23 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/24 02:13:29 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int	ft_atoi(const char *str)
{
	int					signe;
	unsigned long long	nbr;

	signe = 1;
	nbr = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			ft_exit();
		nbr = nbr * 10 + *str - '0';
		if (nbr > INT_MAX && signe > 0)
			ft_exit();
		if (nbr > INT_MAX && signe < 0)
			ft_exit();
		str++;
	}
	return (nbr * signe);
}

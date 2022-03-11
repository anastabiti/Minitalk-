/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:20:52 by atabiti           #+#    #+#             */
/*   Updated: 2022/01/17 11:16:55 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	positive;

	positive = 1;
	n = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			positive = -1;
		}
	i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return ((int)n * positive);
}

void	sender(int PIDN, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c % 2) == 1)
		{
			kill(PIDN, SIGUSR2);
			usleep(200);
		}
		if ((c % 2) == 0)
		{
			kill(PIDN, SIGUSR1);
			usleep(200);
		}
		c = c / 2;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	x;
	int	c;

	if (argc < 3 || argc > 3)
	{
		write(1, "NOT VALID ARGUMENT  ", 19);
	}
	if (argc == 3)
	{
		x = 0;
		while (argv[2][x])
		{
			c = argv[2][x];
			sender(ft_atoi(argv[1]), c);
			x++;
		}
	}
}

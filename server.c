/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:21:03 by atabiti           #+#    #+#             */
/*   Updated: 2022/01/17 11:17:16 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
	}
}
static int	g_char;

void	ft_checker(int i)
{
	if (i == 7)
		g_char = g_char + 128;
	if (i == 6)
		g_char = g_char + 64;
	if (i == 5)
		g_char = g_char + 32;
	if (i == 4)
		g_char = g_char + 16;
	if (i == 3)
		g_char = g_char + 8;
	if (i == 2)
		g_char = g_char + 4;
	if (i == 1)
		g_char = g_char + 2;
	if (i == 0)
		g_char = g_char + 1;
}

void	anas_bit_handler(int sig, siginfo_t *info, void *other)
{
	static int	i = 0;
	static int	sender_pid;

	if (sender_pid != info->si_pid && info->si_pid != 0)
	{
		sender_pid = info->si_pid;
		i = 0;
		g_char = 0;
	}
	if (sig == SIGUSR2)
	{
		ft_checker(i);
		i++;
	}
	if (sig == SIGUSR1)
	{
		i++;
	}
	if (i >= 8)
	{
		write(1, &g_char, 1);
		g_char = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	whattodo;
	int					n;

	n = getpid();
	ft_putchar(' ');
	ft_putnbr(n);
	ft_putchar('\n');
	whattodo.sa_sigaction = &anas_bit_handler;
	whattodo.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &whattodo, NULL);
	sigaction(SIGUSR1, &whattodo, NULL);
	while (1337)
		pause();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:17:48 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/06/22 20:17:49 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "minitalk.h"

typedef struct s_data
{
	int			result;
	int			power;
}				t_data;
t_data			g_data;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_bitshift_switch(int sig)
{
	if (sig == SIGUSR1)
		g_data.result += 1 << g_data.power;
	g_data.power++;
	if (g_data.power == 8)
	{
		g_data.power = 0;
		write(1, &g_data.result, 1);
		g_data.result = 0;
	}
}

int	main(int ac, char **av)
{
	int	get;

	g_data.result = 0;
	g_data.power = 0;
	get = getpid();
	if (ac == 1)
	{
		ft_putnbr(get);
		signal(SIGUSR1, ft_bitshift_switch);
		signal(SIGUSR2, ft_bitshift_switch);
		while (1)
			pause ();
	}
	else
		write(1, "\n", 1);
	av = NULL;
}

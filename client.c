/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:17:40 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/06/22 20:17:41 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "minitalk.h"

void	ft_error(void)
{
	printf("Check ur PID \n");
	exit(0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_signal_send(int *index, char *str, int *i, int pid)
{
	int	bit;

	bit = ((str[*index] >> *i) & 1);
	if (bit == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error();
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error();
	}
}

int	convert_and_send(int pid, char *str)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (str[index] != '\0')
	{
		i = 0;
		while (i < 8)
		{
			ft_signal_send(&index, str, &i, pid);
			usleep (150);
			i++;
		}
		index++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	else
	{
		ft_check_char(argv);
		pid = ft_atoi(argv[1]);
		convert_and_send(pid, argv[2]);
	}
	if (convert_and_send(pid, "") == 1)
		printf("Message received to server");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 21:12:13 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/06/30 21:12:15 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

int		ft_atoi(char *str);
int		ft_isdigit(int c);
void	ft_error(void);
void	ft_putstr(char *str);
void	ft_signal_send(int *index, char *str, int *i, int pid);
int		convert_and_send(int pid, char *str);
void	ft_bitshift_switch(int sig);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_check_char(char **argv);

#endif
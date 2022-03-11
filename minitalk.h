/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:36:10 by atabiti           #+#    #+#             */
/*   Updated: 2022/01/17 11:16:42 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>

void	ft_checker(int i);
void	anas_bit_handler(int sig, siginfo_t *info, void *other);
int		ft_atoi(const char *str);

#endif

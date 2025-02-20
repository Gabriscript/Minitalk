/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:23:25 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/19 14:54:02 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	signal_handler(int signum)
{
	static char	character;
	static int	bit;

	if (signum == SIGUSR1)
		character |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		character = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{		
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}

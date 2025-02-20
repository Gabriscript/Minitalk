/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:28:47 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/20 09:36:32 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((c >> bit) & 1) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(80);
		bit++;
	}
}

static void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\n');
}

static int	is_valid_pid(char *str)
{
	int	pid;

	pid = ft_atoi(str);
	if (pid <= 0)
	{
		ft_putstr_fd("Error: Invalid PID\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error: Provide 3 arguments\n", 2);
		return (-1);
	}
	if (!is_valid_pid(argv[1]))
		return (-1);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}

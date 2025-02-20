/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:20:39 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/19 11:45:25 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

void	ft_putnbr(int n)
{
	char	res;

	if (n > 9)
		ft_putnbr(n / 10);
	res = (n % 10) + '0';
	write(1, &res, 1);
}

int	ft_atoi(char *str)
{
	long long int	res;
	int				i;

	i = 0;
	res = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (ft_strlen(str) > 10)
		return (0);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (res > INT_MAX)
			return (0);
	}
	return (res);
}

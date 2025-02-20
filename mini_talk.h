/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:18:11 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/19 11:39:15 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <unistd.h>
# include <signal.h>
# include <limits.h>

int		ft_atoi(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr(int n);

#endif

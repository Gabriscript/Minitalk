/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:23:25 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/18 12:23:25 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mini_talk.h"

static void	signal_handler(int signum)
{
	static int	bit;
	static char	character;

    if (bit == 0 && character == 0)
    {
        bit = 0;
        character = 0;
    }
	if (signum == SIGUSR1)      
		character |= (1 << bit); // Se riceviamo SIGUSR1, il bit è 1
	bit++;
	if (bit == 8) // Se abbiamo ricevuto 8 bit, significa che abbiamo un carattere
	{
		write(1, &character, 1);
         // Stampiamo il carattere
		if (character == '\n')       // Se è '\n', andiamo a capo
			write(1, "\n", 1);
		character = 0; // Reset del carattere per il prossimo
		bit = 0;       // Reset del conteggio dei bit
	}
}

int	main(void)
{
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);

	signal(SIGUSR1, signal_handler); // Impostiamo il gestore di segnali per SIGUSR1
	signal(SIGUSR2, signal_handler); // Impostiamo il gestore di segnali per SIGUSR2

	while (1) // Il server resta in ascolto per sempre
		pause(); // Aspetta un segnale prima di continuare
	return (0);
}


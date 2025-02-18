/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:28:47 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/18 11:28:47 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// Invia un singolo bit (0 o 1) al processo specificato tramite segnali.
static void send_bit(int pid, char bit)
{
    if (bit == '1')
        kill(pid, SIGUSR1); // Invia SIGUSR1 per rappresentare '1'
    else
        kill(pid, SIGUSR2); // Invia SIGUSR2 per rappresentare '0'
    usleep(100); // Pausa per evitare problemi di sincronizzazione
}

// Invia un carattere al processo specificato convertendolo in una sequenza di bit.
static void send_char(int pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if (((c >> bit) & 1) == 0)
         {
            send_bit(pid, '0');
        } else {
            send_bit(pid, '1');
        }
        bit++;
    }
}

// Invia una stringa di caratteri al processo specificato.
static void send_message(int pid, char *message)
{
    int i;

    i = 0;
    while (message[i])
    {
        send_char(pid, message[i]); // Invia ogni carattere
        i++;
    }
    send_char(pid, '\n'); // Invia un newline per segnalare la fine del messaggio
}

int main(int argc, char **argv)
{
    int result;
    int pid;

    if (argc != 3)
        return (-1);

    pid = ft_atoi(argv[1]); // Ottieni l'ID del processo dal primo argomento

    // Verifica che il PID sia valido
    result = kill(pid, 0);
    if (result != 0)
    {
        ft_putstr("Invalid PID\n"); //perror non è consentito
        return (-1);
    }
    send_message(pid, argv[2]); // Invia il messaggio dal secondo argomento
    return (0);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:09:02 by evalenti          #+#    #+#             */
/*   Updated: 2023/09/09 12:23:23 by evalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
INSTRUCTIONS

Mandatory Part
You must create a communication program in the form of a client and a server.
• The server must be started first. After its launch, it has to print its PID.
• The client takes two parameters:
    ◦ The server PID.
    ◦ The string to send.
• The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
• The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.
1 second for displaying 100 characters is way too much!
• Your server should be able to receive strings from several clients in a row without
needing to restart.
• The communication between your client and your server has to be done only using
UNIX signals.
• You can only use these two signals: SIGUSR1 and SIGUSR2.

Linux system does NOT queue signals when you already have pending
signals of this type! Bonus time?

Bonus part
• The server acknowledges every message received by sending back a signal to the
client.
• Unicode characters support!
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
    int	i;
    int	nb;

    i = 0;
    nb = 0;
    while (str[i])
    {
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return (nb);
}

static void	send_char(char *pid, char c)
{
    int	i;
    int	bit;

    i = 0;
    while (i < 8)
    {
        bit = (c >> i) & 1;
        if (bit)
            kill(ft_atoi(pid), SIGUSR1);
        else
            kill(ft_atoi(pid), SIGUSR2);
        i++;
        usleep(100);
    }
}

int    main(int argc, char **argv)
{
    int	i;

    if (argc != 3)
        return (0);
    i = 0;
    while (argv[2][i])
    {
        send_char(argv[1], argv[2][i]);
        i++;
    }
    send_char(argv[1], '\0');
    return (0);
}
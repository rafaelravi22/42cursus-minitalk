/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafamart <rafamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:21:57 by rafamart          #+#    #+#             */
/*   Updated: 2023/10/24 16:58:28 by rafamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid_id, char *txt)
{
	int		i;
	int		base;
	char	ch;

	i = 0;
	while (txt[i])
	{
		base = 128;
		ch = txt[i];
		while (base > 0)
		{
			if (ch >= base)
			{
				kill(pid_id, SIGUSR1);
				ch = ch - base;
			}
			else
				kill(pid_id, SIGUSR2);
			base = base >> 1;
			usleep(333);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_bit(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr("(Error)\n");
}

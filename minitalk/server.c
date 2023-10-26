/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafamart <rafamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:22:01 by rafamart          #+#    #+#             */
/*   Updated: 2023/10/22 19:50:55 by rafamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_bin[8] = {0};

void	convert_to_txt(int *bin)
{
	int		i;
	int		base;
	int		total;
	char	letra;

	base = 1;
	i = 7;
	total = 0;
	while (i >= 0)
	{
		total = total + (base * bin[i]);
		i--;
		base = base << 1;
	}
	letra = (char)total;
	ft_putchar(letra);
}

void	get_bin(int bit)
{
	static int	i;

	if (bit == SIGUSR1)
	{
		g_bin[i] = 1;
		i++;
	}
	else if (bit == SIGUSR2)
	{
		g_bin[i] = 0;
		i++;
	}
	if (i == 8)
	{
		convert_to_txt(g_bin);
		i = 0;
	}
}

int	main(void)
{
	ft_putstr("The server PID is:\n");
	ft_putnubr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, get_bin);
	signal(SIGUSR2, get_bin);
	while (1)
		pause();
}

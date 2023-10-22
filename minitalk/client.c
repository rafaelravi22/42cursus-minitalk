
#include "minitalk.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	res;

	res = 0;
	i = 0;
	signal = 1;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * signal);
}

void	send_bit(int pid_id,char *txt)
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
			usleep(666);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		send_bit(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr("(Error)\n");
}

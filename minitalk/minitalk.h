#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *s);
int	    ft_atoi(const char *str);
void	send_bit(int pid_id,char *txt);
void	ft_putchar(char c);
void	convert_to_txt(int *bin);
void	get_bin(int bit);
void	ft_putnubr(long int num);

#endif

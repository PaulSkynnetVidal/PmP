/*
** number.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:30:36 2014 paul vidal
** Last update Thu Jul 17 09:30:38 2014 paul vidal
*/

#include "square.h"

int	getnbr(char *str)
{
  int	i;
  int	result;
  int	neg;

  i = 0;
  result = 0;
  neg = 1;
  while (str && str[i] == '-')
    {
      neg *= -1;
      ++i;
    }
  while (str && str[i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	return (result * neg);
      result = result * 10 + str[i] - 48;
      ++i;
    }
  return (result * neg);
}

int	putnbr(int nb)
{
  if (nb < 0)
    {
      if (my_putchar('-') == -1)
	return (-1);
      nb *= -1;
    }
  if (nb >= 10)
    putnbr(nb / 10);
  return (my_putchar(nb % 10 + 48));
}

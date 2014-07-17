/*
** str.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:32:46 2014 paul vidal
** Last update Thu Jul 17 09:33:05 2014 paul vidal
*/

#include "square.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != 0)
    ++i;
  return (i);
}

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}

int	my_putstr(char *s)
{
  if (!s)
    return (-1);
  return (write(1, s, my_strlen(s)));
}

int	my_puterror(char *s)
{
  if (!s)
    return (-1);
  return (write(2, s, my_strlen(s)));
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while (s1[i] != 0)
    {
      if (s1[i] != s2[i])
	return (-1);
      ++i;
    }
  return (0);
}

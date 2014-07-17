/*
** parser.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:31:27 2014 paul vidal
** Last update Thu Jul 17 09:31:29 2014 paul vidal
*/

#include "square.h"

int	get_l_size(t_square *square, char **args)
{
  if (!square || !args || !args[1])
    return (-1);
  if (my_strcmp(args[0], "-l") != 0)
    return (-1);
  if ((square->l = getnbr(args[1])) <= 0)
    return (my_puterror("invalid size for -l\n"));
  return (0);
}

int	get_L_size(t_square *square, char **args)
{
  if (!square || !args || args[1])
    return (-1);
  write(1, "Bonjour\n", 8);
  if (my_strcmp(args[0], "-L") != 0)
    return (-1);
  write(1, "adieu\n", 8);
  if ((square->L = getnbr(args[1])) <= 0)
    return (my_puterror("invalid size for -L\n"));
  return (0);
}

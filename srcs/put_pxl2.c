/*
** mlx_fct.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Fri Jul 18 03:34:29 2014 paul vidal
** Last update Fri Jul 18 06:37:09 2014 paul vidal
*/

#include "square.h"

int	key_hook2(int keycode, t_square *square)
{
  if (keycode == 65307)
    {
      mlx_destroy_window(square->mlx, square->win2);
      exit(0);
    }
  return (0);
}

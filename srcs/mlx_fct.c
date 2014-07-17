/*
** mlx_fct.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:29:14 2014 paul vidal
** Last update Thu Jul 17 19:28:35 2014 paul vidal
*/

#include "square.h"

int	key_hook(int keycode, t_square *square)
{
  if (keycode == 65436)
    return (1);
  if (keycode == 65433)
    return (2);
  if (keycode == 65435)
    return (3);
  if (keycode == 65307)
    {
      mlx_destroy_window(square->mlx, square->win);
      exit(0);
    }
  return (0);
}

int	expose_hook(t_square *square)
{
  return (mlx_put_image_to_window(square->mlx, square->win, square->img, 0, 0));
}

int	mouse_hook(int button, int x, int y, t_square *square)
{
  if (button == 1)
    {
      draw_square(square, x, y, RED);
      draw_square1(square, x, y, RED);
      draw_square2(square, x, y, RED);
      draw_square3(square, x, y, RED);
      circle(square, x, y, GREEN);
      tria(square, x, y, BLUE);
      return (mlx_put_image_to_window(square->mlx,
				      square->win, square->img, 0, 0));
    }
  return (square->sqr_size);
}

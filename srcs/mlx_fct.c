/*
** mlx_fct.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:29:14 2014 paul vidal
** Last update Fri Jul 18 06:40:28 2014 paul vidal
*/

#include "square.h"

int	key_hook(int keycode, t_square *square)
{
  if (keycode == 65436)
    square->fig = 1;
  if (keycode == 65433)
    square->fig = 2;
  if (keycode == 65435)
    square->fig = 3;
  if (keycode == 65307)
    {
      mlx_destroy_window(square->mlx, square->win);
      exit(0);
    }
  return (0);
}

int	expose_hook(t_square *square)
{
  return (mlx_put_image_to_window(square->mlx,
				  square->win, square->img, 0, 0));
}

int	expose_hook2(t_square *square)
{
  return (mlx_put_image_to_window(square->mlx,
				  square->win2, square->img2, 0, 0));
}

int	mouse_hook(int button, int x, int y, t_square *square)
{
  if (button == 1)
    {
      if (square->fig == 1)
	{
	  draw_square(square, x, y, square->color);
	  draw_square1(square, x, y, square->color);
	  draw_square2(square, x, y, square->color);
	  draw_square3(square, x, y, square->color);
	}
      else if (square->fig == 2)
	circle(square, x, y, square->color);
      else if (square->fig == 3)
	tria(square, x, y, square->color);
      else
	{
	  draw_square(square, x, y, square->color);
	  draw_square1(square, x, y, square->color);
	  draw_square2(square, x, y, square->color);
	  draw_square3(square, x, y, square->color);
	}
      return (mlx_put_image_to_window(square->mlx,
				      square->win, square->img, 0, 0));
    }
  return (square->sqr_size);
}

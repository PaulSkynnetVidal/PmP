/*
** main.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:28:48 2014 paul vidal
** Last update Fri Jul 18 06:36:53 2014 paul vidal
*/

#include "square.h"

void   	init_square(t_square *square)
{
  square->size = 0;
  square->bpp = 0;
  square->end = 0;
  square->size2 = 0;
  square->bpp2 = 0;
  square->end2 = 0;
  square->sqr_size = 70;
  square->sqr_size2 = 40;
  square->l = 20;
  square->L = 20;
  square->l2 = 8;
  square->L2 = 3;
}

int	set_img(t_square *square)
{
  if ((square->size =
       (square->l * square->sqr_size) * (square->L * square->sqr_size)) <= 10)
    return (-1);
  if ((square->img =
       mlx_new_image(square->mlx, square->l * square->sqr_size,
		     square->L * square->sqr_size)) == NULL)
    return (-1);
  if ((square->win =
       mlx_new_window(square->mlx, square->l * square->sqr_size,
		      square->L * square->sqr_size, "Paint")) == NULL)
    return (-1);
  square->data = mlx_get_data_addr(square->img, &square->bpp,
				   &square->size, &square->end);
  if (!square->data)
    return (-1);
  return (0);
}

void	remp(t_square *square, int x, int y, unsigned int color)
{
  int	x1;
  int	y1;

  x = square->size;
  y = square->size / 5;
  x1 = 0;
  y1 = 0;
  while (x1 <= x)
    {
      while (y1 <= y)
	{
	  pxl(square, x1, y1, color);
	  y1++;
	}
      y1 = 0;
      x1++;
    }
}

void	put_img(t_square *square)
{
  remp(square, 0, 0, Wall_Color);
  mlx_put_image_to_window(square->mlx, square->win, square->img, 0, 0);
  palette(square);
  mlx_put_image_to_window(square->mlx, square->win2, square->img2, 0, 0);
  mlx_expose_hook(square->win, &expose_hook, square);
  mlx_key_hook(square->win, &key_hook, square);
  mlx_expose_hook(square->win2, &expose_hook, square);
  mlx_key_hook(square->win2, &key_hook, square);
  mlx_mouse_hook(square->win, &mouse_hook, square);
  mlx_mouse_hook(square->win2, &mouse_hook2, square);
  mlx_loop(square->mlx);
}

int		main(UNUSED int ac, UNUSED char **av)
{
  t_square	square;

  if ((square.mlx = mlx_init()) == NULL)
    return (my_puterror("Invalid env.\n"));
  init_square(&square);
  set_img2(&square);
  set_img(&square);
  put_img(&square);
  return (0);
}

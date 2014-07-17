/*
** main.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:28:48 2014 paul vidal
** Last update Thu Jul 17 11:39:38 2014 paul vidal
*/

#include "square.h"

void   	init_square(t_square *square)
{
  square->size = 0;
  square->bpp = 0;
  square->end = 0;
  square->sqr_size = 70;
  square->l = 25;
  square->L = 25;
}

int	set_square(t_square *square, char **av)
{
  int	value;

  if (av && (value = getnbr(av[0])) > 0)
    square->l = value;
  if (av && av[1] && (value = getnbr(av[1])) > 0)
    square->L = value;
  return (0);
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
		      square->L * square->sqr_size, "CARRE PERDANT")) == NULL)
    return (-1);
  square->data = mlx_get_data_addr(square->img, &square->bpp,
				   &square->size, &square->end);
  if (!square->data)
    return (-1);
  return (0);
}

void	put_img(t_square *square)
{
  mlx_put_image_to_window(square->mlx, square->win, square->img, 0, 0);
  mlx_expose_hook(square->win, &expose_hook, square);
  mlx_key_hook(square->win, &key_hook, square);
  mlx_mouse_hook(square->win, &mouse_hook, square);
  mlx_loop(square->mlx);
}

int		main(UNUSED int ac, UNUSED char **av)
{
  t_square	square;

  if ((square.mlx = mlx_init()) == NULL)
    return (my_puterror("Invalid env.\n"));
  init_square(&square);
  if (ac > 1)
    set_square(&square, &av[1]);
  set_img(&square);
  put_img(&square);
  return (0);
}

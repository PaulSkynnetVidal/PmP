/*
** main2.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 22:55:34 2014 paul vidal
** Last update Fri Jul 18 06:28:41 2014 paul vidal
*/

#include <square.h>

void		pxl2(t_square *square, int x, int y, unsigned int color)
{
  int		pixel;
  t_color	split;

  split.color = color;
  if ((pixel = x * (square->bpp2 / 8) + y * square->size2) < 0)
    return;
  square->data2[pixel] = split.part[0];
  square->data2[pixel + 1] = split.part[1];
  square->data2[pixel + 2] = split.part[2];
  square->data2[pixel + 3] = split.part[3];
}

int	set_img2(t_square *square)
{
  if ((square->size2 =
       (square->l2 * square->sqr_size2) *
       (square->L2 * square->sqr_size2)) <= 10)
    return (-1);
  if ((square->img2 =
       mlx_new_image(square->mlx, square->l2 * square->sqr_size2,
		     square->L2 * square->sqr_size2)) == NULL)
    return (-1);
  if ((square->win2 =
       mlx_new_window(square->mlx, square->l2 * square->sqr_size2,
		      square->L2 * square->sqr_size2, "Colors")) == NULL)
    return (-1);
  square->data2 = mlx_get_data_addr(square->img2, &square->bpp2,
				   &square->size2, &square->end2);
  if (!square->data2)
    return (-1);
  return (0);
}

void	remp1(t_square *square, int x, int y, unsigned int color)
{
  int	x1;
  int	y1;

  x1 = 0;
  y1 = 0;
  while (x1 <= x)
    {
      while (y1 <= y)
	{
	  pxl2(square, x1, y1, color);
	  y1++;
	}
      y1 = 0;
      x1++;
    }
}

void		palette(t_square *square)
{
  remp1(square, 200, 100, ORANGE);
  remp1(square, 200, 50, PURPLE);
  remp1(square, 150, 100, LEMON);
  remp1(square, 150, 50, RED);
  remp1(square, 100, 100, PINK);
  remp1(square, 100, 50, BLUE);
  remp1(square, 50, 100, GREEN);
  remp1(square, 50, 50, BLACK);
}

int	mouse_hook2(int button, int x, int y, t_square *square)
{
  if (button == 1)
    {
      if (x >= 0 && x < 50 && y >= 0 && y < 50)
	square->color = BLACK;
      if (x >= 0 && x < 50 && y >= 50 && y < 100)
	square->color = GREEN;
      if (x >= 50 && x < 100 && y >= 0 && y < 50)
	square->color = BLUE;
      if (x >= 50 && x < 100 && y >= 50 && y < 100)
	square->color = PINK;
      if (x >= 100 && x < 150 && y >= 0 && y < 50)
	square->color = RED;
      if (x >= 100 && x < 150 && y >= 50 && y < 100)
	square->color = LEMON;
      if (x >= 150 && x < 200 && y >= 0 && y < 50)
	square->color = PURPLE;
      if (x >= 150 && x < 200 && y >= 50 && y < 100)
	square->color = ORANGE;
      return (mlx_put_image_to_window(square->mlx,
				      square->win, square->img, 0, 0));
    }
  return (square->sqr_size);
}

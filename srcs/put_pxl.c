/*
** put_pxl.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:31:42 2014 paul vidal
** Last update Thu Jul 17 20:56:59 2014 paul vidal
*/

#include "square.h"

void		pxl(t_square *square, int x, int y, unsigned int color)
{
  int		pixel;
  t_color	split;

  split.color = color;
  if ((pixel = x * (square->bpp / 8) + y * square->size) < 0)
    return;
  square->data[pixel] = split.part[0];
  square->data[pixel + 1] = split.part[1];
  square->data[pixel + 2] = split.part[2];
  square->data[pixel + 3] = split.part[3];
}

void	draw_square(t_square *square, int x, int y, unsigned int color)
{
  int	x_end;
  int	y_end;
  int	save;

  x_end = x + square->sqr_size / 2;
  y_end = y + square->sqr_size / 2;
  x = x - square->sqr_size / 2;
  while (x < (x_end - (square->sqr_size - 2)))
    {
      save = y - square->sqr_size / 2;
      while (save < y_end)
	{
	  pxl(square, x, save, color);
	  ++save;
	}
      ++x;
    }
}

void	draw_square1(t_square *square, int x, int y, unsigned int color)
{
  int	x_end;
  int	y_end;
  int	save;

  x_end = x + square->sqr_size / 2;
  y_end = y + square->sqr_size / 2;
  x = x - square->sqr_size / 2;
  while (x < x_end)
    {
      save = y - square->sqr_size / 2;
      while (save < (y_end - (square->sqr_size - 2)))
	{
	  pxl(square, x, save, color);
	  ++save;
	}
      ++x;
    }
}

void	draw_square2(t_square *square, int x, int y, unsigned int color)
{
  int	x_end;
  int	y_end;
  int	save;

  x_end = x + square->sqr_size / 2;
  y_end = y + square->sqr_size / 2;
  x = x - square->sqr_size / 2;
  while (x < x_end)
    {
      save = y + square->sqr_size / 2.1;
      while (save < y_end)
	{
	  pxl(square, x, save, color);
	  ++save;
	}
      ++x;
    }
}

void	draw_square3(t_square *square, int x, int y, unsigned int color)
{
  int	x_end;
  int	y_end;
  int	save;

  x_end = x + square->sqr_size / 2;
  y_end = y + square->sqr_size / 2;
  x = x + square->sqr_size / 2.1;
  while (x < x_end)
    {
      save = y - square->sqr_size / 2;
      while (save < y_end)
	{
	  pxl(square, x, save, color);
	  ++save;
	}
      ++x;
    }
}

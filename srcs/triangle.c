/*
** triangle.c for pisc in /home/vidal_p/rendu/Pmp/srcs
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 15:47:18 2014 paul vidal
** Last update Thu Jul 17 18:47:38 2014 paul vidal
*/

#define _BSD_SOURCE
#include "square.h"

void	tria(t_square *square, int x, int y, unsigned int color)
{
  int	x1;
  int	y2;

  x1 = x;
  y2 = y - 40;
  while (y2 < y + 20)
    pxl(square, x1--, y2++, color);
  x1 = x;
  y2 = y - 40;
  while ( y2 < y + 20)
    pxl(square, x1++, y2++, color);
  x1 = x - 60;
  while (x1 != x + 60)
    pxl(square, x1++, y2, color);
}

void	circle(t_square *square, int x, int y, unsigned int color)
{
  float	angle;
  float	ray;
  float	x1;
  float	y2;

  angle = 0;
  ray = 50;
  while (angle < 360)
    {
      x1 = x + ray * cosf(angle);
      y2 = y + ray * sinf(angle);
      angle++;
      pxl(square, x1, y2, color);
    }
}

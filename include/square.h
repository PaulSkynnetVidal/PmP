/*
** square.h for pisc in /home/vidal_p/rendu/Pmp/include
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:28:13 2014 paul vidal
** Last update Thu Jul 17 19:27:13 2014 paul vidal
*/

#ifndef	SQUARE_H_
# define SQUARE_H_

# include	<mlx.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>

# define	UNUSED	__attribute__((unused))
# define	RED	0xFF0000
# define	BLUE	0x0000FF
# define	GREEN	0x00FF00

typedef	struct	s_square
{
  void		*mlx;
  void		*img;
  void		*win;
  int		size;
  int		bpp;
  int		end;
  char		*data;
  int		sqr_size;
  int		l;
  int		L;
  int		keycode;
}		t_square;

typedef	union	u_color
{
  unsigned int	color;
  unsigned char	part[4];
}		t_color;

int		my_strlen(char *);
int		my_putstr(char *);
int		my_puterror(char *);
int		my_putchar(char);
int		putnbr(int);
int		getnbr(char *);
int		my_strcmp(char *, char *);

void		pxl(t_square *, int, int, unsigned int);

int		expose_hook(t_square *);
int		key_hook(int, t_square *);
int		mouse_hook(int, int, int, t_square *);

void		draw_square(t_square *, int, int, unsigned int);
void		draw_square1(t_square *, int, int, unsigned int);
void		draw_square2(t_square *, int, int, unsigned int);
void		draw_square3(t_square *, int, int, unsigned int);

void		tria(t_square *, int, int, unsigned int);
void		circle(t_square *, int, int, unsigned int);

int		get_l_size(t_square *, char **);
int		get_L_size(t_square *, char **);

#endif	/* !SQUARE_H_ */

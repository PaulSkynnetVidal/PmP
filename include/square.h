/*
** square.h for pisc in /home/vidal_p/rendu/Pmp/include
** 
** Made by paul vidal
** Login   <vidal_p@epitech.net>
** 
** Started on  Thu Jul 17 09:28:13 2014 paul vidal
** Last update Fri Jul 18 06:35:00 2014 paul vidal
*/

#ifndef	SQUARE_H_
# define SQUARE_H_

# include	<mlx.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>

# define	UNUSED		__attribute__((unused))
# define	RED		0xFF0000
# define	BLUE		0x0000FF
# define	GREEN		0x00FF00
# define	PINK		0xCC0066
# define	LEMON		0xFFFF00
# define	ORANGE		0xFF3300
# define	BLACK		0x000000
# define	PURPLE		0x6600CC
# define	Wall_Color	0xFFFFFF

typedef	struct	s_square
{
  void		*mlx;
  void		*img;
  void		*win;
  void		*win2;
  void		*img2;
  int		size;
  int		bpp;
  int		end;
  char		*data;
  int		size2;
  int		bpp2;
  int		end2;
  char		*data2;
  int		sqr_size;
  int		sqr_size2; 
  int		l;
  int		L;
  int		l2;
  int		L2;
  int		keycode;
  int		fig;
  int		color;
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
int		expose_hook2(t_square *);

/*
put_pxl
 */
void		draw_square(t_square *, int, int, unsigned int);
void		draw_square1(t_square *, int, int, unsigned int);
void		draw_square2(t_square *, int, int, unsigned int);
void		draw_square3(t_square *, int, int, unsigned int);

/*
triangle.c
 */
void		tria(t_square *, int, int, unsigned int);
void		circle(t_square *, int, int, unsigned int);

/*
main2.c
 */
int		set_img2(t_square *);
void		pxl2(t_square *, int, int, unsigned int);
void		palette(t_square *);
void		remp1(t_square *, int x, int y, unsigned int);
int		mouse_hook2(int, int, int, t_square *);

#endif	/* !SQUARE_H_ */

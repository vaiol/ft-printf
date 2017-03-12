#ifndef FLOAT_H
# define FLOAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <zconf.h>

/* Some useful macros */

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define CONCAT2(x,y) x ## y
#define CONCAT(x,y) CONCAT2(x,y)

/* Convenient bit representation for modifier flags, which all fall
 * within 31 codepoints of the space character. */

#define ZERO_PAD   (1U << ('0'-' '))
#define LEFT_ADJ   (1U << ('-'-' '))

typedef struct	s_arrays
{
	char		*copy;
	uint32_t	*a;
	uint32_t	*d;
	uint32_t	*r;
	uint32_t	*z;
}				t_arrays;

typedef struct	s_indecies
{
	char		*prefix;
	int			pl;
	int			e;
	int			e2;
	int 		i;
	int			j;
}				t_indecies;

typedef struct	s_bufs
{
	char	buf[9 + LDBL_MANT_DIG / 4];
	char	ebuf0[sizeof(int) * 3];
	char	*ebuf;
}				t_bufs;

void			rounder(int p, int t, t_arrays *arrays, t_indecies *indecies);
void			handle_g(int *p, t_arrays *arrays, int *t, t_indecies *indecies);
void 			handle_f(t_arrays *arrays, int p, t_bufs *bufs);
void 			handle_e(t_arrays *arrays, int p, char *estr, t_bufs *bufs);
void			out(char **sp, const char *s, size_t l);
void			pad(char **sp, char c, int w, int l, int fl);
char			*fmt_u(uintmax_t x, char *s);
int				infinite(long double nbr, int t, char *sp, t_indecies *indecies);
void			parse_int(t_indecies *indecies, t_arrays *arrays);
void			parse_fract(t_indecies *indecies, t_arrays *arrays, int t, int p);
void			next_function(t_indecies *indecies, t_arrays *arrays, int p, int t);

#endif

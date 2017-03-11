//
// Created by Alexander Stepanov on 3/10/17.
//

#include <printf.h>
#include "libft/libft.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

char	*handle_float(double nbr, int precision);



int main(void)
{
//	int r1 = printf("%.0p %#.0p %.0p %#.0p %.0x %#.0x %.0x %#.0x\n", NULL, NULL, 42, 42, 0, 0, 42, 42);
//	int r2 = ft_printf("%.0p %#.0p %.0p %#.0p %.0x %#.0x %.0x %#.0x\n", NULL, NULL, 42, 42, 0, 0, 42, 42);
//	r1 == r2 ? printf(GRN "OK\n" RESET) : ft_printf(RED "NEOK: %d %d" RESET, r1, r2);
//	r1 = printf("%.4p %#.4p %.4p %#.4p %.4x %#.4x %.4x %#.4x\n", NULL, NULL, 42, 42, 0, 0, 42, 42);
//	r2 = ft_printf("%.4p %#.4p %.4p %#.4p %.4x %#.4x %.4x %#.4x\n", NULL, NULL, 42, 42, 0, 0, 42, 42);
//	r1 == r2 ? printf(GRN "OK\n" RESET) : ft_printf(RED "NEOK: %d %d" RESET, r1, r2);
//
//	r1 = printf("%#.3X\n", 1);
//	r2 = ft_printf("%#.3X\n", 1);
//	r1 == r2 ? printf(GRN "OK\n" RESET) : ft_printf(RED "NEOK: %d %d" RESET, r1, r2);

	double f = -42.42;
	printf("%f\n", f);

	printf("%s\n", handle_float(f, 6));

}
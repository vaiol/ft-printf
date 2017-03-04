#include "ft_printf.h"
#include <printf.h>
#include <stdio.h>
#include <locale.h>



//long long:
//9223372036854775807
//-9223372036854775808



int 	main(int argc, char **argv)
{
	int r1 = 0;
	int r2 = 0;
	long n = 9223372036854775800;
	wint_t wc = L'\x3b1';

	char str[] = "Привеα";
	size_t i = 2343876578909876578;
	setlocale(LC_ALL, "en_US.UTF-8");
//	unsigned int jj = -123;
//	char *format = "START: %ls 123 %s\t%c - hi %p : %ld, i = %zu %%\n";
//	r1 = 	printf(format, ws, str, 'f', ws, n, i);
//	r2 = ft_printf(format, ws, str, 'f', ws, n, i);
//	ft_printf("%d %d\n", r1, r2);
//	unsigned char	w[] = "\0\0\0\0";
	char *format = "%0100.20c\n";
	wchar_t *wstr = (wchar_t *)L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	r1 = printf(format, '1');
	r2 = ft_printf(format, '1');
	printf("\n%d %d\n", r1, r2);
}


//-00000123
// 00000123
//unsigned int	ui = 10;
//int				i = 10;
//
//
//10000000 00000000 00000000 000100100;


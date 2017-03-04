#include "ft_printf.h"
#include <printf.h>
#include <stdio.h>
#include <locale.h>

void	test_basic()
{
	int r1 = 0;
	int r2 = 0;

	printf("-WSTR-TEST-\n");
	char *format = "START: %ls 123 %s\t%c - hi %p : %ld, i = %zu %%\n";
	r1 = printf(format);
	r2 = ft_printf(format);
	r1 == r2 ? printf("OK\n") : printf("NEOK: %d %d\n", r1, r2);
}

void	test_wstr()
{
	int r1 = 0;
	int r2 = 0;
	wchar_t *wstr = (wchar_t *)L" 123 ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	printf("-WSTR-TEST-\n");
	char *format = "123 %050.21ls 123\n";
	r1 = printf(format, wstr);
	r2 = ft_printf(format, wstr);
	r1 == r2 ? printf("OK\n") : printf("NEOK: %d %d\n", r1, r2);
}

void	test_wchr()
{
	int r1 = 0;
	int r2 = 0;
	wint_t wc = L'\x3b1';
	printf("-WCHR-TEST-\n");
	char *format = "123 %010.0lc 123\n";
	r1 = printf(format, wc);
	r2 = ft_printf(format, wc);
	r1 == r2 ? printf("OK\n") : printf("NEOK: %d %d\n", r1, r2);

}

void	test_str()
{
	int r1 = 0;
	int r2 = 0;
	char *str = " 1 ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	printf("-STR-TEST-\n");
	char *format = "123 %050.21s 123\n";
	r1 = printf(format, str);
	r2 = ft_printf(format, str);
	r1 == r2 ? printf("OK\n") : printf("NEOK: %d %d\n", r1, r2);
}

int 	main(int argc, char **argv)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	test_str();
	test_wstr();
	test_wchr();

}
//long long:
//9223372036854775807
//-9223372036854775808

//long n = 9223372036854775800;
//size_t i = 2343876578909876578;

#include "ft_printf.h"
#include <locale.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RES "\x1B[0m"

/*
** long long:
** 9223372036854775807
** -9223372036854775808
*/

void	test_basic()
{
	int r1 = 0;
	int r2 = 0;
	printf(CYN "-BASIC-TEST-\n" RES);
	char *format = "START: %s 123 %s\t%c - hi %p : %d, i = %zu %%\n";
	r1 = printf(format, "Hacha", "ALOHA", 'Q', "p", 2345434);
	r2 = ft_printf(format, "Hacha", "ALOHA", 'Q', "p", 2343346);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_wstr()
{
	int r1 = 0;
	int r2 = 0;
	wchar_t *wstr = (wchar_t *)L" 123 ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	printf(CYN "-WSTR-TEST-\n" RES);
	char *format = "123 %050.21ls 123\n";
	r1 = printf(format, wstr);
	r2 = ft_printf(format, wstr);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_wchr()
{
	int r1 = 0;
	int r2 = 0;
	wint_t wc = L'\x3b1';
	printf(CYN "-WCHR-TEST-\n" RES);
	char *format = "123 %02.0lc 123\n";
	r1 = printf(format, wc);
	r2 = ft_printf(format, wc);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);

}

void	test_str()
{
	int r1 = 0;
	int r2 = 0;
	char *str = " 1 ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	printf(CYN "-STR-TEST-\n" RES);
	char *format = "123 %050.21s 123\n";
	r1 = printf(format, str);
	r2 = ft_printf(format, str);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_nbr()
{
	int r1 = 0;
	int r2 = 0;
	int nbr0 = 2147483647;
	int nbr1 = -2147483648;
	int nbr2 = 0;
	int nbr3 = 10;
	int nbr4 = 104657;
	printf(CYN "-NBR-TEST-\n" RES);
	char *format = "123 %030.21d %019d % .1d %-5d %+d\n";
	r1 = printf(format, nbr0, nbr1, nbr2, nbr3, nbr4);
	r2 = ft_printf(format, nbr0, nbr1, nbr2, nbr3, nbr4);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_nbr_size()
{
	int r1 = 0;
	int r2 = 0;
	long l = 9223372036854775807LL;
	long long ll = -9223372036854775808LLU;
	char hh = -128;
	short h = 32767;
	intmax_t j = 9223372036854775807LL;
	ssize_t z = -9223372036854775807LL;
	printf(CYN "-NBR-SIZE-TEST-\n" RES);
	char *format = "123 %ld %lld %hhd %hd %jd %zd\n";
	r1 = printf(format, l, ll, hh, h, j, z);
	r2 = ft_printf(format, l, ll, hh, h, j, z);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_unsigned()
{
	int r1 = 0;
	int r2 = 0;
	unsigned int nbr0 = 2147483648 * 2 - 1;
	unsigned int nbr1 = -1345;
	unsigned int nbr2 = 0;
	unsigned int nbr3 = 10;
	unsigned int nbr4 = 10465756;
	printf(CYN "-UNSIGNED-TEST-\n" RES);
	char *format = "123 %030.21u %019u % .1u %-5u %+u\n";
	r1 = printf(format, nbr0, nbr1, nbr2, nbr3, nbr4);
	r2 = ft_printf(format, nbr0, nbr1, nbr2, nbr3, nbr4);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_unsigned_size()
{
	int r1 = 0;
	int r2 = 0;
	unsigned long l = -1;
	unsigned long long ll = 0;
	unsigned char hh = -128;
	unsigned short h = 65535;
	uintmax_t j = 9223372036854775809LLU;
	size_t z = -1235;
	printf(CYN "-UNSIGNED-SIZE-TEST-\n" RES);
	char *format = "123 %lu %llu %hhu %hu %ju %zu\n";
	r1 = printf(format, l, ll, hh, h, j, z);
	r2 = ft_printf(format, l, ll, hh, h, j, z);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_octal()
{
	int r1 = 0;
	int r2 = 0;
	unsigned int nbr0 = 2147483648 * 2 - 1;
	unsigned int nbr1 = -156777;
	unsigned int nbr2 = 0;
	unsigned int nbr3 = 10;
	unsigned int nbr4 = 10465756;
	printf(CYN "-OCTAL-TEST-\n" RES);
	char *format = "123 %#030.21o %#o % #.1o %#-5o %+o\n";
	r1 = printf(format, nbr0, nbr1, nbr2, nbr3, nbr4);
	r2 = ft_printf(format, nbr0, nbr1, nbr2, nbr3, nbr4);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_hexa()
{
	int r1 = 0;
	int r2 = 0;
	unsigned int nbr0 = 2147483648 * 2 - 1;
	unsigned int nbr1 = -156777;
	unsigned int nbr2 = 0;
	unsigned int nbr3 = 10;
	unsigned int nbr4 = 10465756;
	printf(CYN "-HEXA-TEST-\n" RES);
	char *format = "123 %#.9x %#012X % #.1x %#-5X %+07x\n";
	r1 = printf(format, nbr0, nbr1, nbr2, nbr3, nbr4);
	r2 = ft_printf(format, nbr0, nbr1, nbr2, nbr3, nbr4);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	bonus_apostrophe()
{
	int r1 = 0;
	int r2 = 0;
	unsigned int nbr0 = 2147483648 * 2 - 1;
	unsigned int nbr1 = -156777;
	unsigned int nbr2 = 0;
	unsigned int nbr3 = 10;
	unsigned int nbr4 = 10465756;
	printf(CYN "-APOSTROPHE-TEST-\n" RES);
	char *format = "123 %#'.9d %#'012u % #'.1o %#'-5x %+'07u %'d %'d %'d %'d %'d\n";
	r1 = printf(format, nbr0, nbr1, nbr2, nbr3, nbr4, 1, 12, 123, 1234, 12345);
	r2 = ft_printf(format, nbr0, nbr1, nbr2, nbr3, nbr4, 1, 12, 123, 1234, 12345);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_char()
{
	int r1 = 0;
	int r2 = 0;
	char c = 'O';
	printf(CYN "-CHR-TEST-\n" RES);
	char *format = "123 %02.0c %-3c %+2c % 2c %.4c %+04.3c123\n";
	r1 = printf(format, c, c, c, c, c, c);
	r2 = ft_printf(format, c, c, c, c, c, c);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

void	test_memory()
{
	int r1 = 0;
	int r2 = 0;
	char *mem = "123";
	printf(CYN "-MEM-TEST-\n" RES);
	char *format = "123    %020p   44\n";
	r1 = printf(format, mem);
	r2 = ft_printf(format, mem);
	r1 == r2 ? printf(GRN "OK\n\n" RES) : printf(RED "NEOK: %d %d\n\n" RES, r1, r2);
}

int 	main(int argc, char **argv)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	test_basic();
	if (argc > 1)
	{
		test_wstr();
		test_wchr();
	}
	test_char();
	test_str();
	test_nbr();
	test_nbr_size();
	test_unsigned();
	test_unsigned_size();
	test_octal();
	test_hexa();
	test_memory();
	if (argc > 2)
	{
		bonus_apostrophe();
	}
	return (0);
}

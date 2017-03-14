#include <locale.h>
#include "libft/libft.h"

int	main(void)
{
    double test[] = { /*1.0 / -0.0,*/
					  /*-67454675565667556754654675467556756750.12423453452545,
					  5.0,*/
					  12.123456,
					  0.00000000000000245,
					  45252.6999996999999,
					  0.0000065456789876545678987654567898765
	};
    size_t i;

//    int w = 50;
//    int p = -20;
//    for (i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
//
//        ft_printf("%*.*F\n", w, p, test[i]);
//        printf("%*.*F\n\n", w, p, test[i]);
//    }
//
//    for (i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
//
//        ft_printf("%*.*F\n", w, p, test[i]);
//        printf("%*.*F\n\n", w, p, test[i]);
//    }
//
//    for (i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
//
//        ft_printf("%*.*g\n", w, p, test[i]);
//        printf("%*.*a\n\n", w, p, test[i]);
//    }

	setlocale(LC_ALL, "en_US.UTF-8");
	ft_printf("{red}%f{eoc}\n", -13456567);
	printf("%f", -13456567);
    return 0;
}

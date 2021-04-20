#include "libasm.h"
#include <stdio.h>

int main(void)
{
	printf("FT_STRLEN\n");
	printf("Empty string : %lu\n", ft_strlen(""));
	printf("\"salut ca va ?\" : %lu\n", ft_strlen("salut ca va ?"));
}

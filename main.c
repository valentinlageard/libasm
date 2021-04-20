/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:34:47 by valentin          #+#    #+#             */
/*   Updated: 2021/04/20 18:34:55 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>

int	main(void)
{
	printf("FT_STRLEN\n");
	printf("Empty string : %lu\n", ft_strlen(""));
	printf("\"salut ca va ?\" : %lu\n", ft_strlen("salut ca va ?"));

	printf("\nFT_STRCMP\n");
	printf("ft_strcmp : \"salut\" VS \"salut\" : %d\n", ft_strcmp("salut", "salut"));
	printf("strcmp    : \"salut\" VS \"salut\" : %d\n", strcmp("salut", "salut"));
	printf("ft_strcmp : \"salut\" VS \"salu\" : %d\n", ft_strcmp("salut", "salu"));
	printf("strcmp    : \"salut\" VS \"salu\" : %d\n", strcmp("salut", "salu"));
	printf("ft_strcmp : \"salu\" VS \"salut\" : %d\n", ft_strcmp("salu", "salut"));
	printf("strcmp    : \"salu\" VS \"salut\" : %d\n", strcmp("salu", "salut"));
	printf("ft_strcmp : \"\" VS \"\" : %d\n", ft_strcmp("", ""));
	printf("strcmp    : \"\" VS \"\" : %d\n", strcmp("", ""));
}

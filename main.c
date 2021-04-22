/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:34:47 by valentin          #+#    #+#             */
/*   Updated: 2021/04/22 17:02:49 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <errno.h>

void	print_dline(void)
{
	printf("==============================\n");
}

void	print_line(void)
{
	printf("------------------------------\n");
}

int		main(void)
{
	char dest[20];

	printf("\n");
	print_dline();
	printf("FT_STRLEN\n");
	print_dline();
	printf("\"\" : %lu\n", ft_strlen(""));
	print_line();
	printf("\"salut ca va ?\" : %lu\n", ft_strlen("salut ca va ?"));

	printf("\n");
	print_dline();
	printf("FT_STRCMP\n");
	print_dline();
	printf("ft_strcmp : \"salut\" VS \"salut\" : %d\n",
			ft_strcmp("salut", "salut"));
	printf("strcmp    : \"salut\" VS \"salut\" : %d\n",
			strcmp("salut", "salut"));
	print_line();
	printf("ft_strcmp : \"salut\" VS \"salu\" : %d\n",
			ft_strcmp("salut", "salu"));
	printf("strcmp    : \"salut\" VS \"salu\" : %d\n",
			strcmp("salut", "salu"));
	print_line();
	printf("ft_strcmp : \"salu\" VS \"salut\" : %d\n",
			ft_strcmp("salu", "salut"));
	printf("strcmp    : \"salu\" VS \"salut\" : %d\n",
			strcmp("salu", "salut"));
	print_line();
	printf("ft_strcmp : \"\" VS \"\" : %d\n",
			ft_strcmp("", ""));
	printf("strcmp    : \"\" VS \"\" : %d\n",
			strcmp("", ""));

	printf("\n");
	print_dline();
	printf("FT_STRCPY\n");
	print_dline();
	printf("ft_strcpy : \"salut ca va ?\" : \"%s\"\n",
			ft_strcpy(dest, "salut ca va ?"));
	printf("strcpy    : \"salut ca va ?\" : \"%s\"\n",
			strcpy(dest, "salut ca va ?"));
	print_line();
	printf("ft_strcpy : \"\" : \"%s\"\n", ft_strcpy(dest, ""));
	printf("strcpy    : \"\" : \"%s\"\n", strcpy(dest, ""));

	printf("\n");
	print_dline();
	printf("FT_WRITE\n");
	print_dline();
	printf("ft_write : \"salut ca va ?\" (13) -> stdout : \n");
	printf("| [return : %ld]\n", ft_write(0, "salut ca va ?", 13));
	printf("errno : %d\n", errno);
	printf("write : \"salut ca va ?\" (13) -> stdout : \n");
	printf("| [return : %ld]\n", write(0, "salut ca va ?", 13));
	printf("errno : %d\n", errno);
	print_line();
	printf("ft_write : \"salut ca va ?\" (1) -> stdout : \n");
	printf("| [return : %ld]\n", ft_write(0, "salut ca va ?", 1));
	printf("errno : %d\n", errno);
	printf("write : \"salut ca va ?\" (1) -> stdout : \n");
	printf("| [return : %ld]\n", write(0, "salut ca va ?", 1));
	printf("errno : %d\n", errno);
	print_line();
	printf("ft_write : \"salut ca va ?\" (0) -> stdout : \n");
	printf("| [return : %ld]\n", ft_write(0, "salut ca va ?", 0));
	printf("errno : %d\n", errno);
	printf("write : \"salut ca va ?\" (0) -> stdout : \n");
	printf("| [return : %ld]\n", write(0, "salut ca va ?", 0));
	printf("errno : %d\n", errno);
	print_line();
	printf("ft_write : \"\" (0) -> stdout : \n");
	printf("| [return : %ld]\n", ft_write(0, "", 0));
	printf("errno : %d\n", errno);
	printf("write : \"\" (0) -> stdout : \n");
	printf("| [return : %ld]\n", write(0, "", 0));
	printf("errno : %d\n", errno);
	print_line();
	printf("ft_write : \"salut ca va ?\" (13) -> invalid fd : \n");
	printf("| [return : %ld]\n", ft_write(100, "salut ca va ?", 13));
	printf("errno : %d\n", errno);
	printf("write : \"salut ca va ?\" (13) -> invalid fd : \n");
	printf("| [return : %ld]\n", write(100, "salut ca va ?", 13));
	printf("errno : %d\n", errno);
}

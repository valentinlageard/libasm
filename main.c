/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:34:47 by valentin          #+#    #+#             */
/*   Updated: 2021/04/23 18:14:01 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void	print_title(char *title)
{
	printf("\n");
	printf("============================================================\n");
	printf("%s\n", title);
	printf("============================================================\n");
}

void	print_line(void)
{
	printf("------------------------------------------------------------\n");
}

void	test_ft_strlen(char *str)
{
	printf("ft_strlen(\"%s\") -> %lu\n", str, ft_strlen(str));
	print_line();
}

void	test_ft_strcmp(char *s1, char *s2)
{
	printf("ft_strcmp(\"%s\", \"%s\") -> %d\n", s1, s2, ft_strcmp(s1, s2));
	printf("strcmp(\"%s\", \"%s\") -> %d\n", s1, s2, strcmp(s1, s2));
	print_line();
}

void	test_ft_strcpy(char *dst1, char *dst2, char *s)
{
	printf("ft_strcpy(dst1[20], \"%s\") -> \"%s\"\n", s, ft_strcpy(dst1, s));
	printf("strcpy(dst2[20], \"%s\") -> \"%s\"\n", s, strcpy(dst2, s));
	print_line();
}

void	test_ft_write(int fd, char *s, size_t count)
{
	int	error1;
	int error2;

	errno = 0;
	printf("ft_write(%i, \"%s\", %lu) ->\n", fd, s, count);
	error1 = ft_write(fd, s, count);
	printf("\nreturn : %i, errno : %d\n", error1, errno);
	errno = 0;
	printf("write(%i, \"%s\", %lu) ->\n", fd, s, count);
	error2 = write(fd, s, count);
	printf("\nreturn : %i, errno : %d\n", error1, errno);
	print_line();
}

void	test_ft_write_mulfd(int fd1, int fd2, char *s, size_t count)
{
	int	error1;
	int error2;

	errno = 0;
	printf("ft_write(%i, \"%s\", %lu) ->\n", fd1, s, count);
	error1 = ft_write(fd1, s, count);
	printf("\nreturn : %i, errno : %d\n", error1, errno);
	errno = 0;
	printf("write(%i, \"%s\", %lu) ->\n", fd2, s, count);
	error2 = write(fd2, s, count);
	printf("\nreturn : %i, errno : %d\n", error1, errno);
	print_line();
}

void	test_ft_read(int fd1, int fd2, char *buf1, char *buf2, size_t count)
{
	int	error1;
	int error2;

	memset(buf1, 0, 20);
	memset(buf2, 0, 20);
	errno = 0;
	printf("ft_read(%i, buf1[20], %lu) ->\n", fd1, count);
	error1 = ft_read(fd1, buf1, count);
	printf("\"%s\"\nreturn : %i, errno : %d\n", buf1, error1, errno);
	errno = 0;
	printf("read(%i, buf2[20], %lu) ->\n", fd2, count);
	error2 = read(fd2, buf2, count);
	printf("\"%s\"\nreturn : %i, errno : %d\n", buf2, error1, errno);
	print_line();
}

void	test_ft_strdup(char *s)
{
	char *s1;
	char *s2;

	s1 = ft_strdup(s);
	s2 = strdup(s);
	printf("ft_strdup(\"%s\") -> \"%s\"\n", s, s1);
	printf("strdup(\"%s\") -> \"%s\"\n", s, s2);
	free(s1);
	free(s2);
	print_line();
}

int		main(void)
{
	char	dst1[20];
	char	dst2[20];
	int		fd1;
	int		fd2;

	print_title("FT_STRLEN");
	test_ft_strlen("");
	test_ft_strlen("salut ca va ?");

	print_title("FT_STRCMP");
	test_ft_strcmp("salut", "salut");
	test_ft_strcmp("salut", "salu");
	test_ft_strcmp("salu", "salut");
	test_ft_strcmp("", "");

	print_title("FT_STRCPY");
	test_ft_strcpy(dst1, dst2, "salut ca va ?");
	test_ft_strcpy(dst1, dst2, "");

	fd1 = open("test1.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	fd2 = open("test2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	print_title("FT_WRITE");
	test_ft_write(0, "salut ca va ?", 13);
	test_ft_write(0, "salut ca va ?", 1);
	test_ft_write(0, "salut ca va ?", 0);
	test_ft_write(0, "", 0);
	test_ft_write(-1, "salut ca va ?", 13);
	test_ft_write_mulfd(fd1, fd2, "salut ca va ?", 13);
	close(fd1);
	close(fd2);

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	print_title("FT_READ");
	test_ft_read(fd1, fd2, dst1, dst2, 13);
	test_ft_read(0, 0, dst1, dst2, 13);
	test_ft_read(-1, -1, dst1, dst2, 13);
	close(fd1);
	close(fd2);

	print_title("FT_STRDUP");
	test_ft_strdup("salut ca va ?");
	test_ft_strdup("");
	test_ft_strdup("unephraselooooooooooooooooooooooooooooooooooooooooooongue");
}

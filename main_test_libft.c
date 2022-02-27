/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macasubo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:47:15 by macasubo          #+#    #+#             */
/*   Updated: 2019/11/12 17:55:25 by macasubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>
#include "libft.h"

void		red()
{
	printf("\033[1;31m");
}

void		green()
{
	printf("\033[0;32m");
}

void		reset()
{
	printf("\033[0m");
}

void		fail(int n)
{
	printf("test %d: ", n);
	red();
	printf("FAIL\n");
	reset();
}

void		pass(int n)
{
	printf("test %d: ", n);
	green();
	printf("PASS\n");
	reset();
}

void		test_memset()
{
	char		str1[42] = "salut c'est cool";
	char		str2[42] = "salut c'est cool";

	if (strncmp((char *)ft_memset((void *)str1, 'a', (0)), (char *)memset((void *)str2, 'a', (0)), 42) == 0)
		pass(1);
	else
		fail(1);
	
	if (strncmp((char *)ft_memset((void *)str1, 'a', 42), (char *)memset((void *)str2, 'a', 42), 42) == 0)
		pass(2);
	else
		fail(2);
	if (strncmp((char *)ft_memset((void *)str1, 0, 42), (char *)memset((void *)str2, 0, 42), 42) == 0)
		pass(3);
	else
		fail(3);
	if (strncmp((char *)ft_memset((void *)str1, -20, 42), (char *)memset((void *)str2, -20, 42), 42) == 0)
		pass(4);
	else
		fail(4);
}

void		test_bzero()
{
	char	str1[42] = {4};
	char	str2[42] = {4};

	ft_bzero((void *)str1, (0));
	bzero((void *)str2, (0));
	if (strncmp(str1, str2, 42) == 0)
		pass(1);
	else
		fail(1);
	ft_bzero((void *)str1, 1);
	bzero((void *)str2, 1);
	if (strncmp(str1, str2, 42) == 0)
		pass(2);
	else
		fail(2);
	ft_bzero((void *)str1, 42);
	bzero((void *)str2, 42);
	if (strncmp(str1, str2, 42) == 0)
		pass(3);
	else
		fail(3);
}

void		test_memcpy()
{
	char	dst1[42] = {0};
	char	dst2[42] = {0};
	char	src1[21] = "salut c'est cool";
	char	src2[21] = "salut c'est cool";

	if (strncmp((char *)ft_memcpy(dst1, src1, 0), (char *)memcpy(dst2, src2, 0), 42) == 0)
		pass(1);
	else
		fail(1);
	if (strncmp((char *)ft_memcpy(dst1, src1, 21), (char *)memcpy(dst2, src2, 21), 42) == 0)
		pass(2);
	else
		fail(2);
}

void		test_memccpy()
{
	char	dst1[42] = {0};
	char	dst2[42] = {0};
	char	src1[21] = "salut c'est cool";
	char	src2[21] = "salut c'est cool";
	
	if (strncmp((char *)ft_memccpy(dst1, src1, 'a', 20), (char *)memccpy(dst2, src2, 'a', 20), 40) == 0) // caractere avant limite
		pass(1);
	else
		fail(1);	
	if (strncmp(dst1, dst2, 42) == 0)
		pass(2);
	else
		fail(2);
	if (ft_memccpy(dst1, src1, 'o', 4) == memccpy(dst2, src2, 'o', 4)) // caractere apres limite
		pass(3);
	else
		fail(3);	
	if (strncmp(dst1, dst2, 42) == 0)
		pass(4);
	else
		fail(4);
	if (strncmp((char *)ft_memccpy(dst1, src1, 'a', 2), (char *)memccpy(dst2, src2, 'a', 2), 2) == 0) // index caractere = limite
		pass(5);
	else
		fail(5);	
	if (strncmp(dst1, dst2, 42) == 0)
		pass(6);
	else
		fail(6);
	if (ft_memccpy(dst1, src1, 'o', 0) == memccpy(dst2, src2, 'o', 0)) // limite a zero
		pass(7);
	else
		fail(7);	
	if (strncmp(dst1, dst2, 42) == 0)
		pass(8);
	else
		fail(8);
}

void		test_memmove()
{
	char	dst1[42] = {0};
	char	dst2[42] = {0};
	char	src1[21] = "salut c'est cool";
	char	src2[21] = "salut c'est cool";

	if (strncmp((char *)ft_memmove(dst1, dst1 + 1, 0), (char *)memmove(dst2, dst2 + 1, 0), 42) == 0)
		pass(1);
	else
		fail(1);
	if (strncmp((char *)ft_memmove(dst1 + 1, dst1, 0), (char *)memmove(dst2 + 1, dst2, 0), 42) == 0)
		pass(2);
	else
		fail(2);
	if (strncmp((char *)ft_memmove(dst1, src1, 21), (char *)memmove(dst2, src2, 21), 42) == 0)
		pass(3);
	else
		fail(3);
	if (strncmp((char *)ft_memmove(dst1, dst1 + 1, 21), (char *)memmove(dst2, dst2 + 1, 21), 42) == 0)
		pass(4);
	else
		fail(4);
	if (strncmp((char *)ft_memmove(dst1 + 1, dst1, 21), (char *)memmove(dst2 + 1, dst2, 21), 42) == 0)
		pass(5);
	else
		fail(5);
}

void		test_memchr()
{
	char	str[21] = "salut c'est cool";

	if (ft_memchr(str, 'a', 0) == memchr(str, 'a', 0))
		pass(1);
	else
		fail(1);
	if (ft_memchr(str, 'a', 1) == memchr(str, 'a', 1))
		pass(2);
	else
		fail(2);
	if (ft_memchr(str, 'z', 21) == memchr(str, 'z', 21))
		pass(3);
	else
		fail(3);
	if (strncmp((char *)ft_memchr(str, 0, 42), (char *)memchr(str, 0, 42), 1) == 0)
		pass(4);
	else
		fail(4);
	if (strncmp((char *)ft_memchr(str, 't', 5), (char *)memchr(str, 't', 5), 13) == 0)
		pass(5);
	else
		fail(5);
}

void		test_memcmp()
{
	char	str1[21] = "salut";
	char	str2[21] = "salut";

	if (ft_memcmp((void *)str1, (void *)str2, 6) == memcmp((void *)str1, (void *)str2, 6))
		pass(1);
	else
		fail(1);
	if (ft_memcmp((void *)str1, (void *)str2, 1) == memcmp((void *)str1, (void *)str2, 1))
		pass(2);
	else
		fail(2);
	
	char	str3[21] = "salu";
	char	str4[21] = "salut";

	if (ft_memcmp((void *)str3, (void *)str4, 4) == memcmp((void *)str3, (void *)str4, 4))
		pass(3);
	else
		fail(3);
	if (ft_memcmp((void *)str3, (void *)str4, 5) == memcmp((void *)str3, (void *)str4, 5))
		pass(4);
	else
		fail(4);
	if (ft_memcmp((void *)str4, (void *)str3, 5) == memcmp((void *)str4, (void *)str3, 5))
		pass(5);
	else
		fail(5);
	if (ft_memcmp((void *)str4, (void *)str3, 4) == memcmp((void *)str4, (void *)str3, 4))
		pass(6);
	else
		fail(6);
	
	char	str5[1] = "";
	char	str6[1] = "s";
	
	if (ft_memcmp((void *)str5, (void *)str6, 1) == memcmp((void *)str5, (void *)str6, 1))
		pass(7);
	else
		fail(7);
	if (ft_memcmp((void *)str6, (void *)str5, 1) == memcmp((void *)str6, (void *)str5, 1))
		pass(8);
	else
		fail(8);
}

void		test_strlen()
{
	char	str[21] = "salut c'est cool";

	if (ft_strlen(str) == strlen(str))
		pass(1);
	else
		fail(1);
	if (ft_strlen(str + 15) == strlen(str + 15))
		pass(2);
	else
		fail(2);
	if (ft_strlen(str + 16) == strlen(str + 16))
		pass(3);
	else
		fail(3);
}

void		test_strlcpy()
{
	char	dst1[10] = {1};
	char	dst2[10] = {1};
	char	src1[17] = "salut c'est cool";
	char	src2[17] = "salut c'est cool";

	if (ft_strlcpy(dst1, src1, 0) == strlcpy(dst2, src2, 0)) // lendest = 0
		pass(1);
	else
		fail(1);
	if (strncmp(dst1, dst2, 10) == 0)
		pass(2);
	else
		fail(2);
	if (ft_strlcpy(dst1, src1 + 6, 1) == strlcpy(dst2, src2 + 6, 1)) // lendest = 1
		pass(3);
	else
		fail(3);
	if (strncmp(dst1, dst2, 10) == 0)
		pass(4);
	else
		fail(4);
	if (ft_strlcpy(dst1, src1 + 5, 10) == strlcpy(dst2, src2 + 5, 10)) //lendest = max
		pass(5);
	else
		fail(5);
	if (strncmp(dst1, dst2, 10) == 0)
		pass(6);
	else
		fail(6);
	if (ft_strlcpy(dst1, src1 + 15, 10) == strlcpy(dst2, src2 + 15, 10)) // src too small
		pass(7);
	else
		fail(7);
	if (strncmp(dst1, dst2, 10) == 0)
		pass(8);
	else
		fail(8);
}

void		test_strlcat()
{
	char	dst1[13] = "salut";
	char	dst2[13] = "salut";
	char	src1[8] = "bonjour";
	char	src2[8] = "bonjour";

	if (ft_strlcat(dst1, src1, 0) == strlcat(dst2, src2, 0)) // lendest = 0
		pass(1);
	else
		fail(1);
	if (strncmp(dst1, dst2, 13) == 0)
		pass(2);
	else
		fail(2);
	if (ft_strlcat(dst1, src1 + 2, 1) == strlcat(dst2, src2 + 2, 1)) // lendest = 1
		pass(3);
	else
		fail(3);
	if (strncmp(dst1, dst2, 13) == 0)
		pass(4);
	else
		fail(4);
	if (ft_strlcat(dst1, src1 + 5, 13) == strlcat(dst2, src2 + 5, 13)) // lendest = max
		pass(5);
	else
		fail(5);
	if (strncmp(dst1, dst2, 13) == 0)
		pass(6);
	else
		fail(6);
	if (ft_strlcat(dst1, src1, 13) == strlcat(dst2, src2, 13)) // normal test
		pass(7);
	else
		fail(7);
	if (strncmp(dst1, dst2, 13) == 0)
		pass(8);
	else
		fail(8);
}

void		test_strchr()
{
	char	str[42] = "salut c'est cool";

	if (strncmp(ft_strchr(str, 0), strchr(str, 0), 42) == 0)
		pass(1);
	else
		fail(1);
	if (strncmp(ft_strchr(str, 'l'), strchr(str, 'l'), 42) == 0)
		pass(2);
	else
		fail(2);
	if (strncmp(ft_strchr(str, 's'), strchr(str, 's'), 42) == 0)
		pass(3);
	else
		fail(3);
	if (ft_strchr(str, 'z') == strchr(str, 'z'))
		pass(4);
	else
		fail(4);
	
	char	str2[42] = {0};

	if (ft_strchr(str2, 'z') == strchr(str2, 'z'))
		pass(5);
	else
		fail(5);
}

void		test_strrchr()
{
	char	str[42] = "salut c'est cool";

	if (strncmp(ft_strrchr(str, 0), strrchr(str, 0), 42) == 0)
		pass(1);
	else
		fail(1);
	if (strncmp(ft_strrchr(str, 'l'), strrchr(str, 'l'), 5) == 0)
		pass(2);
	else
		fail(2);
	if (strncmp(ft_strrchr(str, 's'), strrchr(str, 's'), 40) == 0)
		pass(3);
	else
		fail(3);
	if (ft_strrchr(str, 'z') == strrchr(str, 'z'))
		pass(4);
	else
		fail(4);
	
	char	str2[42] = {0};

	if (ft_strrchr(str2, 'z') == strrchr(str2, 'z'))
		pass(5);
	else
		fail(5);
}

void		test_strnstr()
{
	char	string[42] = "salut c'est cool";
	char	needle[20] = "c'est";

	if (strncmp(ft_strnstr(string, needle, 1000), strnstr(string, needle, 1000), 42) == 0)
		pass(1);
	else
		fail(1);
	if (ft_strnstr(string, needle, 0) == strnstr(string, needle, 0))
		pass(2);
	else
		fail(2);
	if (strncmp(ft_strnstr(string, needle, 11), strnstr(string, needle, 11), 42) == 0)
		pass(3);
	else
		fail(3);
	if (ft_strnstr(string, needle, 10) == strnstr(string, needle, 10))
		pass(4);
	else
		fail(4);
	if (strncmp(ft_strnstr(string, needle + 6, 11), strnstr(string, needle + 6, 11), 42) == 0)
		pass(5);
	else
		fail(5);

	string[5] = 0;
	
	if (ft_strnstr(string, needle, 12) == strnstr(string, needle, 12))
		pass(6);
	else
		fail(6);
}

void		test_strncmp()
{
	char	str1[21] = "salut";
	char	str2[21] = "salut";

	if (ft_strncmp(str1, str2, 6) == strncmp(str1, str2, 6))
		pass(1);
	else
		fail(1);
	if (ft_strncmp(str1, str2, 1) == strncmp(str1, str2, 1))
		pass(2);
	else
		fail(2);
	
	char	str3[21] = "salu";
	char	str4[21] = "salut";

	if (ft_strncmp(str3, str4, 4) == strncmp(str3, str4, 4))
		pass(3);
	else
		fail(3);
	if (ft_strncmp(str3, str4, 5) == strncmp(str3, str4, 5))
		pass(4);
	else
		fail(4);
	if (ft_strncmp(str4, str3, 5) == strncmp(str4, str3, 5))
		pass(5);
	else
		fail(5);
	if (ft_strncmp(str4, str3, 4) == strncmp(str4, str3, 4))
		pass(6);
	else
		fail(6);
	
	char	str5[1] = "";
	char	str6[1] = "s";
	
	if (ft_strncmp(str5, str6, 1) == strncmp(str5, str6, 1))
		pass(7);
	else
		fail(7);
	if (ft_strncmp(str6, str5, 1) == strncmp(str6, str5, 1))
		pass(8);
	else
		fail(8);

	char	str7[8] = "salut\0a";
	char	str8[8] = "salut\0z";
	
	if (ft_strncmp(str7, str8, 8) == strncmp(str7, str8, 8))
		pass(9);
	else
		fail(9);
}

void		test_atoi()
{
	if (ft_atoi("0") == atoi("0"))
		pass(1);
	else
		fail(1);
	if (ft_atoi("-2147483648") == atoi("-2147483648"))
		pass(2);
	else
		fail(2);
	if (ft_atoi("2147483647") == atoi("2147483647"))
		pass(3);
	else
		fail(3);
	if (ft_atoi("9000000") == atoi("9000000"))
		pass(4);
	else
		fail(4);
	if (ft_atoi("0001008") == atoi("0001008"))
		pass(5);
	else
		fail(5);
	if (ft_atoi("-1") == atoi("-1"))
		pass(6);
	else
		fail(6);
	if (ft_atoi("- 1") == atoi("- 1"))
		pass(7);
	else
		fail(7);
	if (ft_atoi("+1") == atoi("+1"))
		pass(8);
	else
		fail(8);
	if (ft_atoi("--1") == atoi("--1"))
		pass(9);
	else
		fail(9);
	if (ft_atoi(" \t  \r \v -1") == atoi(" \t  \r \v -1"))
		pass(10);
	else
		fail(10);
	if (ft_atoi("-1a") == atoi(" \t  \r \v -1a"))
		pass(11);
	else
		fail(11);
	if (ft_atoi("-a1") == atoi("-a1"))
		pass(12);
	else
		fail(12);
}

void			test_isalpha()
{
	if (ft_isalpha('a') == isalpha('a'))
		pass(1);
	else
		fail(1);
	if (ft_isalpha('z') == isalpha('z'))
		pass(2);
	else
		fail(2);
	if (ft_isalpha('A') == isalpha('A'))
		pass(3);
	else
		fail(3);
	if (ft_isalpha('Z') == isalpha('Z'))
		pass(4);
	else
		fail(4);
	if (ft_isalpha('1') == isalpha('1'))
		pass(5);
	else
		fail(5);
	if (ft_isalpha('a' - 1) == isalpha('a' - 1))
		pass(6);
	else
		fail(6);
	if (ft_isalpha('z' + 1) == isalpha('z' + 1))
		pass(7);
	else
		fail(7);
	if (ft_isalpha('A' - 1) == isalpha('A' - 1))
		pass(8);
	else
		fail(8);
	if (ft_isalpha('Z' + 1) == isalpha('Z' + 1))
		pass(9);
	else
		fail(9);
	if (ft_isalpha('m') == isalpha('m'))
		pass(10);
	else
		fail(10);
	if (ft_isalpha('M') == isalpha('M'))
		pass(11);
	else
		fail(11);
	if (ft_isalpha(0) == isalpha(0))
		pass(12);
	else
		fail(12);
}

void		test_isdigit()
{
	if (ft_isdigit(5) == isdigit(5))
		pass(1);
	else
		fail(1);
	if (ft_isdigit('0') == isdigit('0'))
		pass(2);
	else
		fail(2);
	if (ft_isdigit('1') == isdigit('1'))
		pass(3);
	else
		fail(3);
	if (ft_isdigit('8') == isdigit('8'))
		pass(4);
	else
		fail(4);
	if (ft_isdigit('9') == isdigit('9'))
		pass(5);
	else
		fail(5);
	if (ft_isdigit('m') == isdigit('m'))
		pass(6);
	else
		fail(6);
	if (ft_isdigit('z') == isdigit('z'))
		pass(7);
	else
		fail(7);
}

void		test_isalnum()
{
	if (ft_isalnum('0') == isalnum('0'))
		pass(1);
	else
		fail(1);
	if (ft_isalnum('0' - 1) == isalnum('0' - 1))
		pass(2);
	else
		fail(2);
	if (ft_isalnum('9') == isalnum('9'))
		pass(3);
	else
		fail(3);
	if (ft_isalnum('9' + 1) == isalnum('9' + 1))
		pass(4);
	else
		fail(4);
	if (ft_isalnum('a') == isalnum('a'))
		pass(5);
	else
		fail(5);
	if (ft_isalnum('a' - 1) == isalnum('a' - 1))
		pass(6);
	else
		fail(6);
	if (ft_isalnum('z') == isalnum('z'))
		pass(7);
	else
		fail(7);
	if (ft_isalnum('z' + 1) == isalnum('z' + 1))
		pass(8);
	else
		fail(8);
	if (ft_isalnum('A') == isalnum('A'))
		pass(9);
	else
		fail(9);
	if (ft_isalnum('A' - 1) == isalnum('A' - 1))
		pass(10);
	else
		fail(10);
	if (ft_isalnum('Z') == isalnum('Z'))
		pass(11);
	else
		fail(11);
	if (ft_isalnum('Z' + 1) == isalnum('Z' + 1))
		pass(12);
	else
		fail(12);
	if (ft_isalnum(0) == isalnum(0))
		pass(13);
	else
		fail(13);
}

void		test_isascii()
{
	if (ft_isascii(0) == isascii(0))
		pass(1);
	else
		fail(1);
	if (ft_isascii(1) == isascii(1))
		pass(2);
	else
		fail(2);
	if (ft_isascii(126) == isascii(126))
		pass(3);
	else
		fail(3);
	if (ft_isascii(127) == isascii(127))
		pass(4);
	else
		fail(4);
	if (ft_isascii(200) == isascii(200))
		pass(5);
	else
		fail(5);
	if (ft_isascii(-42) == isascii(-42))
		pass(6);
	else
		fail(6);
}

void		test_isprint()
{
	if (ft_isprint(' ' - 1) == isprint(' ' - 1))
		pass(1);
	else
		fail(1);
	if (ft_isprint(' ') == isprint(' '))
		pass(2);
	else
		fail(2);
	if (ft_isprint(' ' + 1) == isprint(' ' + 1))
		pass(3);
	else
		fail(3);
	if (ft_isprint(126) == isprint(126))
		pass(4);
	else
		fail(4);
	if (ft_isprint(127) == isprint(127))
		pass(5);
	else
		fail(5);
	if (ft_isprint(200) == isprint(200))
		pass(6);
	else
		fail(6);
	if (ft_isprint(-42) == isprint(-42))
		pass(7);
	else
		fail(7);
}

void		test_toupper()
{
	if (ft_toupper(EOF) == toupper(EOF))
		pass(1);
	else
		fail(1);
	if (ft_toupper('a') == toupper('a'))
		pass(2);
	else
		fail(2);
	if (ft_toupper('m') == toupper('m'))
		pass(3);
	else
		fail(3);
	if (ft_toupper('z') == toupper('z'))
		pass(4);
	else
		fail(4);
	if (ft_toupper('a' - 1) == toupper('a' - 1))
		pass(5);
	else
		fail(5);
	if (ft_toupper('z' + 1) == toupper('z' + 1))
		pass(6);
	else
		fail(6);
	if (ft_toupper('A') == toupper('A'))
		pass(7);
	else
		fail(7);
	if (ft_toupper('M') == toupper('M'))
		pass(8);
	else
		fail(8);
	if (ft_toupper(200) == toupper(200))
		pass(9);
	else
		fail(9);
	if (ft_toupper(-42) == toupper(-42))
		pass(10);
	else
		fail(10);
	if (ft_toupper(0) == toupper(0))
		pass(11);
	else
		fail(11);
}

void		test_tolower()
{
	if (ft_tolower(EOF) == tolower(EOF))
		pass(1);
	else
		fail(1);
	if (ft_tolower('A') == tolower('A'))
		pass(2);
	else
		fail(2);
	if (ft_tolower('M') == tolower('M'))
		pass(3);
	else
		fail(3);
	if (ft_tolower('Z') == tolower('Z'))
		pass(4);
	else
		fail(4);
	if (ft_tolower('A' - 1) == tolower('A' - 1))
		pass(5);
	else
		fail(5);
	if (ft_tolower('Z' + 1) == tolower('Z' + 1))
		pass(6);
	else
		fail(6);
	if (ft_tolower('a') == tolower('a'))
		pass(7);
	else
		fail(7);
	if (ft_tolower('m') == tolower('m'))
		pass(8);
	else
		fail(8);
	if (ft_tolower(200) == tolower(200))
		pass(9);
	else
		fail(9);
	if (ft_tolower(-42) == tolower(-42))
		pass(10);
	else
		fail(10);
	if (ft_tolower(0) == tolower(0))
		pass(11);
	else
		fail(11);
}

void		test_calloc()
{
	int test = 1;
	void *mem = ft_calloc(42, sizeof(int));
	int i = 0;
	while (i < 42)
	{
		((int *)mem)[i] = 42;
		i++;
	}
	i = 0;
	while (i < 42)
	{
		if (((int *)mem)[i] != 42)
			test = 0;
		i++;
	}
	if (test)
		pass(1);
	else
		fail(1);
}

void		test_strdup()
{
	char	str[21] = "salut";

	if (strncmp(ft_strdup(str), strdup(str), 10) == 0)
		pass(1);
	else
		fail(1);

	str[2] = 0;
	
	if (strncmp(ft_strdup(str + 1), strdup(str + 1), 10) == 0)
		pass(2);
	else
		fail(2);
	if (strncmp(ft_strdup(str + 2), strdup(str + 2), 10) == 0)
		pass(3);
	else
		fail(3);
}

void		test_substr()
{
	char	str[17] = "salut c'est cool";

	if (ft_substr(NULL, 0, 17) == NULL) // chaine nulle
	   pass(1);
	else
		fail(1);
	if (strcmp(ft_substr(str, 18, 19), "") == 0) // start en dehors de la chaine
		pass(2);
	else
		fail(2);
	if (strcmp(ft_substr(str + 16, 0, 1), "") == 0) // chaine vide
		pass(3);
	else
		fail(3);
	if (strncmp(ft_substr(str, 0, 17), str, 17) == 0)
		pass(4);
	else
		fail(4);
	if (strncmp(ft_substr(str, 0, 1000), str, 17) == 0)
		pass(5);
	else
		fail(5);
	if (strncmp(ft_substr(str, 6, 5), "c'est", 5) == 0)
		pass(6);
	else
		fail(6);
}

void		test_strjoin()
{
	char	str1[6] = "salut";
	char	str2[8] = "bonjour";

	if (strncmp(ft_strjoin(str1, str2), "salutbonjour", 11) == 0)
		pass(1);
	else
		fail(1);
	if (strncmp(ft_strjoin(str1, ""), "salut", 6) == 0)
		pass(2);
	else
		fail(2);
	if (strncmp(ft_strjoin("", str2), "bonjour", 8) == 0)
		pass(3);
	else
		fail(3);
	if (strncmp(ft_strjoin("", ""), "", 1) == 0)
		pass(4);
	else
		fail(4);
}

void		test_strtrim()
{
	char	str[21] = "salut c'est cool";

	if (strncmp(ft_strtrim(str, ""), str, 17) == 0)
		pass(1);
	else
		fail(1);
	if (strncmp(ft_strtrim("", ""), "", 1) == 0)
		pass(2);
	else
		fail(2);
	if (strncmp(ft_strtrim("", "a"), "", 1) == 0)
		pass(3);
	else
		fail(3);
	if (strncmp(ft_strtrim(str, "olsa"), "ut c'est c", 11) == 0)
		pass(4);
	else
		fail(4);
	if (strncmp(ft_strtrim(str, "s"), str + 1, 16) == 0)
		pass(5);
	else
		fail(5);
	if (strncmp(ft_strtrim(str, "l"), "salut c'est coo", 16) == 0)
		pass(6);
	else
		fail(6);
}

void		test_split()
{
	char	str1[200] = "salut comment ca va";
	char	delim = ' ';
	int		test = 1;

	char	**tab = ft_split(str1, delim);

	if (strncmp(tab[0], "salut", 6) != 0)
		test = 0;
	if (strncmp(tab[1], "comment", 8) != 0)
		test = 0;
	if (strncmp(tab[2], "ca", 3) != 0)
		test = 0;
	if (strncmp(tab[3], "va", 3) != 0)
		test = 0;
	if (test == 0 || tab[4] != NULL)
		fail(1);
	else
		pass(1);

	char	str2[200] = "    salut   comment   ca   va     ";
	test = 1;

	char	**tab2 = ft_split(str2, delim);

	if (strncmp(tab2[0], "salut", 6) != 0)
		test = 0;
	if (strncmp(tab2[1], "comment", 8) != 0)
		test = 0;
	if (strncmp(tab2[2], "ca", 3) != 0)
		test = 0;
	if (strncmp(tab2[3], "va", 3) != 0)
		test = 0;
	if (test == 0 || tab2[4] != NULL)
		fail(2);
	else
		pass(2);

	char	str3[1] = "";

	char	**tab3 = ft_split(str3, delim);

	if (tab3[0] != NULL)
		fail(3);
	else
		pass(3);

	char	str4[100] = "         ";

	char	**tab4 = ft_split(str4, delim);

	if (tab4[4] != NULL)
		fail(4);
	else
		pass(4);
}

void		test_itoa()
{
	if (strncmp(ft_itoa(0), "0", 2) == 0)
		pass(1);
	else
		fail(1);
	if (strncmp(ft_itoa(-2147483648), "-2147483648", 12) == 0)
		pass(2);
	else
		fail(2);
	if (strncmp(ft_itoa(2147483647), "2147483647", 11) == 0)
		pass(3);
	else
		fail(3);
	if (strncmp(ft_itoa(-1234567890), "-1234567890", 12) == 0)
		pass(4);
	else
		fail(4);
	if (strncmp(ft_itoa(900000002), "900000002", 10) == 0)
		pass(5);
	else
		fail(5);
}

char		my_function(unsigned int index, char c)
{
	if (index == 4 || index == 7 || c == 'o' || c == 'l')
		return ('Z');
	return (c);
}

void		test_strmapi()
{
	char	str[21] = "salut c'est cool";

	if (strncmp(ft_strmapi(str, &my_function), "saZuZ cZest cZZZ", 17) == 0)
		pass(1);
	else
		fail(1);
	if (strncmp(ft_strmapi(str + 16, &my_function), "", 1) == 0)
		pass(2);
	else
		fail(2);
}

void		test_putchar_fd()
{
	printf("expected : a\n");
	ft_putchar_fd('a', 1);
	printf("\n");
	printf("expected : %%\n");
	ft_putchar_fd('%', 1);
	printf("\n");
}

void		test_putstr_fd()
{
	printf("expected : salut c'est cool\n");
	ft_putstr_fd("salut c'est cool", 1);
	printf("\n");
	printf("expected :\n");
	ft_putstr_fd("", 1);
	printf("\n");
}

void		test_putendl_fd()
{
	printf("expected : salut c'est cool\n");
	ft_putendl_fd("salut c'est cool", 1);
	printf("expected :\n");
	ft_putendl_fd("", 1);
}

void		test_putnbr_fd()
{
	printf("expected : 0\n");
	ft_putnbr_fd(0, 1);
	printf("\nexpected : -2147483648\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\nexpected : 2147483647\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\nexpected : -123456789\n");
	ft_putnbr_fd(-123456789, 1);
}

void		test_lstnew()
{
	char	content[100] = "salut c'est cool";
	
	t_list	*list = ft_lstnew((void *)content);
	if (list && strncmp(list->content, content, 100) == 0 && list->next == NULL)
		pass(1);
	else
		fail(1);

	t_list	*list2 = ft_lstnew(NULL);
	if (list2 && list2->content == NULL && list2->next == NULL)
		pass(2);
	else
		fail(2);
}

void		test_lstadd_front()
{
	t_list	*elem1 = ft_lstnew((void *)"1");
	t_list	*new = ft_lstnew((void *)"Z");
	
	ft_lstadd_front(&elem1, new);
	if (strncmp((char *)elem1->content, "Z", 2) == 0 &&
		strncmp((char *)elem1->next->content, "1", 2) == 0)
		pass(1);
	else
		fail(1);

	t_list	*elem2 = NULL;
	t_list	*new2 = ft_lstnew((void *)"Z");
	
	ft_lstadd_front(&elem2, new2);
	if (strncmp((char *)elem2->content, "Z", 2) == 0)
		pass(2);
	else
		fail(2);
}

void		test_lstsize()
{
	t_list	*elem1 = ft_lstnew(NULL);
	t_list	*elem2 = ft_lstnew(NULL);
	t_list	*elem3 = ft_lstnew(NULL);

	if (ft_lstsize(NULL) == 0)
		pass(1);
	else
		fail(1);
	if (ft_lstsize(elem1) == 1)
		pass(2);
	else
		fail(2);

	elem1->next = elem2;

	if (ft_lstsize(elem1) == 2)
		pass(3);
	else
		fail(3);

	elem2->next = elem3;

	if (ft_lstsize(elem1) == 3)
		pass(4);
	else
		fail(4);
}

void		test_lstlast()
{
	t_list	*elem1 = ft_lstnew((void *) "1");
	t_list	*elem2 = ft_lstnew((void *) "2");
	t_list	*elem3 = ft_lstnew((void *) "3");
	
	if (ft_lstlast(NULL) == NULL)
		pass(1);
	else
		fail(1);
	if (strncmp(ft_lstlast(elem1)->content, "1", 2) == 0)
		pass(2);
	else
		fail(2);

	elem1->next = elem2;
	
	if (strncmp(ft_lstlast(elem1)->content, "2", 2) == 0)
		pass(3);
	else
		fail(3);

	elem2->next = elem3;

	if (strncmp(ft_lstlast(elem1)->content, "3", 2) == 0)
		pass(4);
	else
		fail(4);
}

void		test_lstadd_back()
{
	t_list	*elem1 = ft_lstnew((void *) "1");
	t_list	*new1 = ft_lstnew((void *) "2");
	
	ft_lstadd_back(&elem1, new1);
	if (strncmp((char *)elem1->content, "1", 2) == 0 &&
		strncmp((char *)elem1->next->content, "2", 2) == 0)
		pass(1);
	else
		fail(1);

	t_list	*elem2 = NULL;
	t_list	*new2 = ft_lstnew((void *) "2");
	
	ft_lstadd_back(&elem2, new2);
	if (strncmp((char *)elem2->content, "2", 2) == 0)
		pass(2);
	else
		fail(2);
}

void		del_function(void *content)
{
	(void)content;
}

void		test_lstdelone()
{
	t_list	*elem1 = ft_lstnew((void *) "1");
	/*t_list	*elem2 = ft_lstnew((void *) "2");
	t_list	*elem3 = ft_lstnew((void *) "3");
	t_list	*elem4 = ft_lstnew((void *) "4");*/

	ft_lstdelone(elem1, &del_function);
	pass(1);
}

void		test_lstclear()
{
	t_list	*elem1 = ft_lstnew((void *) "1");
	t_list	*elem2 = ft_lstnew((void *) "2");
	t_list	*elem3 = ft_lstnew((void *) "3");
	t_list	*elem4 = ft_lstnew((void *) "4");

	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	ft_lstclear(&elem1, &del_function);
	if (elem1 == NULL)
		pass(1);
	else
		fail(1);
}

void		nice_function1(void *content)
{
	content = (void *) "Z";
}

void		test_lstiter()
{
	t_list	*elem1 = ft_lstnew((void *) "1");
	t_list	*elem2 = ft_lstnew((void *) "2");
	t_list	*elem3 = ft_lstnew((void *) "3");
	t_list	*elem4 = ft_lstnew((void *) "4");
	
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	/*ft_lstiter(elem1, &nice_function1);
	if (strncmp((char *)elem1->content, "Z", 2) == 0 &&
		strncmp((char *)elem2->content, "Z", 2) == 0 &&
		strncmp((char *)elem3->content, "Z", 2) == 0 &&
		strncmp((char *)elem4->content, "Z", 2) == 0)
		pass(1);
	else
		fail(1);*/
	
	ft_lstiter(elem1, &nice_function1);
	pass(1);
}

void		*nice_function2(void *content)
{
	content = (void *)"Z";
	return (content);
}

/*void		test_lstmap()
{
	t_list	*elem1 = ft_lstnew((void *) "1");
	t_list	*elem2 = ft_lstnew((void *) "2");
	t_list	*elem3 = ft_lstnew((void *) "3");
	t_list	*elem4 = ft_lstnew((void *) "4");
	
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	t_list	*new_list = ft_lstmap(elem1, &nice_function2, &del_function);
	if (strncmp((char *)elem1->content, "1", 2) == 0 &&
		strncmp((char *)elem2->content, "2", 2) == 0 &&
		strncmp((char *)elem3->content, "3", 2) == 0 &&
		strncmp((char *)elem4->content, "4", 2) == 0)
		pass(1);
	else
		fail(1);

	if (strncmp((char *)new_list->content, "Z", 2) == 0 &&
		strncmp((char *)new_list->next->content, "Z", 2) == 0 &&
		strncmp((char *)new_list->next->next->content, "Z", 2) == 0 &&
		strncmp((char *)new_list->next->next->next->content, "Z", 2) == 0)
		pass(2);
	else
		fail(2);

}*/

int			main(void)
{
	printf("\tMEMSET : \n\n");
	test_memset();
	printf("\n\tBZERO : \n\n");
	test_bzero();
	printf("\n\tMEMCPY : \n\n");
	test_memcpy();
	printf("\n\tMEMCCPY : \n\n");
	test_memccpy();
	printf("\n\tMEMMOVE : \n\n");
	test_memmove();
	printf("\n\tMEMCHR : \n\n");
	test_memchr();
	printf("\n\tMEMCMP : \n\n");
	test_memcmp();
	printf("\n\tSTRLEN : \n\n");
	test_strlen();
	printf("\n\tSTRLCPY : \n\n");
	test_strlcpy();
	printf("\n\tSTRLCAT : \n\n");
	test_strlcat();
	printf("\n\tSTRCHR : \n\n");
	test_strchr();
	printf("\n\tSTRRCHR : \n\n");
	test_strrchr();
	printf("\n\tSTRNSTR : \n\n");
	test_strnstr();
	printf("\n\tSTRNCMP : \n\n");
	test_strncmp();
	printf("\n\tATOI : \n\n");
	test_atoi();
	printf("\n\tISALPHA : \n\n");
	test_isalpha();
	printf("\n\tISDIGIT : \n\n");
	test_isdigit();
	printf("\n\tISALNUM : \n\n");
	test_isalnum();
	printf("\n\tISASCII : \n\n");
	test_isascii();
	printf("\n\tISPRINT : \n\n");
	test_isprint();
	printf("\n\tTOUPPER : \n\n");
	test_toupper();
	printf("\n\tTOLOWER : \n\n");
	test_tolower();
	printf("\n\tCALLOC : \n\n");
	test_calloc();
	printf("\n\tSTRDUP : \n\n");
	test_strdup();
	printf("\n\tSUBSTR : \n\n");
	test_substr();
	printf("\n\tSTRJOIN : \n\n");
	test_strjoin();
	printf("\n\tSTRTRIM : \n\n");
	test_strtrim();
	printf("\n\tSPLIT : \n\n");
	test_split();
	printf("\n\tITOA : \n\n");
	test_itoa();
	printf("\n\tSTRMAPI : \n\n");
	test_strmapi();
	printf("\n\tPUTCHAR_FD : \n\n");
	test_putchar_fd();
	printf("\n\tPUTSTR_FD : \n\n");
	test_putstr_fd();
	printf("\n\tPUTENDL_FD : \n\n");
	test_putendl_fd();
	printf("\n\tPUTNBR_FD : \n\n");
	test_putnbr_fd();
	printf("\n\tLSTNEW : \n\n");
	test_lstnew();
	printf("\n\tLSTADD_FRONT : \n\n");
	test_lstadd_front();
	printf("\n\tLSTSIZE : \n\n");
	test_lstsize();
	printf("\n\tLSTLAST : \n\n");
	test_lstlast();
	printf("\n\tLSTADD_BACK : \n\n");
	test_lstadd_back();
	printf("\n\tLSTDELONE : \n\n");
	test_lstdelone();
	printf("\n\tLSTCLEAR : \n\n");
	test_lstclear();
	//printf("\n\tLSTITER : \n\n");
	//test_lstiter();
	//printf("\n\tLSTMAP : \n\n");
	//test_lstmap();

	return (0);
}

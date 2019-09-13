/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:07:22 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/11 18:07:49 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <libft.h>

void	dash_message()
{
	printf("\n------------------------------------------------\n");
}

void	start_message(char *func_name)
{
	dash_message();
	printf("Tests run for %s.\n", func_name);
}

void	success_message(char *func_name)
{
	printf("All tests for %s completed successfully.", func_name);
	dash_message();
}

void	test_ft_memset(void)
{
	char src[16] = "1234567890Hello";
	char ideal[16] = "1234567890Hello";

	ft_memset(src, '1', 10);
	memset(ideal, '1', 10);
	assert(!(strcmp(src, ideal)));
	
	strcpy(src, "Hello world");
	strcpy(ideal, "Hello world");
	ft_memset(src, 70, 5);
	memset(ideal, 70, 5);
	assert(!(strcmp(src, ideal)));
	
	strcpy(src, "Hello world");
	strcpy(ideal, "Hello world");
	ft_memset(src, 70, 1);
	memset(ideal, 70, 2);
	assert(strcmp(src, ideal));

	strcpy(src, "Hello world");
	strcpy(ideal, "Hello world");
	ft_memset(src, 70, 2);
	memset(ideal, 70, 1);
	assert(strcmp(src, ideal));
}

void	handler_ft_memset(void)
{
	start_message("ft_memset");
	test_ft_memset();
	success_message("ft_memset");
}

void	test_ft_bzero(void)
{
	char src[16] = "1234567890Hello";
	char ideal[16] = "1234567890Hello";

	bzero(ideal, 5);
	ft_bzero(src, 5);
	assert(!(strcmp(src, ideal)));
	
	strcpy(src, "Hello world");
	strcpy(ideal, "Hello world");
	bzero(ideal, 1);
	ft_bzero(src, 0);
	assert(strcmp(src, ideal));
}

void	handler_ft_bzero(void)
{
	start_message("ft_bzero");
	test_ft_bzero();
	
	success_message("ft_bzero");
}

void	test_ft_memcpy(void)
{
	char src[16] = "";
	char ideal[16] = "";

	ft_memcpy(src, "Hello", 5);
	memcpy(ideal, "Hello", 5);
	assert(!(strcmp(src, ideal)));

	ft_memcpy(src, " world", 6);
	memcpy(ideal, " world", 6);
	assert(!(strcmp(src, ideal)));

	int i_src[5] = {};
	int i_ideal[5] = {};
	int	i_storage[5] = {10, 20, 30, -40, 0};
	ft_memcpy(i_src, i_storage, sizeof(i_storage));
	memcpy(i_ideal, i_storage, sizeof(i_storage));
	int i = 0;
	while (i < 5)
	{
		assert(i_src[i] == i_ideal[i]);
		i++;
	}
	
	ft_memcpy(&i_src[1], &i_src[0], sizeof(i_src)/5);
	memcpy(&i_ideal[1], &i_ideal[0], sizeof(i_ideal)/5);
	i = 0;
	while (i < 5)
	{
		assert(i_src[i] == i_ideal[i]);
		i++;
	}
}

void	handler_ft_memcpy(void)
{
	start_message("ft_memcpy");
	test_ft_memcpy();
	success_message("ft_memcpy");
}

void	test_ft_memccpy(void)
{
	char src[16] = "";
	char ideal[16] = "";
	char *p_src;
	char *p_ideal;
	
	p_src = ft_memccpy(src, "Hello", 'F', 5);
	p_ideal = memccpy(ideal, "Hello", 'F', 5);
	assert(p_src == NULL && p_ideal == NULL);

	p_src = (char*)ft_memccpy(src, " wForld", 'F', 7);
	p_ideal = (char*)memccpy(ideal, " wForld", 'F', 7);
	assert(p_src != NULL && p_ideal != NULL);
	assert(!(strcmp(src, " wFlo")));
	assert(!(strcmp(src, ideal)));
}

void	handler_ft_memccpy(void)
{
	start_message("ft_memccpy");
	test_ft_memccpy();
	success_message("ft_memccpy");
}

void	test_ft_memmove(void)
{
	char src[16] = "stackoverflow";
	char ideal[16] = "stackoverflow";

	ft_memmove(&src[5], &src[1], 7);
	memmove(&ideal[5], &ideal[1], 7);
	assert(!strcmp(src, ideal));
}

void	handler_ft_memmove(void)
{
	start_message("ft_memmove");
	test_ft_memmove();
	success_message("ft_memmove");
}

void	test_ft_memchr(void)
{
	char	src[16] = "Hello";
	char	ideal[16] = "Hello";
	char	*p_src;
	char	*p_ideal;

	p_src = ft_memchr(src, 'l', 5);
	p_ideal = memchr(ideal, 'l', 5);
	assert(!strcmp(p_src, "llo"));
	assert(!strcmp(p_src, p_ideal));

	p_src = ft_memchr(src, 10, 3);
	p_ideal = memchr(ideal, 10, 3);
	assert(p_src == NULL);
	assert(p_src == p_ideal);
}

void	handler_ft_memchr(void)
{
	start_message("ft_memchr");
	test_ft_memchr();
	success_message("ft_memchr");
}

void	test_ft_memcmp(void)
{
	char	src[16] = "Hello";
	int		src_result;
	int		ideal_result;

	src_result = ft_memcmp(src, "Hello", 5);
	ideal_result = memcmp(src, "Hello", 5);
	assert(src_result == 0);
	assert(src_result == ideal_result);

	src_result = ft_memcmp(src, "Hello ", 5);
	ideal_result = memcmp(src, "Hello ", 5);
	assert(src_result == 0);
	assert(src_result == ideal_result);

	src_result = ft_memcmp(src, "Hello ", 6);
	ideal_result = memcmp(src, "Hello ", 6);
	assert(src_result == ideal_result);

	src_result = ft_memcmp(src, " Hello ", 7);
	ideal_result = memcmp(src, " Hello ", 7);
	assert(src_result == ideal_result);

	src_result = ft_memcmp(src, "hello", 5);
	ideal_result = memcmp(src, "hello", 5);
	assert(src_result == ideal_result);
}

void	handler_ft_memcmp(void)
{
	start_message("ft_memcmp");
	test_ft_memcmp();
	success_message("ft_memcmp");
}

void	test_ft_strcpy(void)
{
	char	src[16];
	char	ideal[16];

	ft_strcpy(src, "Hello");
	strcpy(ideal, "Hello");
	assert(!strcmp(src, ideal));

	ft_strcpy(src, "      H ");
	strcpy(ideal, "      H ");
	assert(!strcmp(src, ideal));
}

void	handler_ft_strcpy(void)
{
	start_message("ft_strcpy");
	test_ft_strcpy();
	success_message("ft_strcpy");
}

void    test_ft_strcat(void)
{
    char src[16] = "Hello";
    char ideal[16] = "Hello";

    ft_strcat(src, " world");
    strcat(ideal, " world");
    assert(!strcmp(src, "Hello world"));
    assert(!strcmp(src, ideal));
}

void    handler_ft_strcat(void)
{
    start_message("ft_strcat");
    test_ft_strcat();
    success_message("ft_strcat");
}

void    test_ft_strncat(void)
{
    char src[16] = "Hello";
    char ideal[16] = "Hello";

    ft_strncat(src, " world", 3);
    strncat(ideal, " world", 3);
    assert(!strcmp(src, "Hello wo"));
    assert(!strcmp(src, ideal));
}

void    handler_ft_strncat(void)
{
    start_message("ft_strncat");
    test_ft_strncat();
    success_message("ft_strncat");
}

void	tests_run(void)
{
	handler_ft_memset();
	handler_ft_bzero();
	handler_ft_memcpy();
	handler_ft_memccpy();
	handler_ft_memmove();
	handler_ft_memchr();
	handler_ft_memcmp();
	handler_ft_strcpy();
    handler_ft_strcat();
    handler_ft_strncat();
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		tests_run();
	while (i < argc)
	{
		if (!strcmp(argv[i], "ft_memset"))
			handler_ft_memset();
		else if (!strcmp(argv[i], "ft_bzero"))
			handler_ft_bzero();
		else if (!strcmp(argv[i], "ft_memcpy"))
			handler_ft_memcpy();
		else if (!strcmp(argv[i], "ft_memccpy"))
			handler_ft_memccpy();
		else if (!strcmp(argv[i], "ft_memmove"))
			handler_ft_memmove();
		else if (!strcmp(argv[i], "ft_memchr"))
			handler_ft_memchr();
		else if (!strcmp(argv[i], "ft_memcmp"))
			handler_ft_memcmp();
		else if (!strcmp(argv[i], "ft_strcpy"))
			handler_ft_strcpy();
		i++;
	}
	return (1);
}

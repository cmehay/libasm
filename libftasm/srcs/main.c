#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libfts.h"

#define CLR_DEFAULT "\033[0;0m"
#define CLR_FUNCTION_NAME "\033[33;1m"
#define CLR_FUNCTION_SUCCESS "\033[32;1m"
#define CLR_FUNCTION_FAILURE "\033[31;1m"

#define SEP_PATTERN "--------------------> "

static int	g_nb_check_failure = 0;
static int	g_opt_v = 0;

static void	lasm_function_name_display(const char * const str)
{
	printf("%s%s%s%s\n", SEP_PATTERN,
			CLR_FUNCTION_NAME, str, CLR_DEFAULT);
}

static void	lasm_function_success(void)
{
	printf("%s%s%s%s\n\n", SEP_PATTERN,
			CLR_FUNCTION_SUCCESS, "Success!", CLR_DEFAULT);
}

static void	lasm_function_failure(const unsigned int errors)
{
	g_nb_check_failure++;
	printf("%s%s%s%s", SEP_PATTERN,
			CLR_FUNCTION_FAILURE, "Failure!", CLR_DEFAULT);
	(errors == 1) ?
		printf(" (%u error)\n\n", errors) :
		printf(" (%u errors)\n\n", errors);
}

static void	lasm_function_state(const unsigned int errors)
{
	if (!errors)
		lasm_function_success();
	else
		lasm_function_failure(errors);
}

static void	lasm_putstr(const char * const str, const size_t len)
{
	size_t	i;

	for (i = 0; i < len; i++)
		str[i] ? putchar(str[i]) : putchar('-');
}

static void	lasm_achievement_display(void)
{
	if (!g_nb_check_failure)
		printf("%sAll functions are successful !\n\n%s",
				CLR_FUNCTION_SUCCESS, CLR_DEFAULT);
	else
	{
		if (g_nb_check_failure == 1)
			printf("%s%d error !\n\n%s",
					CLR_FUNCTION_FAILURE, g_nb_check_failure, CLR_DEFAULT);
		else
			printf("%s%d errors !\n\n%s",
					CLR_FUNCTION_FAILURE, g_nb_check_failure, CLR_DEFAULT);
	}
}

static void	lasm_check_bzero(void)
{
	char			str0[] = "Pikachu!";
	char			str1[] = "Pikachu!";
	char			str2[] = "Pikachu!";
	size_t			str_len = strlen(str0);
	size_t			offset;
	unsigned int	errors = 0;

	lasm_function_name_display("bzero");
	if (g_opt_v)
		printf("%-10s%s\n\n", "string:", str0);

	offset = 0;
	bzero(str1, offset);
	ft_bzero(str2, offset);
	if (strcmp(str1, str2))
		errors++;

	if (g_opt_v)
	{
		printf("%-10s", "bzero:");
		lasm_putstr(str1, str_len);
		printf(" (%zu)\n", offset);

		printf("%-10s", "ft_bzero:");
		lasm_putstr(str2, str_len);
		printf(" (%zu)\n\n", offset);
	}

	offset = 4;
	bzero(str1, offset);
	ft_bzero(str2, offset);
	if (strcmp(str1, str2))
		errors++;

	if (g_opt_v)
	{
		printf("%-10s", "bzero:");
		lasm_putstr(str1, str_len);
		printf(" (%zu)\n", offset);

		printf("%-10s", "ft_bzero:");
		lasm_putstr(str2, str_len);
		printf(" (%zu)\n", offset);
	}

	lasm_function_state(errors);
}

static void	lasm_check_strcat(void)
{
	char			dest1[42] = "Pika-Pi! ";
	char			src1[] = "Pikachu!";
	char			dest2[42] = "Pika-Pi! ";
	char			src2[] = "Pikachu!";
	char			*ret1;
	char			*ret2;
	unsigned int	errors = 0;

	lasm_function_name_display("strcat");

	if (g_opt_v)
	{
		printf("%-11s%s\n", "dest:", dest1);
		printf("%-11s%s\n\n", "src:", src1);
	}

	ret1 = strcat(dest1, src1);
	ret2 = ft_strcat(dest2, src2);
	if (strcmp(ret1, ret2))
		errors++;

	if (g_opt_v)
	{
		printf("%-11s", "strcat:");
		lasm_putstr(ret1, strlen(ret1));
		putchar('\n');

		printf("%-11s", "ft_strcat:");
		lasm_putstr(ret2, strlen(ret2));
		putchar('\n');
	}

	lasm_function_state(errors);
}

static void	lasm_check_function_is(char *f_name, int (*f)(int c), int (*ft)(int c))
{
	int				ret1;
	int				ret2;
	int				i;
	unsigned int	errors = 0;

	lasm_function_name_display(f_name);

	for (i = -1; i < 128; i++)
	{
		ret1 = f(i);
		ret2 = ft(i);
		if ((ret1 == 0 && ret2 != 0) || (ret1 != 0 && ret2 == 0))
			errors++;

		if (g_opt_v)
		{
			printf("%s:%4c", f_name, ' ');
			printf("%d (%c)\n", ret1, i);

			printf("ft_%s:%1c", f_name, ' ');
			printf("%d (%c)\n", ret2, i);

			if (i < 127)
				putchar('\n');
		}
	}

	lasm_function_state(errors);
}

static void	lasm_check_toupper(void)
{
	char			lst_char[] = "@AZ[az}";
	int				ret1;
	int				ret2;
	size_t			i;
	unsigned int	errors = 0;

	lasm_function_name_display("toupper");

	for (i = 0; lst_char[i]; i++)
	{
		ret1 = toupper(lst_char[i]);
		ret2 = ft_toupper(lst_char[i]);
		if (ret1 != ret2)
			errors++;

		if (g_opt_v)
		{
			printf("%-12s", "toupper:");
			printf("%d (%c)\n", ret1, lst_char[i]);

			printf("%-12s", "ft_toupper:");
			printf("%d (%c)\n", ret2, lst_char[i]);
			if (!(lst_char[i + 1] == '\0'))
				putchar('\n');
		}
	}

	lasm_function_state(errors);
}

static void	lasm_check_tolower(void)
{
	char			lst_char[] = "@AZ[az}";
	int				ret1;
	int				ret2;
	size_t			i;
	unsigned int	errors = 0;

	lasm_function_name_display("tolower");

	for (i = 0; lst_char[i]; i++)
	{
		ret1 = tolower(lst_char[i]);
		ret2 = ft_tolower(lst_char[i]);
		if (ret1 != ret2)
			errors++;

		if (g_opt_v)
		{
			printf("%-12s", "tolower:");
			printf("%d (%c)\n", ret1, lst_char[i]);

			printf("%-12s", "ft_tolower:");
			printf("%d (%c)\n", ret2, lst_char[i]);
			if (!(lst_char[i + 1] == '\0'))
				putchar('\n');
		}
	}

	lasm_function_state(errors);
}

void	lasm_check_puts(void)
{
	int				ret1;
	int				ret2;
	const char		str[] = "Pikaaaaaa-Piiiii!";
	unsigned int	errors = 0;

	lasm_function_name_display("puts");

	if (g_opt_v)
	{
		printf("%-5s%s\n\n", "str:", str);

		printf("%s\n", "puts:");
	}

	ret1 = puts(str);
	if (g_opt_v)
	{
		printf("Ret: (%d)\n", ret1);
		putchar('\n');
	}

	if (g_opt_v)
		printf("%s\n", "ft_puts:");
	ret2 = ft_puts(str);
	if (g_opt_v)
		printf("Ret: (%d)\n", ret2);

	if ((ret1 < 0 && ret2 > 0) || (ret1 > 0 && ret2 < 0))
		errors++;

	if (g_opt_v)
		putchar('\n');

	lasm_function_state(errors);
}

static void	lasm_check_strlen(void)
{
	char			str_empty[] = "";
	char			str[] = "Pika-Pi! Pikachu!";
	size_t			ret1;
	size_t			ret2;
	unsigned int	errors = 0;

	lasm_function_name_display("strlen");

	/*
	** Check an empty string
	*/
	if (g_opt_v)
		printf("%-11s%s\n", "str:", str_empty);

	ret1 = strlen(str_empty);
	ret2 = ft_strlen(str_empty);
	if (ret1 != ret2)
		errors++;

	if (g_opt_v)
	{
		printf("%-11s%zu\n", "strlen:", ret1);
		printf("%-11s%zu\n", "ft_strlen:", ret2);
		putchar('\n');
	}

	/*
	** Check a string
	*/
	if (g_opt_v)
		printf("%-11s%s\n", "str:", str);

	ret1 = strlen(str);
	ret2 = ft_strlen(str);
	if (ret1 != ret2)
		errors++;

	if (g_opt_v)
	{
		printf("%-11s%zu\n", "strlen:", ret1);
		printf("%-11s%zu\n", "ft_strlen:", ret2);
	}

	lasm_function_state(errors);
}

static void	lasm_check_memset(void)
{
	char			str0[] = "Pikachu!";
	char			str1[] = "Pikachu!";
	char			str2[] = "Pikachu!";
	size_t			str_len = strlen(str0);
	size_t			offset;
	unsigned int	errors = 0;

	lasm_function_name_display("memset");
	if (g_opt_v)
		printf("%-11s%s\n\n", "string:", str0);

	offset = 0;
	memset(str1, 'o', offset);
	ft_memset(str2,'o', offset);
	if (strcmp(str1, str2))
		errors++;

	if (g_opt_v)
	{
		printf("%-11s", "memset:");
		lasm_putstr(str1, str_len);
		printf(" (%zu)\n", offset);

		printf("%-11s", "ft_memset:");
		lasm_putstr(str2, str_len);
		printf(" (%zu)\n\n", offset);
	}

	offset = 4;
	memset(str1, 'o', offset);
	ft_memset(str2, 'o', offset);
	if (strcmp(str1, str2))
		errors++;

	if (g_opt_v)
	{
		printf("%-11s", "memset:");
		lasm_putstr(str1, str_len);
		printf(" (%zu)\n", offset);

		printf("%-11s", "ft_memset:");
		lasm_putstr(str2, str_len);
		printf(" (%zu)\n", offset);
	}

	lasm_function_state(errors);
}

static void	lasm_check_memcpy(void)
{
	char			src[] = "Pikachu!";
	char			dest1[] = "Togepi!!";
	char			dest2[] = "Togepi!!";
	size_t			str_len = strlen(src);
	size_t			offset;
	unsigned int	errors = 0;

	lasm_function_name_display("memcpy");
	if (g_opt_v)
		printf("%-11s%s\n\n", "string:", src);

	offset = 0;
	memcpy(dest1, src, offset);
	ft_memcpy(dest2, src, offset);
	if (strcmp(dest1, dest2))
		errors++;

	if (g_opt_v)
	{
		printf("%-11s", "memcpy:");
		lasm_putstr(dest1, str_len);
		printf(" (%zu)\n", offset);

		printf("%-11s", "ft_memcpy:");
		lasm_putstr(dest2, str_len);
		printf(" (%zu)\n\n", offset);
	}

	offset = 4;
	memcpy(dest1, src, offset);
	ft_memcpy(dest2, src, offset);
	if (strcmp(dest1, dest2))
		errors++;

	if (g_opt_v)
	{
		printf("%-11s", "memcpy:");
		lasm_putstr(dest1, str_len);
		printf(" (%zu)\n", offset);

		printf("%-11s", "ft_memcpy:");
		lasm_putstr(dest2, str_len);
		printf(" (%zu)\n", offset);
	}

	lasm_function_state(errors);
}

static void	lasm_check_strdup(void)
{
	char			src1[] = "Pikachu!";
	char			src2[] = "";
	char			*dest1;
	char			*dest2;
	unsigned int	errors = 0;

	lasm_function_name_display("strdup");

	if (g_opt_v)
		printf("%-11s%s\n", "string:", src1);
	dest1 = strdup(src1);
	dest2 = ft_strdup(src1);
	if (strcmp(dest1, dest2))
		errors++;
	if (g_opt_v)
	{
		printf("%-11s", "strdup:");
		printf("%s\n", dest1);
		printf("%-11s", "ft_strdup:");
		printf("%s\n\n", dest2);
	}

	if (g_opt_v)
		printf("%-11s%s\n", "string:", "(empty string)");
	dest1 = strdup(src2);
	dest2 = ft_strdup(src2);
	if (strcmp(dest1, dest2))
		errors++;
	if (g_opt_v)
	{
		printf("%-11s", "strdup:");
		printf("%s\n", dest1);
		printf("%-11s", "ft_strdup:");
		printf("%s\n", dest2);
	}

	lasm_function_state(errors);
}

void	lasm_check_cat(void)
{
	int				fd;
	unsigned int	errors = 0;

	lasm_function_name_display("cat");

	fd = open("Makefile", O_RDONLY);
	ft_cat(fd);
	close(fd);

	ft_cat(-1);
	ft_cat(42);
	ft_puts("STDIN test, please write things:");
	ft_cat(1);

	lasm_function_state(errors);
}

void	lasm_check_abs(void)
{
	int				nb;
	int				ret1;
	int				ret2;
	unsigned int	errors = 0;

	lasm_function_name_display("abs");

	for (nb = -2; nb <= 2; nb += 2)
	{
		ret1 = abs(nb);
		ret2 = ft_abs(nb);
		if (ret1 != ret2)
			errors++;

		if (g_opt_v)
		{
			printf("%-11s", "nb:");
			printf("%d\n", nb);

			printf("%-11s", "abs:");
			printf("%d\n", ret1);
			printf("%-11s", "ft_abs:");
			printf("%d\n", ret2);

			if (nb < 2)
				putchar('\n');
		}
	}

	lasm_function_state(errors);
}

void	lasm_check_atoi(void)
{
	int				i;
	int				ret1;
	int				ret2;
    char			tests[7][11] = {
		"0", "1", "-1", "-2147483648", "2147483647", "   42", "   +54"
	};
	unsigned int	errors = 0;

	lasm_function_name_display("atoi");

	for (i = 0; i < 7; i++)
	{
		ret1 = atoi(tests[i]);
		ret2 = ft_atoi(tests[i]);
		if (ret1 != ret2)
			errors++;

		if (g_opt_v)
		{
			printf("%-11s", "input:");
			printf("%s\n", tests[i]);

			printf("%-11s", "atoi:");
			printf("%d\n", ret1);
			printf("%-11s", "ft_atoi:");
			printf("%d\n", ret2);

			if (i < 7)
				putchar('\n');
		}
	}



	lasm_function_state(errors);
}

int		main(int argc, char **argv)
{
	if (argc > 1 && !strcmp(argv[1], "-v"))
		g_opt_v = 1;

	lasm_check_bzero();
	lasm_check_strcat();
	lasm_check_function_is("isalpha", &isalpha, &ft_isalpha);
	lasm_check_function_is("isdigit", &isdigit, &ft_isdigit);
	lasm_check_function_is("isalnum", &isalnum, &ft_isalnum);
	lasm_check_function_is("isascii", &isascii, &ft_isascii);
	lasm_check_function_is("isprint", &isprint, &ft_isprint);
	lasm_check_toupper();
	lasm_check_tolower();
	lasm_check_puts();
	lasm_check_strlen();
	lasm_check_memset();
	lasm_check_memcpy();
	lasm_check_strdup();
	lasm_check_cat();

	lasm_check_function_is("isupper", &isupper, &ft_isupper);
	lasm_check_function_is("islower", &islower, &ft_islower);
	lasm_check_function_is("ispunct", &ispunct, &ft_ispunct);
	lasm_check_abs();
	lasm_check_atoi();

	lasm_achievement_display();

	return (0);
}

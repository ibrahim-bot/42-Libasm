#include "libasm.h"
#include <stdio.h>

int		launch_strlen(char *str)
{
	if (!str)
	{
		if (ft_strlen(str) == 0)
			return (1);
	}
	if (ft_strlen(str) == strlen(str))
		return (1);
	else
		return (0);
}

void	test_strlen(int *flag)
{
	int		nb;
	char	*tab[] = {"Hello World !", "Coucou", "123456789", NULL};

	printf("\n\033[33m------- Test FT_STRLEN -------\033[00m\n");
	nb = 0;
	while (nb < 3)
	{
		printf("\033[94mTest number %d with \"%s\" : \033[00m", (nb + 1), tab[nb]);
		if (launch_strlen(tab[nb]) == 1)
			printf("\033[32mOK\033[00m\n");
		else
		{
			(*flag)++;
			printf("\033[31mERROR\033[00m\n");
		}
		nb++;
	}
}

// /* TEST FT_STRDUP */
// int		launch_strdup(char *str)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = ft_strdup(str);
// 	s2 = strdup(str);

// 	if (strcmp(s1, s2) == 0)
// 	{
// 		free(s1);
// 		free(s2);
// 		return (1);
// 	}
// 	else
// 	{
// 		free(s1);
// 		free(s2);
// 		return (0);
// 	}
// }

// void	test_strdup(int *flag)
// {
// 	int		nb;
// 	char	*tab[] = {"Hello World !", "Coucou", "", "123456789"};

// 	printf("\n\033[33m------- Test FT_STRDUP -------\033[00m\n");
// 	nb = 0;
// 	while (nb < 4)
// 	{
// 		printf("\033[94mTest number %d with \"%s\" :\033[00m ", (nb + 1), tab[nb]);
// 		if (launch_strdup(tab[nb]) == 1)
// 			printf("\033[32mOK\033[00m\n");
// 		else
// 		{
// 			(*flag)++;
// 			printf("\033[31mERROR\033[00m\n");
// 		}
// 		nb++;
// 	}
// }

void	wait_enter()
{
	printf("\n\033[96mCheck the tests and press ENTER to do the others tests\033[00m\n");
	while (getchar() != '\n')
		;
}

int		main(int ac, char **av)
{
	int		flag;

	flag = 0;

	if (ac == 1)
	{
		wait_enter();
		test_strlen(&flag);
		// wait_enter();
		// test_strdup(&flag);
	}
	printf("\n\033[33m------- FINISH -------\033[00m\n");
    if (flag == 0)
		printf("\033[32mAll tests are good :D\033[00m\n");
	else
		printf("\033[31m%d tests failed :(\033[00m\n", flag);
	printf("\n");
	return (0);
}

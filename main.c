#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>


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
	char	*tab[] = {"Hello World !", "Coucou", "123456789", ""};

	printf("\n\033[33m------- Test FT_STRLEN -------\033[00m\n");
	nb = 0;
	while (nb < 4)
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

int		launch_strdup(char *str)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup(str);
	s2 = strdup(str);

	if (strcmp(s1, s2) == 0)
	{
		free(s1);
		free(s2);
		return (1);
	}
	else
	{
		free(s1);
		free(s2);
		return (0);
	}
}

void	test_strdup(int *flag)
{
	int		nb;
	char	*tab[] = {"Hello World !", "Coucou", "", "123456789"};

	printf("\n\033[33m------- Test FT_STRDUP -------\033[00m\n");
	nb = 0;
	while (nb < 4)
	{
		printf("\033[94mTest number %d with \"%s\" :\033[00m ", (nb + 1), tab[nb]);
		if (launch_strdup(tab[nb]) == 1)
			printf("\033[32mOK\033[00m\n");
		else
		{
			(*flag)++;
			printf("\033[31mERROR\033[00m\n");
		}
		nb++;
	}
}

int		launch_strcpy(char *str)
{
	char	s1[100];
	char	s2[100];

	ft_strcpy(s1, str);
	strcpy(s2, str);

	if (strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}

void	test_strcpy(int *flag)
{
	int		nb;
	char	*tab[] = {"Hello World !", "Coucou", ""};

	nb = 0;	
	printf("\n\033[33m------- Test FT_STRCPY -------\033[00m\n");
	while (nb < 3)
	{
		printf("\033[94mTest number %d with \"%s\" :\033[00m ", (nb + 1), tab[nb]);
		if (launch_strcpy(tab[nb]) == 1)
			printf("\033[32mOK\033[00m\n");
		else
		{
			(*flag)++;
			printf("\033[31mERROR\033[00m\n");
		}
		nb++;
	}
}

int		launch_strcmp(char *str)
{
	static int x = 0;	
	int i = strcmp(str, str);
	int j = ft_strcmp(str, str);

	if (x == 0)
	{
		if (i == j)
		{
			x++;
			return (1);
		}
	}
	else if (x == 1)
	{
		i = strcmp("B", str);
		j = ft_strcmp("B", str);
		if (i == j)
		{
			x++;
			return (1);
		}
	}
	else if (x == 2)
	{
		i = strcmp("A", str);
		j = ft_strcmp("A", str);
		if (i == j)
		{
			x++;
			return (1);
		}
	}
	else if (x == 3)
	{
		i = strcmp("Avril", str);
		j = ft_strcmp("Avril", str);
		if (i == j)
		{
			x++;
			return (1);
		}
	}
	else if (x == 4)
	{
		i = strcmp("Sanglier", str);
		j = ft_strcmp("Sanglier", str);
		if (i == j)
		{
			x++;
			return (1);
		}
	}
	x++;
	return (0);
}

void	test_strcmp(int *flag)
{
	int		nb;
	char	*tab[] = {"Salut", "A", "B", "", "Sanglie "};

	nb = 0;	
	printf("\n\033[33m------- Test FT_STRCMP -------\033[00m\n");
	while (nb < 5)
	{
		printf("\033[94mTest number %d with \"%s\" :\033[00m ", (nb + 1), tab[nb]);
		if (launch_strcpy(tab[nb]) == 1)
			printf("\033[32mOK\033[00m\n");
		else
		{
			(*flag)++;
			printf("\033[31mERROR\033[00m\n");
		}
		nb++;
	}
}

int		launch_write(char *str)
{
	static int x = 0;
	int i = 0;
	int j = 0;

	if (x == 0)
	{
		i = write(1, str, 1);
		j = ft_write(1, str, 1);
		if (i == j)
		{
			x++;
			return (1);
		}
	}
	else if (x == 1)
	{
		i = write(1, str, 5);
		j = ft_write(1, str, 5);
		if (i == j)
		{
			x++;
			return (1);
		}
	}
	else if (x == 2)
	{
		i = write(1, str, 0);
		j = ft_write(1, str, 0);
		if (i == j)
		{
			x++;
			return (1);
		}
	}
	return (0);
}

void	test_write(int *flag)
{
	int		nb;
	char 	c = 's';
	char	*tab[] = {NULL, "", &c};

	nb = 0;	
	printf("\n\033[33m------- Test FT_WRITE -------\033[00m\n");
	while (nb < 3)
	{
		printf("\033[94mTest number %d with \"%s\" :\033[00m ", (nb + 1), tab[nb]);
		if (launch_write(tab[nb]) == 1)
			printf("\033[32mOK\033[00m\n");
		else
		{
			(*flag)++;
			printf("\033[31mERROR\033[00m\n");
		}
		nb++;
	}
}

int		launch_read(char *str)
{
	char	s1[100];
	char	s2[100];

	char data[128];
    int fd;
    int size;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (84);
    
    size = ft_read(fd, data, 127);
    if (size < 0)
        write(2, "An error occurred in the read.\n", 31);
    data[size] = 0;
    write(1, data, size);
    close(fd);

	if (strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}

void	test_read(int *flag)
{
	int		nb;
	char 	c = 's';
	char	*tab[] = {NULL, "", &c};

	nb = 0;	
	printf("\n\033[33m------- Test FT_READ -------\033[00m\n");
	while (nb < 3)
	{
		printf("\033[94mTest number %d with \"%s\" :\033[00m ", (nb + 1), tab[nb]);
		if (launch_read(tab[nb]) == 1)
			printf("\033[32mOK\033[00m\n");
		else
		{
			(*flag)++;
			printf("\033[31mERROR\033[00m\n");
		}
		nb++;
	}
}

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
		wait_enter();
		test_strdup(&flag);
		wait_enter();
		test_strcpy(&flag);
		wait_enter();
		test_strcmp(&flag);
		wait_enter();
		test_write(&flag);
	}
	printf("\n\033[33m------- FINISH -------\033[00m\n");
    if (flag == 0)
		printf("\033[32mAll tests are good :D\033[00m\n");
	else
		printf("\033[31m%d tests failed :(\033[00m\n", flag);
	printf("\n");
	char data[128];
    int fd;
    int size;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (84);
    
    size = ft_read(fd, data, 127);
    if (size < 0)
        write(2, "An error occurred in the read.\n", 31);
    data[size] = 0;
    write(1, data, size);
    close(fd);
	return (0);
}

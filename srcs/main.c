/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:54:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/03/29 16:19:27 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	bonus;
	int	i;
	int	j;
	int	(*f)(int, const char *, ...);
	int	tc = 1;
	int	ts = 1;
//	int	tp = 1;
//	int	td = 1;
//	int	ti = 1;
//	int	tu = 1;
//	int	tx = 1;
//	int	tX = 1;
//	int	tper = 1;
	char	c[] = {'a', '~', 0x00, 0};
	char	*s[] = {"", "abcdefghij", "¡™£¢∞§¶•ªº–≠", 0x00, NULL};

	if (argc != 3)
	{
		printf("%s\n%s\n", strerror(EINVAL), ERR_ARG);
		return (1);
	}
	if (strcmp("0", argv[1]) >= 0)
		f = &dprintf;
	else if (strcmp("1", argv[1]) >= 0)
		f = &ft_printf;
	else
	{
		printf("%s\n%s\n", strerror(EINVAL), ERR_ARGPRINTF);
		return (1);
	}
	bonus = 0;
	if (strcmp("0", argv[2]) >= 0)
		bonus = 0;	
	else if (strcmp("1", argv[2]) >= 0)
		bonus = 1;
	else
	{
		printf("%s\n%s\n", strerror(EINVAL), ERR_ARGBONUS);
		return (1);
	}
	fd = 1;
	i = 0;
	////////////////////////////////////////////////////////////////////////
	if (tc)
	{
		j = 0;
		while ((unsigned long)j < (sizeof(c)/sizeof(c[0])))
		{
			printf("TEST %d\n", j);
			test_c(f, fd, c[j], bonus);
			j++;
		}
		i++;
	}
	////////////////////////////////////////////////////////////////////////
	if (ts)
	{
		j = 0;
		while ((unsigned long)j < (sizeof(s)/sizeof(s[0])))
		{
			printf("TEST %d\n", j);
			test_s(f, fd, s[j], bonus);
			j++;
		}
		i++;
	}
	////////////////////////////////////////////////////////////////////////
	return (0);
}

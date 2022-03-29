/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:16:43 by abarrier          #+#    #+#             */
/*   Updated: 2022/03/29 15:52:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	case_c(int *i, int(*f)(int, const char *, ...),
		int fd, const char *exp, char input)
{
	int	res;

	res = 0;
	printf("****case %d: %c****\n", *i, input);
	res = (*f)(fd, exp, input);
	printf("RES = %d\n", res);
	*i = *i + 1;
}

void	test_c(int(*f)(int, const char *, ...),
		int fd, char input, int bonus)
{
	int	i;

	i = 0;
	case_c(&i, f, fd, ">%c<\n", input);
	if (bonus)
	{
		case_c(&i, f, fd, ">%-10c<\n", input);
		case_c(&i, f, fd, ">%2c<\n", input);
		case_c(&i, f, fd, ">%-2c<\n", input);
		case_c(&i, f, fd, ">%-c<\n", input);
	}
	printf("%s\n", SEP_P);
}

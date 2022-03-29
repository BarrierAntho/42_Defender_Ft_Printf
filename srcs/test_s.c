/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:54:04 by abarrier          #+#    #+#             */
/*   Updated: 2022/03/29 15:59:14 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	case_s(int *i, int(*f)(int, const char *, ...),
		int fd, const char *exp, char *input)
{
	int	res;

	res = 0;
	printf("****case %d: %s****\n", *i, input);
	res = (*f)(fd, exp, input);
	printf("RES = %d\n", res);
	*i = *i + 1;
}

void	test_s(int(*f)(int, const char *, ...),
		int fd, char *input, int bonus)
{
	int	i;

	i = 0;
	case_s(&i, f, fd, ">%s<\n", input);
	if (bonus)
	{
		case_s(&i, f, fd, ">%10s<\n", input);
		case_s(&i, f, fd, ">%.s<\n", input);
		case_s(&i, f, fd, ">%.0s<\n", input);
		case_s(&i, f, fd, ">%2.5s<\n", input);
		case_s(&i, f, fd, ">%5.2s<\n", input);
		case_s(&i, f, fd, ">%.2s<\n", input);
		case_s(&i, f, fd, ">%-2.5s<\n", input);
		case_s(&i, f, fd, ">%-5.2s<\n", input);
		case_s(&i, f, fd, ">%-5.s<\n", input);
		case_s(&i, f, fd, ">%-5.0s<\n", input);
		case_s(&i, f, fd, ">%5s<\n", input);
		case_s(&i, f, fd, ">%-5s<\n", input);
		case_s(&i, f, fd, ">%.03s<\n", input);
		case_s(&i, f, fd, ">%.09s<\n", input);

	}
	printf("%s\n", SEP_P);
}

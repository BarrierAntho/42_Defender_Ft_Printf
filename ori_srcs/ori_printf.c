/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ori_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:54:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/03/28 20:21:58 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ori_printf.h"
#include "../include/test.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("%s\n", strerror(EINVAL));
		return (1);
	}
	int bonus;
	int	i;
	int	j;
	int	tc = 0;
	char	c[] = {'a', '~', 0x00, 0};
//	int	ts = 0;
//	int	tp = 1;
//	int	td = 0;
//	int	ti = 0;
//	int	tu = 0;
//	int	tx = 0;
//	int	tX = 0;
//	int	tper = 0;

	bonus = 0;
	if (argv[1])
		bonus = 1;
	i = 0;
	if (tc)
	{
		j = 0;
		while ((unsigned long)j < (sizeof(c)/sizeof(c[0])))
		{
			printf("TEST %d\n", j);
			test_c(&printf, c[j], bonus);
			j++;
		}
		i++;
	}

	return (0);
}

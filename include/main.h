/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:16:28 by abarrier          #+#    #+#             */
/*   Updated: 2022/03/29 16:00:14 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "../ft_printf/include/ft_printf.h"

# define SEP_P "***********************"
# define ERR_ARG "Expected arg1: 0=printf 1=ft_printf | arg2: 0=no bonus 1=bonus"
# define ERR_ARGPRINTF "Expected arg1: 0=printf 1=ft_printf"
# define ERR_ARGBONUS "Expected arg2: 0=no bonus 1=bonus"

void	test_c(int(*f)(int, const char *, ...), int fd, char input, int bonus);
void	test_s(int(*f)(int, const char *, ...), int fd, char *input, int bonus);

#endif

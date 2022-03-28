#include "../include/test.h"

static void	case_c(int *i, int(*f)(const char *, ...), const char *exp, char input)
{
	int	res = 0;
	printf("****case : %d****\n", *i);
	res = (*f)(exp, input);
	printf("RES = %d\n", res);
	*i = *i + 1;
}

void	test_c(int(*f)(const char *, ...), char input, int bonus)
{
	int j = 0;

	//0----------------------------
	case_c(&j, f, ">%c<\n", input);
	(void)bonus;
//	if (bonus)
//	{
//		//1----------------------------
//		case_c(&j, &f, ">%-10c<\n", input);
//		//2----------------------------
//		case_c(&j, &f, ">%2c<\n", input);
//		//3----------------------------
//		case_c(&j, &f, ">%-2c<\n", input);
//		//4----------------------------
//		case_c(&j, &f, ">%-c<\n", input);
//		//-----------------------------
//	}
	printf("%s\n", SEP_P);
}

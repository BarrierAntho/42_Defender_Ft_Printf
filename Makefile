# User settings
PRINTFPATH	:=	ft_printf
IPRINTF		:=	include
PRINTFHEADER	:=	ft_printf.h
PRINTFNAME	:=	libft.a
PRINTFL		:=	ft

# Standard settings
SEP_P		:=	"----------------------------------------------"
SEP_S		:=	".............................................."
EXEC		:=	printf.out
CC		:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
CFLAGSADD	:=	-Wconversion -g3 -fsanitize=address
DFLAGS		:=	-MMD

IPATH		:=	include

# SOURCES FOLDER
SRCSPATH	:=	srcs

RM		:=	rm -rf

# Copying fr_printf.h path into include/main.h
SEDTEXT		:=	'19s/xxxx/${PRINTFPATH}\/${IPRINTF}\/${PRINTFHEADER}/g'
COPYINGHEADER	:= 	$(shell sed -i ${SEDTEXT} include/main.h)

HEADERS		:=	$(wildcard ${IPATH}/*.h)
SRCS		:=	$(wildcard ${SRCSPATH}/*.c)

OBJS		=	${SRCS:.c=.o}

all:			${EXEC} 

%.o:			%.c ${HEADERS}
			${CC} ${CFLAGS} ${CFLAGSADD} -I ${IPATH} -I ${PRINTFPATH}/${IPRINTF} -c $< -o $@

${EXEC}:		${OBJS} 
			make -C ${PRINTFPATH}
			${CC} ${CFLAGS} ${CFLAGSADD} ${OBJS} -I ${PRINTFPATH}/${IPRINTF} -L${PRINTFPATH} -l${PRINTFL} -o ${EXEC} 
clean:
			make clean -C ${PRINTFPATH}
			${RM} ${OBJS}

fclean:			
			make fclean -C ${PRINTFPATH}
			make clean
			${RM} ${EXEC}

re:			
			make re -C ${PRINTFPATH}
			make fclean all

norme:
			@echo ${SEP_P}
			norminette ${SRCSPATH}
			@echo ${SEP_P}
			make norme -C ${PRINTFPATH}

run_ori_no_bonus:
			@make all -s
			@./${EXEC} 0 0

run_mft_no_bonus:
			@make all -s
			@./${EXEC} 1 0

.PHONY:			all clean fclean re norme

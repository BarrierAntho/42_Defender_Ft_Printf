# User settings
PRINTFPATH	:=	ft_printf
PRINTFNAME	:=	ft

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
SRCSPATH	:=	test
ORIPATH		:=	ori_srcs

RM		:=	rm -rf

HEADERS		:=	$(wildcard ${IPATH}/*.h)
SRCS		:=	$(wildcard ${SRCSPATH}/*.c)

ORIHEADERS	:=	$(wildcard ${ORIPATH}/*.h)
ORISRCS		:=	$(wildcard ${ORIPATH}/*.c)

OBJS		=	${SRCS:.c=.o}\
			${ORISRCS:.c=.o}

all:			${EXEC} ${PRINTFNAME}

%.o:			%.c ${HEADERS}
			${CC} ${CFLAGS} ${CFLAGSADD} -I ${IPATH} -c $< -o $@

${EXEC}:		${OBJS}
			make -C ${PRINTFPATH}
			${CC} ${CFLAGS} ${CFLAGSADD} -L${PRINTFPATH} -l${PRINTFNAME} ${OBJS} -o ${EXEC}

clean:
			${RM} ${OBJS}

fclean:			clean
			${RM} ${EXEC}

re:			fclean all

norme:
			@echo ${SEP_P}
			norminette ${PRINTFPATH}

.PHONY:			all clean fclean re norme

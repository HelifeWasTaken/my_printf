##
## EPITECH PROJECT, 2020
## Sample Makefile
## File description:
## A sample of a Makefile to start Epitech
##

CC			=	gcc

AR 			= 	ar rc

CFLAGS 		=	-W -Werror -Wall -Wextra -I./include -g3 -lcsfml-graphics

SRC 		=	./lib/fd/ldputchar.c \
				./lib/fd/ldputnbr.c \
				./lib/fd/ldputnbr_base.c \
				./lib/fd/ldputs.c \
				./lib/fd/ldshowptr.c \
				./lib/fd/ldprint_loop.c \
				./lib/fd/ldputfloat.c \
				\
				./lib/stdio/lputchar.c \
				./lib/stdio/lputnbr.c \
				./lib/stdio/lputs.c \
				./lib/stdio/lprintf.c \
				./lib/stdio/ldprintf.c \
				\
				./lib/stdio/lprintf_check_error_format.c \
				./lib/stdio/lvprintf/lvdprintf.c \
				./lib/stdio/lvprintf/parse_flag.c \
				./lib/stdio/lvprintf/lvdprintf_local/lvdprintf_local_char.c \
				./lib/stdio/lvprintf/lvdprintf_local/lvdprintf_local_int.c \
				./lib/stdio/lvprintf/lvdprintf_local/lvdprintf_local_str.c \
				./lib/stdio/lvprintf/lvdprintf_local/lvdprintf_local_oct.c \
				./lib/stdio/lvprintf/lvdprintf_local/lvdprintf_local_uint.c \
				./lib/stdio/lvprintf/lvdprintf_local/lvdprintf_local_hex.c \
				./lib/stdio/lvprintf/lvdprintf_local/lvdprintf_local_pointer.c \
				./lib/stdio/lvprintf/lvdprintf_local/lvdprintf_local_float.c \
				./lib/stdio/lvprintf/lvdprintf_local/parse_type.c \
				./lib/stdio/lvprintf/lenght_modifiers/lprintf_flag_character.c \
				./lib/stdio/lvprintf/lenght_modifiers/lprintf_lenght_modifiers.c \
				\
				./lib/ctypes/lisalpha.c \
				./lib/ctypes/lisnum.c \
				./lib/ctypes/lisalphanum.c \
				./lib/ctypes/lisprintable.c \
				./lib/ctypes/lislower.c \
				./lib/ctypes/lisupper.c \
				./lib/ctypes/lisspace.c \
				./lib/ctypes/lispunct.c \
				./lib/ctypes/ltolower.c \
				./lib/ctypes/ltoupper.c \
				\
				./lib/stdlib/lbzero.c \
				./lib/stdlib/lcalloc.c \
				./lib/stdlib/lptr_swap.c \
				./lib/stdlib/lrealloc.c \
				./lib/stdlib/lshowptr.c \
				./lib/stdlib/lswap.c \
				./lib/stdlib/latoi.c \
				./lib/stdlib/latol.c \
				./lib/stdlib/latoll.c \
				\
				./lib/math/lfmod.c \
				./lib/math/lnblen.c \
				./lib/math/loderound.c \
				./lib/math/lpow.c \
				./lib/math/lsqrt.c \
				\
				./lib/string/lmemcmp.c \
				./lib/string/lmemcpy.c \
				./lib/string/lmemmove.c \
				./lib/string/lmemset.c \
				./lib/string/lprint_loop.c \
				./lib/string/lrevstr.c \
				./lib/string/lstr_realocat.c \
				./lib/string/lsplit.c \
				./lib/string/lstrcat.c \
				./lib/string/lstrchr.c \
				./lib/string/lstrcmp.c \
				./lib/string/lstrncmp.c \
				./lib/string/lstrcpy.c \
				./lib/string/lstrdup.c \
				./lib/string/lstrlen.c \
				./lib/string/lstrncat.c \
				./lib/string/lstrncpy.c \
				./lib/string/lstrstr.c \
				./lib/string/lstrndup.c

OBJ 		=	$(SRC:.c=.o)

NAME 		=	liblodeus.a

all:		$(NAME)

$(NAME): build_lib build

build:
	$(CC) $(CFLAGS) main.c -L./ -l lodeus -lcriterion -o lodeus

build_lib: 	$(OBJ)
	$(AR) $(NAME) $(OBJ)

copy:
	mkdir -p ../../include
	cp include/*.h ../../include

clean: ## Clean every temporay well knowed files
	@find . -type f \( -name "\#*\#" -o -name "*.swp" \) -delete
	@find . -type f \( -name "*.gc*" -o -name "a.out" \) -delete
	@find . -type f \( -name "*.o" -o -name "*~" -o -name "*.a" \) -delete
	@echo "Cleaned project !"

fclean:		clean ## Call clean rule nothing more

re:			fclean all ## Call fclean then all rule

usage: ## Print the usage
	@grep -h "##" Makefile | sed -e 's/\(\:.*\#\#\)/\:\ /' | grep -v grep | sed -e 's/\\$$//' | sed -e 's/##//'
	@echo "\nEnjoy the project ! :D"

.PHONY:		all build_lib copy clean fclean re

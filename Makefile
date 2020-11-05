##
## EPITECH PROJECT, 2020
## Sample Makefile
## File description:
## A sample of a Makefile to start Epitech
##

CC			=	gcc

CFLAGS 		=	-W -Wall -Wextra -pedantic -Werror -I./include

LFLAGS 		=	-L./lib -lmy

PATH_LIB 	= 	./lib/my

PATH_T_MY 	= 	./tests/tests_libmy

PATH_VNL 	= 	print_formatter/vn_redirect

SRC_TEST	=   $(PATH_LIB)/my_math/my_compute_power_rec.c \
				$(PATH_LIB)/my_math/my_compute_square_root.c \
				$(PATH_LIB)/my_math/my_find_prime_sup.c \
				$(PATH_LIB)/my_math/my_is_prime.c \
				$(PATH_LIB)/my_math/my_putnbr_base.c \
				$(PATH_LIB)/my_math/my_putnbr_base_unsigned.c \
				$(PATH_LIB)/my_math/my_putfloat.c \
				$(PATH_LIB)/my_math/get_nb_size.c \
				$(PATH_LIB)/my_math/get_nb_size_unsigned.c \
				$(PATH_LIB)/my_math/my_put_nbr.c \
				$(PATH_LIB)/my_math/my_put_nbr_unsigned.c \
				\
				$(PATH_LIB)/my_stdlib/my_bzero.c \
				$(PATH_LIB)/my_stdlib/my_calloc.c \
				$(PATH_LIB)/my_stdlib/my_getnbr.c \
				$(PATH_LIB)/my_stdlib/my_itoa.c \
				$(PATH_LIB)/my_stdlib/my_memset.c \
				$(PATH_LIB)/my_stdlib/my_pointer_swap.c \
				$(PATH_LIB)/my_stdlib/my_sort_int_array.c \
				$(PATH_LIB)/my_stdlib/my_strdup.c \
				$(PATH_LIB)/my_stdlib/my_str_to_word_array.c \
				$(PATH_LIB)/my_stdlib/my_swap.c \
				$(PATH_LIB)/my_stdlib/my_put_pointer.c \
				\
				$(PATH_LIB)/my_stdio/my_putstr_err.c \
				$(PATH_LIB)/my_stdio/my_putchar.c \
				$(PATH_LIB)/my_stdio/my_putstr.c \
				\
				$(PATH_LIB)/my_str/concat_params.c \
				$(PATH_LIB)/my_str/is_capital_letter.c \
				$(PATH_LIB)/my_str/is_lowercase_letter.c \
				$(PATH_LIB)/my_str/is_an_alpha_letter.c \
				$(PATH_LIB)/my_str/is_num_letter.c \
				$(PATH_LIB)/my_str/is_printable.c \
				$(PATH_LIB)/my_str/is_char_alphanum.c \
				$(PATH_LIB)/my_str/my_len_array.c \
				$(PATH_LIB)/my_str/my_put_in_str.c \
				$(PATH_LIB)/my_str/my_revstr.c \
				$(PATH_LIB)/my_str/my_showstr.c \
				$(PATH_LIB)/my_str/my_show_word_array.c \
				$(PATH_LIB)/my_str/my_strcapitalize.c \
				$(PATH_LIB)/my_str/my_strcat.c \
				$(PATH_LIB)/my_str/my_strcmp.c \
				$(PATH_LIB)/my_str/my_strcpy.c \
				$(PATH_LIB)/my_str/my_strlen.c \
				$(PATH_LIB)/my_str/my_strncat.c \
				$(PATH_LIB)/my_str/my_strncmp.c \
				$(PATH_LIB)/my_str/my_strncpy.c \
				$(PATH_LIB)/my_str/my_strstr.c \
				$(PATH_LIB)/my_str/my_word_count.c \
				$(PATH_LIB)/my_str/print_char_in_hex.c \
				$(PATH_LIB)/my_str/print_char_in_oct.c \
				\
				$(PATH_LIB)/print_formatter/my_printf.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putbin.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putchar.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_puthex_higher.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_puthex_lower.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putnbr.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putoctal.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putstr.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_showstr_oct.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putpointer.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_get_send_to_stdio.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putnbr_unsigned.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putfloat_precision_6.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_puthex_higher_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_puthex_lower_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putnbr_unsigned_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putoctal_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putnbr_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_puthex_higher_long_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_puthex_lower_long_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putnbr_unsigned_long_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putoctal_long_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_putnbr_long_long.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_hex_high_to_unsigned_char.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_hex_low_to_unsigned_char.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_int_to_unsigned_char.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_oct_to_unsigned_char.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_unsigned_to_unsigned_char.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_int_to_short_int.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_unsigned_to_short_int.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_hex_low_to_short_int.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_hex_high_to_short_int.c \
				$(PATH_LIB)/$(PATH_VNL)/my_vn_cast_oct_to_short_int.c\
				\
				$(PATH_T_MY)/my_math/test_get_nb_size.c \
				$(PATH_T_MY)/my_math/test_my_compute_power_rec.c \
				$(PATH_T_MY)/my_math/test_my_compute_square_root.c \
				$(PATH_T_MY)/my_math/test_is_prime_and_sup.c \
				$(PATH_T_MY)/my_math/test_putnbr_and_unsigned.c \
				$(PATH_T_MY)/my_math/test_putnbr_base_and_unsigned.c \
				$(PATH_T_MY)/my_math/test_my_putfloat.c \
				\
				$(PATH_T_MY)/my_stdio/test_my_putchar.c \
				$(PATH_T_MY)/my_stdio/test_my_putstr.c \
				\
				$(PATH_T_MY)/my_stdlib/test_my_calloc_memset_and_bzero.c \
				$(PATH_T_MY)/my_stdlib/test_my_getnbr.c \
				$(PATH_T_MY)/my_stdlib/test_my_itoa.c \
				$(PATH_T_MY)/my_stdlib/test_my_pointer_swap.c \
				$(PATH_T_MY)/my_stdlib/test_my_put_pointer.c \
				$(PATH_T_MY)/my_stdlib/test_my_sort_int_array.c \
				$(PATH_T_MY)/my_stdlib/test_my_str_to_word_array.c \
				\
				$(PATH_T_MY)/my_str/test_concat_params.c \
				$(PATH_T_MY)/my_str/test_is_an.c \
				$(PATH_T_MY)/my_str/test_my_put_in_str.c \
				$(PATH_T_MY)/my_str/test_my_revstr.c \
				$(PATH_T_MY)/my_str/test_my_show_array.c \
				$(PATH_T_MY)/my_str/test_my_showstr.c \
				$(PATH_T_MY)/my_str/test_my_strcapitalize.c \
				$(PATH_T_MY)/my_str/test_my_strcmp.c \
				$(PATH_T_MY)/my_str/test_my_strncat.c \
				$(PATH_T_MY)/my_str/test_my_strncpy.c \
				$(PATH_T_MY)/my_str/test_my_strstr.c \
				$(PATH_T_MY)/my_str/test_print_char_in.c

TEST_FLAGS		= 	-lcriterion --coverage

UNIT_TEST_EXEC 	= 	$(NAME)_unit_tests

all: 	build_lib ## Calls build_lib

build_lib: ## Builds the lib
	make -C ./lib/my

clean: ## Clean every temporay well knowed files
	@find . -type f \( -name "\#*\#" -o -name "*.swp" \) -delete
	@find . -type f \( -name "*.gc*" -o -name "a.out" \) -delete
	@find . -type f \( -name "*.o" -o -name "*~" -o -name "*.a" \) -delete
	@echo "Cleaned project !"

fclean:		clean ## Call clean rule nothing more

re:			fclean all ## Call fclean then all rule

test: tests_run

tests_run: clean ## Cleans the project and run the unit tests
	make copy -C ./lib/my
	$(CC) $(SRC_TEST) $(CFLAGS) $(TEST_FLAGS) -o $(UNIT_TEST_EXEC)
	./$(UNIT_TEST_EXEC)
	gcovr -e tests -b

usage: ## Print the usage
	@grep -h "##" Makefile | sed -e 's/\(\:.*\#\#\)/\:\ /' | grep -v grep | sed -e 's/\\$$//' | sed -e 's/##//'
	@echo "\nEnjoy the project ! :D"

.PHONY:		all build_lib clean fclean re

##
## EPITECH PROJECT, 2020
## Sample Makefile
## File description:
## A sample of a Makefile to start Epitech
##

CC			=	gcc

CFLAGS 		=	-W -Wall -Wextra -pedantic -Werror -I./include

LFLAGS 		=	-L./lib -lmy

SRC_TEST 	=   ./lib/my/my_math/my_compute_power_rec.c \
				./lib/my/my_math/my_compute_square_root.c \
				./lib/my/my_math/my_find_prime_sup.c \
				./lib/my/my_math/my_is_prime.c \
				./lib/my/my_math/my_putnbr_base.c \
				./lib/my/my_math/my_putnbr_base_unsigned.c \
				./lib/my/my_math/my_putfloat.c \
				./lib/my/my_math/get_nb_size.c \
				./lib/my/my_math/get_nb_size_unsigned.c \
				./lib/my/my_math/my_put_nbr.c \
				./lib/my/my_math/my_put_nbr_unsigned.c \
				\
				./lib/my/my_stdlib/my_bzero.c \
				./lib/my/my_stdlib/my_calloc.c \
				./lib/my/my_stdlib/my_getnbr.c \
				./lib/my/my_stdlib/my_itoa.c \
				./lib/my/my_stdlib/my_memset.c \
				./lib/my/my_stdlib/my_pointer_swap.c \
				./lib/my/my_stdlib/my_sort_int_array.c \
				./lib/my/my_stdlib/my_strdup.c \
				./lib/my/my_stdlib/my_str_to_word_array.c \
				./lib/my/my_stdlib/my_swap.c \
				./lib/my/my_stdlib/my_put_pointer.c \
				\
				./lib/my/my_stdio/my_putstr_err.c \
				./lib/my/my_stdio/my_putchar.c \
				./lib/my/my_stdio/my_putstr.c \
				\
				./lib/my/my_str/concat_params.c \
				./lib/my/my_str/is_capital_letter.c \
				./lib/my/my_str/is_lowercase_letter.c \
				./lib/my/my_str/is_an_alpha_letter.c \
				./lib/my/my_str/is_num_letter.c \
				./lib/my/my_str/is_printable.c \
				./lib/my/my_str/is_char_alphanum.c \
				./lib/my/my_str/my_len_array.c \
				./lib/my/my_str/my_put_in_str.c \
				./lib/my/my_str/my_revstr.c \
				./lib/my/my_str/my_showstr.c \
				./lib/my/my_str/my_show_word_array.c \
				./lib/my/my_str/my_strcapitalize.c \
				./lib/my/my_str/my_strcat.c \
				./lib/my/my_str/my_strcmp.c \
				./lib/my/my_str/my_strcpy.c \
				./lib/my/my_str/my_strlen.c \
				./lib/my/my_str/my_strncat.c \
				./lib/my/my_str/my_strncmp.c \
				./lib/my/my_str/my_strncpy.c \
				./lib/my/my_str/my_strstr.c \
				./lib/my/my_str/my_word_count.c \
				./lib/my/my_str/print_char_in_hex.c \
				./lib/my/my_str/print_char_in_oct.c \
				\
				./lib/my/print_formatter/my_printf.c \
				./lib/my/print_formatter/my_printf_parser.c \
				./lib/my/print_formatter/my_printf_flag_check/get_modificater_flag.c \
				./lib/my/print_formatter/process_my_printf_exception.c \
				./lib/my/print_formatter/print_following_spaces.c \
				\
				./lib/my/print_formatter/format_transform/prepare_print_str.c \
				./lib/my/print_formatter/format_transform/prepare_print_int.c \
				./lib/my/print_formatter/format_transform/prepare_print_hex.c \
				./lib/my/print_formatter/format_transform/prepare_print_oct.c \
				./lib/my/print_formatter/format_transform/prepare_print_unsigned_int.c \
				\
				./lib/my/print_formatter/vn_redirect/my_vn_putbin.c \
				./lib/my/print_formatter/vn_redirect/my_vn_putchar.c \
				./lib/my/print_formatter/vn_redirect/my_vn_puthex.c \
				./lib/my/print_formatter/vn_redirect/my_vn_putnbr.c \
				./lib/my/print_formatter/vn_redirect/my_vn_putoctal.c \
				./lib/my/print_formatter/vn_redirect/my_vn_putstr.c \
				./lib/my/print_formatter/vn_redirect/my_vn_showstr_oct.c \
				./lib/my/print_formatter/vn_redirect/my_vn_putpointer.c \
				./lib/my/print_formatter/vn_redirect/my_vn_get_send_to_stdio.c \
				./lib/my/print_formatter/vn_redirect/my_vn_putnbr_unsigned.c \
				./lib/my/print_formatter/vn_redirect/my_vn_putfloat.c \
				\
				./tests/tests_libmy/my_math/test_get_nb_size.c \
				./tests/tests_libmy/my_math/test_my_compute_power_rec.c \
				./tests/tests_libmy/my_math/test_my_compute_square_root.c \
				./tests/tests_libmy/my_math/test_is_prime_and_sup.c \
				./tests/tests_libmy/my_math/test_putnbr_and_unsigned.c \
				./tests/tests_libmy/my_math/test_putnbr_base_and_unsigned.c \
				./tests/tests_libmy/my_math/test_my_putfloat.c \
				\
				./tests/tests_libmy/my_stdio/test_my_putchar.c \
				./tests/tests_libmy/my_stdio/test_my_putstr.c \
				./tests/tests_libmy/my_stdio/test_my_printf.c \
				\
				./tests/tests_libmy/my_stdlib/test_my_calloc_memset_and_bzero.c \
				./tests/tests_libmy/my_stdlib/test_my_getnbr.c \
				./tests/tests_libmy/my_stdlib/test_my_itoa.c \
				./tests/tests_libmy/my_stdlib/test_my_pointer_swap.c \
				./tests/tests_libmy/my_stdlib/test_my_put_pointer.c \
				./tests/tests_libmy/my_stdlib/test_my_sort_int_array.c \
				./tests/tests_libmy/my_stdlib/test_my_str_to_word_array.c \
				\
				./tests/tests_libmy/my_str/test_concat_params.c \
				./tests/tests_libmy/my_str/test_is_an.c \
				./tests/tests_libmy/my_str/test_my_put_in_str.c \
				./tests/tests_libmy/my_str/test_my_revstr.c \
				./tests/tests_libmy/my_str/test_my_show_array.c \
				./tests/tests_libmy/my_str/test_my_showstr.c \
				./tests/tests_libmy/my_str/test_my_strcapitalize.c \
				./tests/tests_libmy/my_str/test_my_strcmp.c \
				./tests/tests_libmy/my_str/test_my_strncat.c \
				./tests/tests_libmy/my_str/test_my_strncpy.c \
				./tests/tests_libmy/my_str/test_my_strstr.c \
				./tests/tests_libmy/my_str/test_print_char_in.c

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

test: tests_run ## An alias to tests_run

tests_run: clean ## Cleans the project and run the unit tests
	make copy -C ./lib/my
	$(CC) $(SRC_TEST) $(CFLAGS) $(TEST_FLAGS) -o $(UNIT_TEST_EXEC)
	./$(UNIT_TEST_EXEC)

usage: ## Print the usage
	@grep -h "##" Makefile | sed -e 's/\(\:.*\#\#\)/\:\ /' | grep -v grep | sed -e 's/\\$$//' | sed -e 's/##//'
	@echo "\nEnjoy the project ! :D"

.PHONY:		all build_lib clean fclean re test tests_run usage

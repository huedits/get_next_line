gcc -Wall -Wextra -Werror -I ./ get_next_line.c get_next_line_utils.c main.c $1 -g3
valgrind --track-origins=yes ./a.out > result.txt 2> leaks
diff teste.txt result.txt > result.diff
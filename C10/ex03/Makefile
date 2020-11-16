TARGET=ft_hexdump
C_FILES=$(addprefix srcs/, main.c input.c hex.c print_lines.c strings.c)
O_FILES=$(C_FILES:.c=.o)
HEADERS=includes
FLAGS=-Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(O_FILES)
	/usr/bin/gcc $(FLAGS) $(O_FILES) -o $(TARGET) -I$(HEADERS)

$(O_FILES): %.o:%.c
	/usr/bin/gcc $(FLAGS) -c $< -o $@ -I$(HEADERS)

clean: all
	/bin/rm $(O_FILES)

fclean: clean
	/bin/rm $(TARGET)

re: fclean all

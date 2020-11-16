TARGET=ft_tail
C_FILES=$(addprefix srcs/, main.c ft_tail.c ft_string.c ft_error.c)
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

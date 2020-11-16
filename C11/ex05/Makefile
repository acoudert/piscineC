TARGET=do-op
C_FILES=$(addprefix srcs/, main.c ft_strings.c ft_operations.c)
O_FILES=$(C_FILES:.c=.o)
HEADER=includes
FLAGS=-Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(O_FILES)
	/usr/bin/gcc $(FLAGS) $(O_FILES) -o $(TARGET) -I$(HEADER)

$(O_FILES): %.o:%.c
	/usr/bin/gcc $(FLAGS) -c $< -o $@ -I$(HEADER)

clean: all
	/bin/rm $(O_FILES)

fclean: clean
	/bin/rm $(TARGET)

re: fclean all

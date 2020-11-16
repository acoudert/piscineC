TARGET=ft_display_file
C_FILE=ft_display_file.c
O_FILE=$(C_FILE:.c=.o)
FLAGS=-Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(O_FILE)
	/usr/bin/gcc $(FLAGS) $(O_FILE) -o $(TARGET)

$(O_FILE): %.o:%.c
	/usr/bin/gcc $(FLAGS) -c $(C_FILE) -o $(O_FILE)

clean: all
	/bin/rm $(O_FILE)

fclean: clean
	/bin/rm $(TARGET)

re: fclean all

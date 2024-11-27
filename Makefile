SRC = manage.cpp edit_building.cpp checkers.cpp list_buildings.cpp utils.cpp \
		init_data.cpp available_apartments.cpp reservations.cpp calendar.cpp
OBJECTS = $(SRC:.cpp=.o)
CC = c++
RM = rm -f

NAME = gesRAE

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

r: all clean
	@clear
	@./$(NAME)


.PHONY: all clean fclean re	
NAME 		=	hotrace
DIRSRC 		=	src
OBJD 		=	obj
INCLUDE 	=	head
OBJ			=	$(SRC:.cpp=.o)
OBJS		=	$(OBJ:%=$(OBJD)/%)

SRC 		= 	db.cpp \
				entry.cpp \
				main.cpp	\
				hashmap.cpp	\
				hashitem.cpp


CFLAGS		=	-g3 -fsanitize=address#-Wall -Wextra -Werror #-march=native -pipe -O3 #-g3 -fsanitize=address #
CC			=	clang++

all : $(NAME)

$(NAME) 	: $(OBJD) $(OBJS)
			$(CC) $(CFLAGS) -lpthread -pthread -I ./ -o $(NAME) $(OBJS) $(LIB)

$(OBJD)	:
			@mkdir $(OBJD)

$(OBJD)/%.o	:	$(DIRSRC)/%.cpp
					$(CC) -I ./$(INCLUDE) $(CFLAGS) -o $@ -c $<

run : all
	./$(NAME)

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(OBJD)

re : fclean all

.PHONY : all clean fclean re
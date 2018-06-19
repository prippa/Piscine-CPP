NAME			=	replace
RUN				=	clang++
FLAGS			=	-Wall -Wextra -Werror

MEGAPHONE_CPP 	=	main.cpp

OBJ				=	$(MEGAPHONE_CPP:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(RUN) -o $(NAME) $(OBJ)
	@echo "Compiling" [ $(NAME) ]

%.o: %.cpp
	@$(RUN) $(FLAGS) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ)
	@echo "Clean [ obj files ]"

fclean:
	@rm -rf $(OBJ)
	@echo "Clean [ obj files ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all
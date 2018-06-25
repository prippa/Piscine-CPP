# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 20:46:24 by akokoshk          #+#    #+#              #
#    Updated: 2018/02/01 22:21:01 by akokoshk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CLANG MAKE

NAME = ft_retro
CC = clang++
FLAGS = -Wall -Wextra -Werror
NCURFLAG = -lncurses
SOURCES = main.cpp Ncurse.cpp Game.cpp Player.cpp Enemies.cpp GameObj.cpp Shot.cpp \
	ftList.cpp Asteroid.cpp Boss.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(NCURFLAG) $(OBJECTS) -o $(NAME)
	@echo "ft_retro compiled"

#$(CC) −lncurses $(OBJECTS) -o $(NAME)
#@ar rc $(NAME) $(OBJECTS_PF) $(OBJECTS_LIB). #$(FLAGS) -lncurses

clean:
	@rm -f $(OBJECTS)
	@echo "ft_retro cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "ft_retro fcleaned"

re:	fclean all
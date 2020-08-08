# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: luwargni <luwargni@student.42.fr>		  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2018/11/06 19:24:01 by lomasse		   #+#	#+#			  #
#	Updated: 2019/11/26 20:45:09 by luwargni		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME			= libft.a

SRC_PATH		= srcs

SRCS			= $(shell ls | grep -E ".+\.c")

INC	 			= -I ./

CC 				= gcc

LIBS_FLAGS		= ar r

FLAGS			= -Wall -Wextra -Werror

OBJS			= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(LIBS_FLAGS) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(INC) -o $@ -c $< $(FLAGS)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean			: clean
	@rm -rf $(NAME)

re				: fclean all

.PHONY: fclean re all clean

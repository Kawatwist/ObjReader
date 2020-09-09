# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 18:00:02 by lomasse           #+#    #+#              #
#    Updated: 2020/08/16 15:42:39 by lomasse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libobjreader.a

SRCS = Sources/Initiaize/init_obj.c		\
	Sources/Initiaize/other.c			\
	Sources/Free/free_obj.c				\
	Sources/Parsing/fill_face.c			\
	Sources/Parsing/fill_vertex.c		\
	Sources/Parsing/main_parser.c		\
	Sources/Parsing/objload.c			\
	Sources/Parsing/parsing_vertex.c	\
	Sources/Parsing/realloc_vertex.c	\
	Sources/Parsing/skip_whitespace.c	\
	Sources/Mtl/mtl_parser.c			\
	Sources/Mtl/parsingv1.c				\
	Sources/Mtl/parsingv2.c				\

INC = -I ./Includes/ \
		 -I ./libft/

LIB = ./libft/libft.a

FLAGS = -Ofast

CC 				= gcc

OBJS			= $(SRCS:.c=.o)

LIBS_FLAGS = ar r

$(NAME): $(OBJS)
	$(LIBS_FLAGS) $(NAME) $(OBJS) $(LIB)

%.o: %.c
	$(CC) $(INC) -o $@ -c $< $(FLAGS)

all: $(NAME)

clean : 
	rm Sources/*/*.o
	rm Includes/*.gch

check :
	gcc Sources/main.c Sources/Initiaize/init_obj.c Sources/Initiaize/other.c Sources/Free/free_obj.c Includes/ObjReader.h Includes/ObjError.h Sources/Parsing/objload.c libft/libft.a libft/get_next_line.h Sources/Parsing/main_parser.c Sources/Parsing/parsing_vertex.c Sources/Parsing/skip_whitespace.c Sources/Parsing/realloc_vertex.c libft/libft.h Sources/Parsing/fill_vertex.c Sources/Parsing/fill_face.c Sources/Mtl/mtl_parser.c Sources/Mtl/parsingv1.c Sources/Mtl/parsingv2.c Includes/MtlReader.h
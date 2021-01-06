# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 11:11:47 by ichougra          #+#    #+#              #
#    Updated: 2021/01/06 08:36:05 by ichougra         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

CC		=	nasm

FLAGS	=	-f macho64

HEADER  =	libasm.h

LFLAGS	=	-I $(HEADER)

SRCS	=	main.c

ASM		=	ft_strlen.s ft_strdup.s	ft_strcpy.s\
# 			ft_strcmp.s\
#			ft_write.s\
# 			ft_read.s\ 			


ASMOBJ	=	$(ASM:.s=.o)

all: $(NAME)

$(NAME): $(ASMOBJ) $(HEADER)
	@ar rcs $(NAME) $(ASMOBJ)
	@echo "\033[36m[OK] \033[0m Making libasm...\t\033[92m√\033[0m"

%.o : %.s $(HEADER)
	@$(CC) $(FLAGS) -s $< -o $@

clean:
	@rm -f $(ASMOBJ)
	@echo "\033[36m[OK] \033[0m Clean: (libasm) \033[92m   √\033[0m"

fclean: clean
	@rm -rf $(NAME) test test.dSYM
	@echo "\033[36m[OK] \033[0m Fclean: (libasm) \033[92m   √\033[0m"

re : fclean all

.PHONY: all fclean clean re

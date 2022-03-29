# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 13:09:39 by minsunki          #+#    #+#              #
#    Updated: 2022/03/29 12:34:09 by minsunki         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME			=		ex03

SRCF			=		.	

FIL_M			=		main Bureaucrat Form ShrubberyCreationForm \
						RobotomyRequestForm PresidentialPardonForm \
						Intern

SRCS_M			=		$(addsuffix .cpp, $(FIL_M))

OBJS_M			=		$(SRCS_M:.cpp=.o)

CC				=		c++
WFLAG			=		-Wall -Wextra -Werror
CPPFLAG			=		-std=c++98
RM				=		rm -f

%.o				:		%.cpp
						$(CC) $(WFLAG) $(CPPFLAG) -c $< -o $@

$(NAME)         :		$(OBJS_M)
						$(CC) $(OBJS_M) $(WFLAG) $(CPPFLAG) -o $(NAME)

clean           :
						$(RM) $(OBJS_M)
						$(RM) *_shrubbery

all				:		$(NAME)

fclean          :		clean
						$(RM) $(NAME)

re				:		fclean all

.PHONY          :		.c.o all clean fclean re
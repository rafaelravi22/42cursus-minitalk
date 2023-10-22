
SOURCEFILES	= 	client.c server.c 
OBJECTS	= $(SOURCEFILES:.c=.o)

COMPILER = gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re, server client

server: server.o
	$(COMPILER) $(FLAGS) server.o -o server
	$(RM) server.o

client: client.o
	$(COMPILER) $(FLAGS) client.o -o client
	$(RM) client.o
	
%.o : %.c
	${COMPILER} ${FLAGS} -c $< -o $@

all: server client

clean:
	${RM} ${OBJECTS} 

fclean: clean
	${RM}  server client

re: fclean all

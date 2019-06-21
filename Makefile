NAME=PCP_restoPicker
CPP=clang++
GREEN = \e[32m
RED = \e[31m
WHITE = \e[0m
YELLOW = \e[33m
SRC_FOLDER := source/
SRC := main.cpp\

SRC := $(addprefix $(SRC_FOLDER),$(SRC))
INC := -I include/general \
			 -I include/ \

OBJ := $(SRC:.cpp=.o)
CFLAGS := $(INC) -g -F -Wall
LDFLAGS := -lpthread 

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CPP) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS) -fsanitize=address

clean:
	rm -Rf out.txt
	@rm -Rf $(OBJ)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all

%.o: %.cpp
	@$(CPP) $(CFLAGS) -c $^ -o $@
	@printf "$(GREEN) $(NAME) $(WHITE)  : Built $(YELLOW) $@\n"

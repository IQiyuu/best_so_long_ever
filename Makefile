NAME = so_long
LIB = slime_attak.a

FILES = actions \
		utils \
		struct_init

GFILES = init \
		 menu \
		 hooks \
		 game_menu \
		 game

GS = $(foreach f, $(GFILES), srcs/window/$(f).c)
S = $(foreach f, $(FILES), srcs/$(f).c)

GOBJ = $(GS:.c=.o)
OBJ = $(S:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I headers/ -I minilibx/include -fsanitize=address -g
G_FLG = minilibx/libmlx42.a -lglfw -L "/Users/$(shell echo $(USER))/.brew/opt/glfw/lib/"

C1			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/200")
C2			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/100")
C4			= $(shell bc <<< "255 - (((($(CMP_COUNT) - ($(CMP_TOTAL) / 2))*100)/($(CMP_TOTAL) / 2))*255)/100")
C5			= $(shell bc <<< "255 - $(C1)")
CMP_TOTAL	= $(shell awk -F' ' '{printf NF}' <<< "$(S) $(S_BON)")
CMP_COUNT	= $(shell ls | grep -c '\.o')

CLEAR		= "\x1b\2K\r
GREEN		= \x1b[38;2;0;255;0m
L_GREEN		= \x1b[38;2;100;255;100m
WHITE		= \x1b[0m
CMP_OK		= has been successfully compiled!                                                    \n
CMP_DELETE	= has been successfully deleted!													 \n

RBW_P1		= \x1b[38;2;$(C4);255;$(C5)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                    
RBW_P2		= \x1b[38;2;255;$(C2);$(C1)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                    


all: $(NAME)

run: all
	@gcc -o $(NAME) srcs/main.c $(LIB) $(CFLAGS) $(G_FLG)
	./so_long

norminette:
	@printf $(CLEAR)$(L_GREEN)"
	@norminette $(S) headers/*.h libft/*.c

$(NAME): minilibx/libmlx42.a $(GOBJ) $(OBJ)
	@ar -rc $(LIB) $(OBJ)
	@ar -rc $(LIB) $(GOBJ)
	@gcc -o $(NAME) srcs/main.c $(LIB) $(CFLAGS) $(G_FLG)
	@printf "\n$(WHITE)> $(GREEN)$@ $(CMP_OK)$(WHITE)"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<
	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))
	@if [ $(CMP_COUNT) -gt $(shell expr $(CMP_TOTAL) / 2) ]; \
		then printf $(CLEAR)>$(RBW_P1)";\
		else printf $(CLEAR)>$(RBW_P2)";\
	fi

minilibx/libmlx42.a:
	@make -C minilibx

clean:
	@rm -rf $(GOBJ) $(OBJ) srcs/main.o
	@printf "> $(GREEN)all .o $(CMP_DELETE)$(WHITE)"

fclean: clean
	@rm -rf $(LIB) $(NAME)
	@printf "> $(GREEN)$(LIB)and $(NAME) $(CMP_DELETE)$(WHITE)"

re: fclean all

.PHONY: all bonus clean fclean re

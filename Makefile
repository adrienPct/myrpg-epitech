##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile of defender
##

D_SRC = 	./src/

D_INC = 	./include/

D_GLIB = 	./graphic_lib/

D_LIST = 	./listtool/

SRC =		$(D_SRC)core.c					\
			$(D_SRC)set_all.c				\
			$(D_SRC)set_menu.c				\
			$(D_SRC)draw_shop.c				\
			$(D_SRC)manage_pause.c			\
			$(D_SRC)set_shop.c				\
			$(D_SRC)draw_inventory.c		\
			$(D_SRC)manage_shop.c			\
			$(D_SRC)manage_inventory.c		\
			$(D_SRC)set_house.c				\
			$(D_SRC)set_quest.c				\
			$(D_SRC)cycle_day_night.c		\
			$(D_SRC)draw_menu.c				\
			$(D_SRC)how_many_slime.c		\
			$(D_SRC)set_player.c			\
			$(D_SRC)player_attack.c			\
			$(D_SRC)set_play.c				\
			$(D_SRC)manage_menu_bk.c		\
			$(D_SRC)scene_manager.c			\
			$(D_SRC)loop_window.c			\
			$(D_SRC)tools_bar.c				\
			$(D_SRC)create_col_map.c		\
			$(D_SRC)check_col64.c			\
			$(D_SRC)move_player.c			\
			$(D_SRC)manage_player.c			\
			$(D_SRC)anim_player.c			\
			$(D_SRC)set_inventory.c			\
			$(D_SRC)display.c				\
			$(D_SRC)draw_play.c				\
			$(D_SRC)manage_event.c			\
			$(D_SRC)manage_menu.c			\
			$(D_SRC)manage_house.c			\
			$(D_SRC)manage_rock.c			\
			$(D_SRC)manage_png_quest.c		\
			$(D_SRC)move_slime.c 			\
			$(D_SRC)campfire_gestion.c		\
			$(D_SRC)anim_slime.c 			\
			$(D_SRC)png_text_val.c 			\
			$(D_SRC)set_text.c				\
			$(D_SRC)deco.c					\
			$(D_GLIB)object_is_col_vector.c	\
			$(D_GLIB)set_obj.c				\
			$(D_GLIB)set_collider.c			\
			$(D_GLIB)on_collision.c			\
			$(D_SRC)my_itoa.c				\
			$(D_SRC)my_revstr.c				\
			$(D_SRC)set_env.c				\
			$(D_SRC)set_stat.c				\
			$(D_SRC)draw_stat.c				\
			$(D_SRC)manage_stat.c			\
			$(D_SRC)my_strcat.c				\
			$(D_GLIB)on_middle_collision.c	\
			$(D_GLIB)draw_obj.c				\
			$(D_GLIB)animation_buts.c		\
			$(D_LIST)connect_links.c		\
			$(D_LIST)create_link.c			\
			$(D_LIST)print_all_link.c		\
			$(D_SRC)cantgo.c				\
			$(D_SRC)show_current_quest.c	\
			$(D_LIST)print_link.c			\

OBJ = 		$(SRC:.c=.o)

CFLAGS += 	-w -Wall -Wextra -Include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I $(D_INC) -I $(D_GLIB) -lm

NAME =		my_rpg

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			rm -f $(OBJ)


fclean:		clean
			rm -f $(NAME)

re:			fclean all
/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #define CAN_MOVE game->play.player.can_move
    #define PLAYER game->play.player
    #define SLIMETAB game->play.slime.tab_link
    #define STARTLINK game->play.slime.act
    #define SLOT game->play.slot
    #define SCENE game->scene
    #define SCENEPATH game->scene_path
    #define SPAWN "sprite/spawn.png"
    #define FOREST "sprite/forest.png"
    #define VIEW game->view
    #define INVENTORY game->play.inventory
    #define HP game->play.life.hp
    #define SLIME_IN_LIFE game->play.nb_slime_in_life
    #define LVL game->play.player.lvl
    #define PAUSE game->pause

    #include "graphic_lib.h"

typedef struct link
{
    obj_t data;
    struct link *next;
    struct link *prev;
    int id;
} link_t;

typedef enum view {
    MENU,
    SPAWNV,
    FORESTV,
    HOME,
    OPTION
} view_e;

typedef enum slot {
    ONE,
    TWO,
    THREE,
    FOURTH,
    FIVE
} slot_e;

typedef enum items {
    IRONSWORD,
    SLIMEBALL,
    POTION
} items_e;

typedef enum direction {
    IDLE,
    UP,
    DOWN,
    RIGHT,
    LEFT
} direction_e;

typedef struct window {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
} win_t;

 typedef struct text {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f start_pos;
    sfColor color;
    int size;
} text_t;

typedef struct dial
{
    text_t quest_text;
    text_t second_quest_text;
    text_t third_quest_text;
    bool player_can_move;
    int i;
}dial_t;


typedef struct inventory
{
    obj_t tools_bar;
    obj_t *slots;
    obj_t inv_font;
    int obj_take;
    sfVector2f start_pos;
    sfVector2f *pos_slot;
    items_e *what_item;
    bool *is_empty;
    int act_tool;
    bool show_invent;
} inventory_t;

typedef struct {
    obj_t png;
    obj_t slimeball;
    obj_t potion;
    obj_t arrow;
    int price;
    obj_t bk;
    text_t talk;
    bool shop_open;
    bool can_open;
    text_t title;
    my_clock_t anim_p;
    obj_t button;
    text_t buy;
    text_t price_txt;
    obj_t quit;
} shop_t;

typedef struct map_collider {
    float x;
    float y;
    int width;
    int height;
} m_col_t;

typedef struct map_collision {
    char *buffer;
    m_col_t *colliders;
    int size;
} map_col_t;

typedef struct can_move {
    bool right;
    bool left;
    bool up;
    bool down;
} can_move_t;

typedef struct col_attack {
    float right;
    float left;
    float top;
    float bot;
} col_attack_t;

typedef struct {
    int lvl;
    obj_t xp_bar;
    int xp;
    text_t lvl_txt;
} lvl_t;

typedef struct player {
    obj_t obj;
    float speed;
    float walk_speed;
    float run_speed;
    bool *dir_tab;
    direction_e orientation;
    direction_e dir;
    direction_e last_dir;
    my_clock_t anim;
    lvl_t lvl;
    bool attack;
    bool attack_start;
    int idle_base;
    int walk_base;
    can_move_t can_move;
    bool stuck;
    col_attack_t col_attack;
    text_t txt_slime;
    obj_t slimeball;
    int nb_slimeball;
} player_t;

typedef struct slime
{
    obj_t *tab;
    my_clock_t clock_slime;
    int size;
    float speed;
    int life;
    link_t **tab_link;
    int act;
    float damage;
    bool death;
} slime_t;

typedef struct life
{
    int hp;
    obj_t hp_bar;
    obj_t hp_cont;
} life_t;

typedef struct statistics
{
    float strength;
    float speed;
    float life;
    int upgrade_point;
    obj_t stat;
    obj_t logo;
    text_t life_text;
    text_t strenght_text;
    text_t speed_text;
    text_t life_point;
    text_t strenght_point;
    text_t speed_point;
    text_t point_spend;
    text_t point_spend_var;
    obj_t plus_life;
    obj_t plus_strenght;
    obj_t plus_speed;
} statistics_t;

typedef struct play
{
    inventory_t inventory;
    player_t player;
    obj_t png;
    obj_t bubble_int;
    my_clock_t bubble_c;
    slime_t slime;
    map_col_t spawn_col;
    map_col_t forest_col;
    map_col_t act_map_col;
    bool *check;
    slot_e slot;
    life_t life;
    int nb_slime_in_life;
    obj_t house;
    obj_t rock;
    text_t pause;
    text_t text_cant_go;
    obj_t campfire;
    obj_t button_quit;
    obj_t button_resume;
    my_clock_t fire_clock;
} play_t;

typedef struct 
{
    my_clock_t cycle_clock;
    obj_t cycle_filter;
    bool is_day;
    int hours;
    bool is_am;
    text_t hours_txt;
    text_t hours_time;
    obj_t tree;
    obj_t apple_tree;
    my_clock_t clock;
    obj_t *flowers;
    int nb_flower;
} env_t;


typedef struct {
    obj_t bk;
    obj_t bt_play;
    my_clock_t bk_c;
    obj_t player;
    my_clock_t pl_c;
    obj_t campfire;
    obj_t quit;
    text_t title;
} menu_t;

typedef struct {
    sfMusic *spawn;
    sfMusic *house;
    sfMusic *forest;
    sfSound *take_damage;
    sfSoundBuffer *take_damage_buf;
    sfSound *button;
    sfSound *button_buf;
    sfSound *slurp;
    sfSoundBuffer *slurp_buf;
    sfSound *sword_hit;
    sfSoundBuffer *sword_hit_buf;
    sfSound *sword_slash;
    sfSoundBuffer *sword_slash_buf;
    sfSound *door;
    sfSoundBuffer *door_buf;
    sfSound *rock;
    sfSoundBuffer *rock_buf;
    sfSound *death;
    sfSoundBuffer *death_buf;
    sfSound *talk;
    sfSoundBuffer *talk_buf;
} sound_t;

typedef struct {
    obj_t build;
    map_col_t col_map;
    text_t text_png;
    obj_t box_text;
    obj_t arrow;
} house_t;

typedef struct {
    bool destroy;
    bool can_destroy;
    bool is_talking;
    bool in_mission;
    bool mission_finish_rock;
    bool mission_finish_slime;
    bool kill_slime;
    bool show_text;
    bool show_cant_go;
    bool first_time_talk;
    bool sec_time_talk;
    int nb_slime;
    bool xp_first_quest;
    bool xp_seconde_quest;
    text_t rock_text;
    text_t current_quest;
    text_t destroy_quest;
    text_t go_house;
    text_t slime_quest;
    text_t first_quest;
} quest_t;

typedef struct game {
    dial_t dial;
    view_e view;
    win_t win;
    statistics_t statis;
    my_clock_t fps;
    shop_t shop;
    sfVector2i pos_mouse;
    play_t play;
    menu_t menu;
    quest_t quest;
    char *scene_path;
    obj_t scene;
    house_t home;
    env_t env;
    bool pause;
    text_t game_over;
    sound_t sound;
    text_t comming_soon;
    bool show_comming;
} game_t;

void connect_links(link_t *link1, link_t *link2, int first);
link_t *create_link(obj_t *data, int id);
void print_link(link_t *link, game_t *game);
void print_all_link(link_t *link, game_t *game);

#endif /* !GAME_H_ */
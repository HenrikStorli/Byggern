/*
 * OLED_menu.h
 *
 * Created: 28.09.2020 12:24:15
 *  Author: Herbe
 */


#ifndef OLED_MENU_H_
#define OLED_MENU_H_

#include <avr/io.h>
#include <stdio.h>
#include "OLED.h"
#include "pos_read.h"

typedef enum{MAIN_MENU, PLAY_GAME, SCORE, SETTING, DIFFICULTY, DEBUGGINGN, END_MENU} MENU_ITEMS;

typedef struct Node_t{
    struct Node_t *Parent; //
    struct Node_t* children[8];
    int elements_on_screen;
    void (*functionPtr)(void); // //
    char name[20];
}Node;



/**
 * @brief Builds the menu node, and places it in the correct place.
 *
 * @param this_node Pointer to the node that you want to build.
 * @param father_node Pointer to the parent node.
 * @param node_name Array of caracthers containing name of the node.
 * @param do_function Pointer to function node should do.
 * @param children_nodes The node's children.
 * @param elements_on_screen Number of elements that the current node is showing on screen
 */
void build_node(Node *this_node, Node* father_node, char node_name[], void (*do_function)(void), Node* children_nodes[8], int elements_on_screen);

/**
 * @brief Changes the current pointer to point to the parent node.
 *
 * @param this_node Pointer to a pointer that points to a node.
 */
void go_up(Node **this_node);

/**
 * @brief Chenges this_node so it points to one of its childs.
 *
 * @param this_node Pointer to a pointer that points to a node.
 * @param child The index for the child that should be pointed to.
 */
void go_down(Node **this_node, int child);

/**
 * @brief Waits until the user does something withthe joystick.
 *
 * @return Direction of the joystick [LEFT, RIGHT, UP, DOWN, NEUTRAL, BUTTON_PRESS].
 */
DIRECTION wait_for_action(void);

/**
 * @brief Waits until the joystick is in neutral position.
 */
void wait_for_neutral_joystick_position();

/**
 * @brief Updates the screen according to the given node.
 *
 * @param current_node A pointer to the current node.
 * @param child Index for the current nodes child.
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */
void update_screen(Node *current_node, int child);

/**
 * @brief Updates the index for element when joystick is moved up.
 *
 * @param current_node Pointer to the current_node.
 * @param child index for the child.
 *
 * @return The new index for the child.
 */
int update_element_up(Node *current_node, int child);

/**
 * @brief Updates the index for element when joystick is moved down.
 *
 * @param current_node Pointer to the current_node.
 * @param child index for the child.
 *
 * @return The new index for the child.
 */
int update_element_down(Node *current_node, int child);

/**
 * @brief Runs the menu.
 */
void menu();

/**
 * @brief Prints the objects of main menu node.
 *
 * @param child index for the child.
 */
void print_main_menu_objects(int child);

/**
 * @brief Prints the objects of new game menu.
 *
 * @param child index for the child.
 */
void print_new_game_menu_objects(int child);

/**
 * @brief Prints the objects of score menu.
 *
 * @param child index for the child.
 */
void print_score_menu_objects(int child);

/**
 * @brief Prints arrow showing wich element is selected.
 *
 * @param child index for the child.
 */
void print_selecting_arrow(int child);

/**
 * @brief Runs the ping-pong game.
 */
void play_game();

void show_score();



// https://www.codeproject.com/Articles/794047/Finite-State-Menu

#endif /* OLED_MENU_H_ */

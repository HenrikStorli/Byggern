/*
 * OLED_menu.c
 *
 * Created: 28.09.2020 12:23:55
 *  Author: Herbe
 */

#include "OLED_menu.h"

int _1ST, _2ND, _3RD = 0;

int child = 1; //Barnet som man "howrer" over på skjermen. Default er øverste barnet.

void build_node(Node *this_node, Node* father_node, char node_name[], void (*do_function)(void), Node *children_nodes[8], int elements_on_screen){
    this_node->Parent = father_node;
    strcpy(this_node->name, node_name);
    this_node->functionPtr = do_function;
    this_node->elements_on_screen = elements_on_screen;

    for(int i = 0; i < 8; i++){
        (this_node->children)[i] = children_nodes[i];
    }
}

void go_up(Node **this_node){
  if((*this_node)->Parent != 0){
    (*this_node) = (*this_node)->Parent;
    //printf("LEFT");
  }
}

void go_down(Node **this_node, int child){

    if(((*this_node)->children)[child - 1] != 0){
        (*this_node) = ((*this_node)->children)[child - 1];
        //printf("Bytte node\t\n");
    }
    else if((*this_node)->functionPtr != 0){
        (*this_node)->functionPtr();
        //printf("KJØR FUNSKJONSPEKER\t\n");
    }else{
       // printf("Do nothing\t\n");
    }
}

DIRECTION wait_for_action(void){

    //printf("Inn i wait for action\n");

    while(joystick_direction() == NEUTRAL && !usb_button_pushed(JOYSTICK_BUTTON));

    if(joystick_direction() == UP){
        //printf("UPUPUPUP\n");
        return UP;
    }
    else if(joystick_direction() == DOWN){
        return DOWN;
    }
    else if(joystick_direction() == RIGHT){
        return RIGHT;
    }
    else if(joystick_direction() == LEFT){
        return LEFT;
    }
    else if(usb_button_pushed(JOYSTICK_BUTTON)){
        return BUTTON_PRESS;
    }
}
void wait_for_neutral_joystick_position(){
    while(joystick_direction() != NEUTRAL);
}

void update_screen(Node *current_node, int child){

    if(((*current_node).name[1]) == 'a'){
        //printf("Update  MAIN_MENU screen\t\n");
        print_main_menu_objects(child);
        //Skal oppdatere skjermen som passer til main-menu. I tillegg skal pilen howre over riktg barn.
    }
    else if(((*current_node).name[1]) == 'l'){
       // printf("Update PLAY menu\t\n");
        print_new_game_menu_objects(child);
    }
    else if(((*current_node).name[1]) == 'h'){
        print_score_menu_objects(child);
    }
	else if(((*current_node).name[1]) == 'i'){
		print_difficulty_menu_objects(child);
	}

}

int update_element_up(Node *current_node, int child){

    child--;

    if(child == 0){
        child = current_node->elements_on_screen;
    }

    return child;
}

int update_element_down(Node *current_node, int child){

    child++;

    if(child == current_node->elements_on_screen + 1){
        child = 1;
    }

    return child;
    
}
//Node Main_menu, Score, Play, Settings, Difficulty, Debugging, *current_node;

void menu(){

    static Node Main_menu, Score, Play, Difficulty, Easy, Medium, Hard, *current_node;

    current_node = &Main_menu; //Startnoden
    DIRECTION action; //Handling som er gjort på Joysticken

    //Bygger nodestrukturen
    Node* children1[8] = {&Play, &Score, &Difficulty ,0 ,0 ,0 ,0 ,0};
    Node* children2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    Node* children3[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	Node* children4[8] = {&Easy, &Medium, &Hard, 0, 0, 0, 0, 0};
		
		



    build_node(&Main_menu, NULL, "Main menu", NULL, &children1,3);
    build_node(&Play, &Main_menu, "Play game", play_game, &children2,1);
    build_node(&Score, &Main_menu, "Show score", NULL, &children3,8);
	build_node(&Difficulty, &Main_menu, "Difficulty", set_difficulty, &children2, 3);
	//build_node(&Difficulty, &Main_menu, "Difficulty", NULL, &children4, 3);
	//build_node(&Easy, &Difficulty, "Easy", set_difficulty_easy, &children2, 0);
	//build_node(&Medium, &Difficulty, "Easy", set_difficulty_medium, &children2, 0);
	//build_node(&Hard, &Difficulty, "Easy", set_difficulty_hard, &children2, 0);
	

    update_screen(current_node, child);

    while(1){
        action = wait_for_action();  //Wait for user to move the joystick
        oled_clear();  //Clears the screen.

        switch(action)
        {
          case BUTTON_PRESS:
              break;
          case UP:
                //update_screen(current_node, child);
                child = update_element_up(current_node, child);
              break;
          case DOWN:
                child = update_element_down(current_node, child);
              break;
          case LEFT:
                go_up(&current_node);
                child = 1;
              break;
          case RIGHT:
                go_down(&current_node, child);
                child = 1;
              break;
          default:
              break;
        }

        //printf("After switch\t\n");
        //printf("Nodenavn %c \t\n",((*current_node).name[0]));
        update_screen(current_node, child);
        wait_for_neutral_joystick_position();
    }
}


void print_main_menu_objects(int child){
    char line1[] = "play";
    char line2[] = "Score";
	char line3[] = "Difficulty";

    oled_pos_set(0, 12);
    oled_print(&line1);

    oled_pos_set(1, 12);
    oled_print(&line2);
	
	oled_pos_set(2, 12);
	oled_print(&line3);
	
	

    print_selecting_arrow(child);       //Draw the arrow that selects the preferable option.
    
}

void print_new_game_menu_objects(int child){

    char line1[] = "Start game";

    oled_pos_set(0, 12);
    oled_print(&line1);

    print_selecting_arrow(child);
}

void check_highscore(int highscore){
    if(highscore >= _1ST){   //check if new highscore
		_3RD = _2ND;
		_2ND = _1ST;
        _1ST = highscore;
		
    }
    else if(    (highscore < _1ST) && (highscore > _2ND)    )    {  //check if new second best
		_3RD = _2ND;
        _2ND = highscore;
    }
    else if(    (highscore < _2ND) && (highscore > _3RD)    ){ //check if new third best
        _3RD = highscore;
    }
    
}

void print_score_menu_objects(int child){

char line1[] = "Top score";
    
char score_string1[15], score_string2[15], score_string3[15];

itoa(_1ST, score_string1, 10);
itoa(_2ND, score_string2, 10);
itoa(_3RD, score_string3, 10);    

    
    oled_pos_set(0, 12);
    oled_print(&line1);

    oled_pos_set(2, 12);
    oled_print("1ST  ");
    oled_print(&score_string1);
    
    oled_pos_set(4, 12);
    oled_print("2ND  ");
    oled_print(&score_string2);

    oled_pos_set(6, 12);
    oled_print("3RD  ");
    oled_print(&score_string3);
    
    print_selecting_arrow(child);

}

void print_difficulty_menu_objects(int child){
	char line1[] = "Easy";
	char line2[] = "Medium";
	char line3[] = "Hard";

	oled_pos_set(0, 12);
	oled_print(&line1);

	oled_pos_set(1, 12);
	oled_print(&line2);
	
	oled_pos_set(2, 12);
	oled_print(&line3);
	
	print_selecting_arrow(child);       //Draw the arrow that selects the preferable option.
	
}


void print_selecting_arrow(int child){
    oled_print_arrow(child - 1, 5);
	
}


void play_game(){
	
	message_handler();
	message_handler();
	
	CAN_message_t game_status;
	game_status.data[0] = 0;
	uint8_t game_on = 1;
	
	CAN_message_t start_game;
	start_game.identifier = 9;
	start_game.data[0] = 7;
	start_game.data_length = 1;
	
	CAN_message_transmission(&start_game);
		
		
	while(game_on){
		joyStick_Can_Message();
		
		game_status = message_handler();
		
		if(game_status.data[0] == 0b10101011){
			game_on = 0;
			
			printf("GameStatusData: %d", game_status.data[0]);
		}
	}
	int highscore = game_status.data[1];
	
	//printf("Highscore is: %d", highscore);
	
	check_highscore(highscore);
	
}

void set_difficulty(){
	CAN_message_t difficulty_message;
	difficulty_message.identifier = 5;
	difficulty_message.data_length = 1;
	
	if(child == 1){
		difficulty_message.data[0] = 1;
		printf("EASY");
	}
	else if(child == 2){
		difficulty_message.data[0] = 2;
		printf("Medium");
	}
	else if(child == 3){
		difficulty_message.data[0] = 3;
		printf("Hard");	
	}
	CAN_message_transmission(&difficulty_message);
}

//void show_score(){
//   char score = oled_convert2ASCII(1111);
////   oled_clear();
// //  oled_print(score);
//}

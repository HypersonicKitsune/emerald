#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "./common.h"
#include "./macros.h"
#include "./geoitems.h"

ALLEGRO_DISPLAY *display = NULL;


int main()
{
	init_allegro();
	display = al_create_display(SCREEN_W, SCREEN_H);
	
	Point pl;
	pl = set_point_coordinates(200, 200);
	
	Vector vec;
	vec = set_vec_coordinates(64, 64);
	
    al_clear_to_color(GRAY);
    al_draw_filled_rectangle(pl.x, pl.y, pl.x+32, pl.y+32, BLUE);
    al_flip_display();
    
    al_rest(1);
    
    point_translation(&pl, vec);
    
    al_clear_to_color(GRAY);
    al_draw_filled_rectangle(pl.x, pl.y, pl.x+32, pl.y+32, BLUE);
    al_flip_display();
	
	al_rest(5);
	
	al_destroy_display(display);
	
	return EXIT_SUCCESS;
}

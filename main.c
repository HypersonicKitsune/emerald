/***
 * Current experiment based on the engine: an mobile square
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "./common.h"
#include "./macros.h"
#include "./geoitems.h"

// allegro's stuff
ALLEGRO_DISPLAY     *display  = NULL;
ALLEGRO_EVENT_QUEUE *ev_queue = NULL;
ALLEGRO_TIMER       *timer    = NULL;

Point pl; // player's position
Vector vec; // current player's translation vector
bool mainloop = true;
bool redraw   = true;

enum{KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_LEFT, KEY_MAX};
bool key[KEY_MAX] = {0};


int main()
{
	init_allegro();
	display = al_create_display(SCREEN_W, SCREEN_H);

	al_install_keyboard();
    ev_queue = al_create_event_queue();
    timer = al_create_timer(1.0/25);
    
    al_register_event_source(ev_queue, al_get_display_event_source(display));
    al_register_event_source(ev_queue, al_get_keyboard_event_source());
    al_register_event_source(ev_queue, al_get_timer_event_source(timer));
    
    al_start_timer(timer);
    
	pl = set_point_coordinates(SCREEN_W/2, SCREEN_H/2);
	vec = set_vec_coordinates(0, 0);
	
	// vec
	float i = 0.0;
	
	while(mainloop)
    {
        // events
        ALLEGRO_EVENT ev;
        al_wait_for_event(ev_queue, &ev);
        
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            mainloop = false;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = true;
                    break;
                case ALLEGRO_KEY_LEFT:
                    key[KEY_LEFT] = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = true;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    mainloop = false;
                    break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = false;
                    break;
                case ALLEGRO_KEY_LEFT:
                    key[KEY_LEFT] = false;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = false;
                    break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
			if(key[KEY_UP])
				vec = set_vec_pol_coordinates(10, -PI/2);
			else if(key[KEY_DOWN])
				vec = set_vec_pol_coordinates(10, PI/2);
            else if(key[KEY_LEFT])
				vec = set_vec_pol_coordinates(10, PI);
            else if(key[KEY_RIGHT])
				vec = set_vec_pol_coordinates(10, PI*2);
			else
				vec = set_vec_coordinates(0, 0);
            
            point_translation(&pl, vec);

            redraw = true;
        }
        
        // graphics update
        if(redraw && al_is_event_queue_empty(ev_queue))
        {
			al_clear_to_color(GRAY);
			al_draw_filled_rectangle(pl.x, pl.y, pl.x+32, pl.y+32, BLUE);
			al_flip_display();
            
            redraw = false;
        }
	}
	
	al_destroy_timer(timer);
	al_destroy_event_queue(ev_queue);
	al_destroy_display(display);
	
	return EXIT_SUCCESS;
}

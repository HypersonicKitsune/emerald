/***
 * Current experiment based on the engine: an animated square
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
        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            vec = set_vec_pol_coordinates(10, i+=0.1);
            
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
    
    /**al_clear_to_color(GRAY);
     * 
    al_draw_filled_rectangle(pl.x, pl.y, pl.x+32, pl.y+32, BLUE);
    al_flip_display();
    
    al_rest(1);
    
    point_translation(&pl, vec);
    
    al_clear_to_color(GRAY);
    al_draw_filled_rectangle(pl.x, pl.y, pl.x+32, pl.y+32, BLUE);
    al_flip_display();
	
	al_rest(5);
	
	al_destroy_display(display);**/
	
	al_destroy_timer(timer);
	al_destroy_event_queue(ev_queue);
	al_destroy_display(display);
	
	return EXIT_SUCCESS;
}

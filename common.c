#include <stdlib.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

#include "./common.h"

/* Engine setup */

void init_allegro()
{
	dbg("Initialize Allegro... ");
	
	if(!al_init())
		error("Could not initialize Allegro");
	if(!al_init_primitives_addon())
		error("Could not initialize Allegro - primitives addon");
	if(!al_init_image_addon())
		error("Could not initialize Allegro - image addon");
	if(!al_install_keyboard())
		error("Keyboard not found");
	
	dbg("Done!\n");
}


/* User/debugging notifications */

void error(const char *msg)
{
    ALLEGRO_DISPLAY *d;
    d = al_is_system_installed() ? al_get_current_display() : NULL;
    fprintf(stderr, "[FATAL ERROR] %s - Aborting.\n", msg);
    al_show_native_message_box(d, "FATAL ERROR!", "Fatal error occured, aborting. Sorry.",
                               msg, NULL, ALLEGRO_MESSAGEBOX_ERROR);
    al_destroy_display(d);
    exit(EXIT_FAILURE);
}

void warning(const char *header, const char *msg)
{
    ALLEGRO_DISPLAY *d;
    d = al_is_system_installed() ? al_get_current_display() : NULL;
    printf("[WARNING] %s\n", msg);
    al_show_native_message_box(d, "Warning", header, msg, NULL, 0);
    al_destroy_display(d);
}

void dbg(const char *msg)
{
	printf(msg);
}

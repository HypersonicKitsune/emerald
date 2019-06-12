#include <stdlib.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

#include "./macros.h"
#include "./common.h"


static FILE *logfile = NULL;


/* Engine setup */

void init_allegro()
{
	logfile_init();
	
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


void release_all()
{
	logfile_close();
}


/* Logfile */

void logfile_init()
{
	if(NULL != (logfile = fopen(LOGFILE_PATH, "w")))
	{
		logfile_message("%s version %s", GAME_NAME, GAME_VERSION);
	}
	else
		warning("logfile_init()", "Logfile could not be initialized");
}


void logfile_message(const char *msg, ...)
{
	if(logfile != NULL)
	{
		fprintf(logfile, msg);
		fputc('\n', logfile);
	}
}


void logfile_close()
{
	logfile_message("Closing logfile");
	if(logfile != NULL)
	{
		fclose(logfile);
	}
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

void dbg(const char *msg, ...)
{
	printf(msg);
	logfile_message(msg);
}

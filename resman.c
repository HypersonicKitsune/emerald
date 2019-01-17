/*********************
 *
 * resman - A RESource MANager
 * Copyright (C) 2019 HypersonicKitsune <hypersonic.kitsune@gmail.com>
 *
 *********************
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 *********************/


#include <stdlib.h>

#include <allegro5/allegro.h>

#include "./resman.h"



/*** SETUP ***/

#define HASHTABLE_TABLESIZE 97



/*** HASHTABLE-RELATED FUNCTIONS ***/

// TODO : creer une macro capable de generer des hashtables par type.
// TODO 2 : peut-etre deplacer toutes ces fonctions dans un fichier a part ?


/*
 * int hashfunc(const char *str)
 * 
 * A hash function, for hashtable key generation.
 * Has to be improved later !
 */
int hashfunc(const char *str)
{
    int i = 0, hash = 0;

	hash += 2 * str[0];
	hash += 4 * str[1];
    for (i = 0 ; str[i] != '\0' ; i++)
        hash += str[i];
	
    hash %= HASHTABLE_TABLESIZE;

    return hash;
}



/*** ALLEGRO_BITMAP HASHTABLE ***/


/*
 * ALLEGRO_BITMAP *bitmap_hashtable_create()
 * 
 * Returns an empty ALLEGRO_BITMAP array of pointers
 * which will be used as a hashtable.
 */
ALLEGRO_BITMAP *bitmap_hashtable_create()
{
	// /!\ DO NOT USE THIS FUNCTION; it doesn't work
	ALLEGRO_BITMAP *ht[HASHTABLE_TABLESIZE];

	for(int i = 0; i < HASHTABLE_TABLESIZE; i++)
		ht[i] = NULL;
	
	return ht;
}


/*
 * void bitmap_hashtable_empty(ALLEGRO_BITMAP *ht[])
 * 
 * Empties the ALLEGRO_BITMAP hashtable 'ht'.
 */
void bitmap_hashtable_empty(ALLEGRO_BITMAP *ht[])
{
	for(int i = 0; i < HASHTABLE_TABLESIZE; i++)
	{
		if(ht[i] != NULL)
		{
			al_destroy_bitmap(ht[i]);
			ht[i] = NULL;
		}
	}
}


/*
 * void bitmap_hashtable_add(ALLEGRO_BITMAP *ht[], ALLEGRO_BITMAP *bmp, const char *key)
 * 
 * Adds 'bmp' to ALLEGRO_BITMAP hashtable 'ht'.
 */
void bitmap_hashtable_add(ALLEGRO_BITMAP *ht[], ALLEGRO_BITMAP *bmp, const char *key)
{
	// TODO : check for any collision
	ht[hashfunc(key)] = bmp;
}


/*
 * ALLEGRO_BITMAP *bitmap_hashtable_get(ALLEGRO_BITMAP *ht[], const char *key)
 * 
 * Returns the element corresponding to its key in ALLEGRO_BITMAP hashtable 'ht'.
 */
ALLEGRO_BITMAP *bitmap_hashtable_get(ALLEGRO_BITMAP *ht[], const char *key)
{
	// TODO : check if this isn't NULL
	return ht[hashfunc(key)];
}


/*
 * void bitmap_hashtable_remove(ALLEGRO_BITMAP *ht[], const char *key)
 * 
 * Removes the element corresponding to its key in ALLEGRO_BITMAP hashtable 'ht'.
 */
void bitmap_hashtable_remove(ALLEGRO_BITMAP *ht[], const char *key)
{
	int index = hashfunc(key);
	
	al_destroy_bitmap(ht[index]);
	ht[index] = NULL;
}


/* int bitmap_hashtable_count(ALLEGRO_BITMAP *ht[])
 * 
 * Returns the number of used slots in ALLEGRO_BITMAP hashtable 'ht'.
 */
int bitmap_hashtable_count(ALLEGRO_BITMAP *ht[])
{
	int mem_used = 0;
	
	for(int i = 0; i < HASHTABLE_TABLESIZE; i++)
	{
		if(ht[i] != NULL)
			mem_used++;
	}
	
	return mem_used;
}

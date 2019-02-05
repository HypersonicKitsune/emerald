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

#include "./common.h"
#include "./resman.h"



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
 * HASHTABLE_BMP bitmap_hashtable_create()
 * 
 * Returns an empty ALLEGRO_BITMAP array of pointers
 * which will be used as a hashtable.
 */
HASHTABLE_BMP bitmap_hashtable_create()
{
	HASHTABLE_BMP ht = {NULL};

	for(int i = 0; i < HASHTABLE_TABLESIZE; i++)
		ht.h[i] = NULL;
	
	return ht;
}


/*
 * void bitmap_hashtable_empty(HASHTABLE_BMP ht[])
 * 
 * Empties the ALLEGRO_BITMAP hashtable 'ht'.
 */
void bitmap_hashtable_empty(HASHTABLE_BMP *ht)
{
	for(int i = 0; i < HASHTABLE_TABLESIZE; i++)
	{
		if(ht->h[i] != NULL)
		{
			al_destroy_bitmap(ht->h[i]);
			ht->h[i] = NULL;
		}
	}
}


/*
 * void bitmap_hashtable_add(HASHTABLE_BMP ht[], ALLEGRO_BITMAP *bmp, const char *key)
 * 
 * Adds 'bmp' to ALLEGRO_BITMAP hashtable 'ht'.
 */
void bitmap_hashtable_add(HASHTABLE_BMP *ht, ALLEGRO_BITMAP *bmp, const char *key)
{
	if(ht->h[hashfunc(key)] == NULL)
		ht->h[hashfunc(key)] = bmp;
	else
		warning("Collision! Wrong key in hashtable", key);
}


/*
 * ALLEGRO_BITMAP *bitmap_hashtable_get(ALLEGRO_BITMAP *ht[], const char *key)
 * 
 * Returns the element corresponding to its key in ALLEGRO_BITMAP hashtable 'ht'.
 */
ALLEGRO_BITMAP *bitmap_hashtable_get(HASHTABLE_BMP *ht, const char *key)
{
	ALLEGRO_BITMAP *bmp = ht->h[hashfunc(key)];
	if(bmp != NULL)
		return bmp;
	else
	{
		warning("Invalid key - no element exist", key);
		return NULL;
	}
}


/*
 * void bitmap_hashtable_remove(HASHTABLE_BMP ht[], const char *key)
 * 
 * Removes the element corresponding to its key in ALLEGRO_BITMAP hashtable 'ht'.
 */
void bitmap_hashtable_remove(HASHTABLE_BMP *ht, const char *key)
{
	int index = hashfunc(key);
	
	al_destroy_bitmap(ht->h[index]);
	ht->h[index] = NULL;
}


/* int bitmap_hashtable_count(ALLEGRO_BITMAP *ht[])
 * 
 * Returns the number of used slots in ALLEGRO_BITMAP hashtable 'ht'.
 */
int bitmap_hashtable_count(HASHTABLE_BMP *ht)
{
	int mem_used = 0;
	
	for(int i = 0; i < HASHTABLE_TABLESIZE; i++)
	{
		if(ht->h[i] != NULL)
			mem_used++;
	}
	
	return mem_used;
}

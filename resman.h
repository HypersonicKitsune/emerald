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

#ifndef RESMAN_H
#define RESMAN_H



/*** SETUP ***/

#define HASHTABLE_TABLESIZE 97



/*** HASHTABLES STRUCTURES ***/

typedef struct HASHTABLE_BMP HASHTABLE_BMP;
struct HASHTABLE_BMP
{
	ALLEGRO_BITMAP *h[HASHTABLE_TABLESIZE];
};



/*** HASHTABLE-RELATED FUNCTIONS ***/

int hashfunc(const char *str);



/*** ALLEGRO_BITMAP HASHTABLE ***/

HASHTABLE_BMP bitmap_hashtable_create();
void bitmap_hashtable_empty(HASHTABLE_BMP *ht);
void bitmap_hashtable_add(HASHTABLE_BMP *ht, ALLEGRO_BITMAP *bmp, const char *key);
ALLEGRO_BITMAP *bitmap_hashtable_get(HASHTABLE_BMP *ht, const char *key);
void bitmap_hashtable_remove(HASHTABLE_BMP *ht, const char *key);
int bitmap_hashtable_count(HASHTABLE_BMP *ht);


#endif // RESMAN_H

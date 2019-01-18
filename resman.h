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


/*** HASHTABLE-RELATED FUNCTIONS ***/

int hashfunc(const char *str);


/*** ALLEGRO_BITMAP HASHTABLE ***/

// ALLEGRO_BITMAP *bitmap_hashtable_create();
void bitmap_hashtable_empty(ALLEGRO_BITMAP *ht[]);
void bitmap_hashtable_add(ALLEGRO_BITMAP *ht[], ALLEGRO_BITMAP *bmp, const char *key);
ALLEGRO_BITMAP *bitmap_hashtable_get(ALLEGRO_BITMAP *ht[], const char *key);
void bitmap_hashtable_remove(ALLEGRO_BITMAP *ht[], const char *key);
int bitmap_hashtable_count(ALLEGRO_BITMAP *ht[]);


#endif // RESMAN_H

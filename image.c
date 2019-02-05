/*********************
 *
 * image - Imagery module
 * Copyright (C) 2019 HypersonicKitsune <hypersonic.kitsune@gmail.com>
 * This file is a part of EmeraldEngine.
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
#include <allegro5/allegro_image.h>

#include "./geoitems.h"
#include "./resman.h"
#include "./image.h"


/*
 * void image_load(HASHTABLE_BMP ht[], const char *path)
 * 
 * Loads an image file and puts it into ALLEGRO_BITMAP hashtable 'ht'.
 */
void image_load(HASHTABLE_BMP ht[], const char *path)
{
	bitmap_hashtable_add(ht, al_load_bitmap(path), path);
}


/*
 * void image_mask(HASHTABLE_BMP ht[], const char *key, ALLEGRO_COLOR col)
 * 
 * Makes pixels with 'col' transparent.
 */
void image_mask(HASHTABLE_BMP ht[], const char *key, ALLEGRO_COLOR col)
{
	al_convert_mask_to_alpha(bitmap_hashtable_get(ht, key), col);
}


/*
 * void image_draw(HASHTABLE_BMP ht[], const char *key, Vector coords)
 * 
 * Draws an image on the screen
 */
void image_draw(HASHTABLE_BMP ht[], const char *key, Vector coords, int flags)
{
	al_draw_bitmap(bitmap_hashtable_get(ht, key), coords.x, coords.y, flags);
}

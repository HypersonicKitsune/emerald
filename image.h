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
 
 
 #ifndef IMAGE_H
 #define IMAGE_H
 
void image_load(HASHTABLE_BMP ht[], const char *path);
void image_mask(HASHTABLE_BMP ht[], const char *key, ALLEGRO_COLOR col);
void image_draw(HASHTABLE_BMP ht[], const char *key, Vector coords, int flags);
void image_get_region(HASHTABLE_BMP ht[], const char *key, const char *new, int x, int y, int w, int h);
 
 #endif // IMAGE_H

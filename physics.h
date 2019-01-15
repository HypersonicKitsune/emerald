/*********************
 *
 * physics - Collisions & Physics-related routines
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


#ifndef PHYSICS_H
#define PHYSICS_H


/*** HITBOX STRUCTURE ***/


/* Represents a box used for collision calculations */
typedef struct Hitbox Hitbox;
struct Hitbox
{
	int x;
	int y;
	int w;
	int h;
};


/*** FUNCTIONS PROTOTYPES ***/

void set_hb(Hitbox *hb, int x, int y, int w, int h);
void set_hb_point(Hitbox *hb, Point pt);
void set_hb_point_centered(Hitbox *hb, Point pt);


#endif PHYSICS_H

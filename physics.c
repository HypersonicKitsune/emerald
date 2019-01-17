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


#include <stdlib.h>
#include <stdbool.h>

#include "./geoitems.h"
#include "./physics.h"


void set_hb(Hitbox *hb, int x, int y, int w, int h)
{
	hb->x = x;
	hb->y = y;
	hb->w = w;
	hb->h = h;
}


void set_hb_point(Hitbox *hb, Vector pos)
{
	hb->x = pos.x;
	hb->y = pos.y;
}


void set_hb_point_centered(Hitbox *hb, Vector pos)
{
	hb->x = pos.x + hb->w/2;
	hb->y = pos.y - hb->h/2;
}


bool collision(Hitbox a, Hitbox b)
{
	if(a.x < b.x + b.w &&
	   a.x + a.w > b.x &&
	   a.y < b.y + b.h &&
	   a.h + a.y > b.y)
		return true;
	else
		return false;
}

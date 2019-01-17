/*********************
 *
 * geoitems - Geometrical Items, such as points or vectors.
 * Copyright (C) 2018 HypersonicKitsune <hypersonic.kitsune@gmail.com>
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

#ifndef GEOITEMS_H
#define GEOITEMS_H


/* Vector structure */

typedef struct Vector Vector;
struct Vector
{
	int x;
	int y;
};


/* Vector functions */

Vector set_vec_coordinates(int x, int y);
Vector set_twopoints(Point a, Point b);
Vector set_vec_pol_coordinates(int length, float angle);
float vec_length(Vector vec);
float vec_angle(Vector vec);
float dot_product(Vector a, Vector b);

#endif // GEOITEMS_H

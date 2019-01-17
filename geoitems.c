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


#include <math.h>

#include "./geoitems.h"


/* Vector functions */


/*
 * Vector set_vec_coordinates(int x, int y)
 *
 * Sets cartesian coordinates of a Vector
 */
Vector set_vec_coordinates(int x, int y)
{
	Vector vec;
	vec.x = x;
	vec.y = y;
	return vec;
}

/*
 * Vector set_twopoints(Point a, Point b)
 * 
 * Set Vector's coordinates as the a, b vector
 */
Vector set_twopoints(Point a, Point b)
{
	Vector vec;
	vec.x = b.x - a.x;
	vec.y = b.y - a.y;
	return vec;
}

/*
 * Vector set_vec_pol_coordinates(int length, float angle)
 * 
 * Sets polar coordinates of a Vector (angle in radians)
 */
Vector set_vec_pol_coordinates(int length, float angle)
{
	Vector vec;
	vec.x = length * cos(angle);
	vec.y = length * sin(angle);
	return vec;
}

/*
 * float vec_length(Vector vec)
 * 
 * Returns the length (norm) of a Vector.
 */
float vec_length(Vector vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

/*
 * float vec_angle(Vector vec)
 * 
 * Returns the angle of a Vector (in radians).
 */
float vec_angle(Vector vec)
{
	return atan2(vec.y, vec.x);
}

/*
 * float dot_product(Vector a, Vector b)
 * 
 * Returns the dot product a.b
 */
float dot_product(Vector a, Vector b)
{
	return (a.x + a.y)*(b.x + b.y);
}

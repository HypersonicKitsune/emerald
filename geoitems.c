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



/*** VECTOR FUNCTIONS ***/



/* Vector modification operations */


/*
 * Vector set_vec_coordinates(int x, int y)
 *
 * Sets cartesian coordinates of a Vector
 */
Vector set_vec_coordinates(int x, int y)
{
	Vector u;
	u.x = x;
	u.y = y;
	return u;
}


/*
 * Vector set_twopoints(int x1, int y1, int x2, int y2)
 * 
 * Set Vector's coordinates as the a, b vector
 */
Vector set_twopoints(int x1, int y1, int x2, int y2)
{
	Vector u;
	u.x = x2 - x1;
	u.y = y2 - y1;
	return u;
}


/*
 * Vector set_vec_pol_coordinates(int length, float angle)
 * 
 * Sets polar coordinates of a Vector (angle in radians)
 */
Vector set_vec_pol_coordinates(int length, float angle)
{
	Vector w;
	w.x = length * cos(angle);
	w.y = length * sin(angle);
	return w;
}


/*
 * Vector vec_add(Vector u, Vector v)
 * 
 * Adds two vectors
 */
Vector vec_add(Vector u, Vector v)
{
	Vector w;
	w.x = u.x + v.x;
	w.y = u.y + v.y;
	return w;
}


/*
 * Vector vec_substract(Vector u, Vector v)
 * 
 * Subtracts two vectors
 */
Vector vec_substract(Vector u, Vector v)
{
	Vector w;
	w.x = u.x - v.x;
	w.y = u.y - v.y;
	return w;
}


/*
 * Vector vec_multiply(Vector u, int k)
 * 
 * Returns a copy of vector u multiplied by k.
 */
Vector vec_multiply(Vector u, int k)
{
	Vector w;
	w.x = u.x * k;
	w.y = u.y * k;
	return w;
}


/*
 * Vector vec_rotate(Vector u, float angle)
 * 
 * Rotates a vector. Angle in radians.
 */
Vector vec_rotate(Vector u, float angle)
{
	Vector v;
	v.x = u.x * cos(angle) - u.y * sin(angle);
	v.y = u.x * sin(angle) + u.y * cos(angle);
	return v;
}


/* Vector values */


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

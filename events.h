/*********************
 *
 * events - Event-related routines
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


/*** KEY CODES ***/

enum{KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_LEFT, KEY_ESCAPE, KEY_MAX};

// directional
#define K_UP     1
#define K_DOWN   2
#define K_RIGHT  3
#define K_LEFT   4

// action
#define K_SPACE  5
#define K_ESCAPE 0


void read_controls(bool key[], ALLEGRO_EVENT ev);

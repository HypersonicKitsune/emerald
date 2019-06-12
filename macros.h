/*********************
 *
 * macros - Useful macros for the whole program
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
 
#ifndef MACROS_H
#define MACROS_H


/*** GENERAL PURPOSE ***/

#define GAME_NAME "Emerald Engine"
#define GAME_VERSION "0.0"

#define LOGFILE_PATH "./log.txt" // default logfile path

/*** MATHEMATICS ***/

#define PI 3.1415927


/*** GRAPHICS MACROS ***/

// screen dimensions
#define SCREEN_W 640
#define SCREEN_H 480

// basic colors
#define RED al_map_rgb(255, 0, 0)
#define GREEN al_map_rgb(0, 255, 0)
#define BLUE al_map_rgb(0, 0, 255)
#define YELLOW al_map_rgb(255, 255, 0)
#define CYAN al_map_rgb(0, 255, 255)
#define MAGENTA al_map_rgb(255, 0, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define GRAY al_map_rgb(128, 128, 128)
#define WHITE al_map_rgb(255, 255, 255)


#endif // MACROS_H
// OwO what's this?

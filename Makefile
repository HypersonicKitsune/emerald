#####################
#
# Makefile - compilation script
# Copyright (C) 2019 HypersonicKitsune <hypersonic.kitsune@gmail.com>
# This file is a part of EmeraldEngine.
# This file contains commands to compile the software using `make`.
#
#####################
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.
#
#####################


# CC: compiler - CFLAGS: compiler's parameters
# LDFLAGS: dynamic libs to link - EXEC: executable's name 
CC = gcc
CFLAGS = -W -Wall
LDFLAGS = -lm -lallegro -lallegro_primitives -lallegro_dialog -lallegro_image
EXEC = test
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

# this target name MUST be the same as `EXEC`
test: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: macros.h common.h geoitems.h events.h image.h physics.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

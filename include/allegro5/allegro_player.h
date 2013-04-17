/*
 * This addon adds a Player class support to the Allegro game library.
 * Copyright (c) 2013 Kotori - <kotori@greenskin.hopto.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * For more information, visit http://www.gnu.org/copyleft
 */

#ifndef ALLEGRO_ALLEGRO_H
#define ALLEGRO_ALLEGRO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <allegro5/allegro.h>

enum Direction
{
	DIR_NORTH	= 0,
	DIR_NORTH_EAST	= 1,
	DIR_NORTH_WEST	= 2,
	DIR_EAST	= 3,
	DIR_SOUTH_EAST	= 4,
	DIR_SOUTH_WEST	= 5,
	DIR_SOUTH	= 6,
	DIR_WEST	= 7
};

typedef struct _Point	Point;
typedef struct _Rect	Rect;
typedef struct _Player	Mob;

//
// Helper functions
//

bool al_player_check_collision( Mob *player, Mob *target );

//
// Attribute Getters
//
int al_get_player_id( Mob *player );
int al_get_player_width( Mob *player );
int al_get_player_height( Mob *player );
int al_get_player_level( Mob *player );
int al_get_player_lives( Mob *player );
int al_get_player_speed( Mob *player );
bool al_get_player_visibility( Mob *player );
Point al_get_player_position( Mob *player );
Point al_get_player_prev_position( Mob *player );
ALLEGRO_BITMAP *al_get_player_image( Mob *player );
Direction al_get_player_direction( Mob *player );

//
// Attribute Setters
//
void al_set_player_id( Mob *player, int ident );
void al_set_player_width( Mob *player, int w );
void al_set_player_height( Mob *player, int h );
void al_set_player_level( Mob *player, int level );
void al_set_player_lives( Mob *player, int life );
void al_set_player_speed( Mob *player, int moveSpeed );
void al_set_player_visibility( Mob *player, bool isVisible );
void al_set_player_position( Mob *player, Point pos );
void al_set_player_prev_position( Mob *player, Point pos );
void al_set_player_image( Mob *player, ALLEGRO_BITMAP *img );
void al_set_player_direction( Mob *player, Direction dir );



#ifdef __cplusplus
}
#endif

#endif // ALLEGRO_ALLEGRO_H
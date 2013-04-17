/**
 * \file player.cpp
 */

#include "player.h"

bool al_player_check_collision( Mob *player, Mob *target )
{
	if( player->location.x < target->location.x || player->location.x < target->location.x + player->width ||
		player->location.y + player->height < target->location.y || player->location.y > target->location.y + player->height )
	{
		return false;
	}
	return true;
}

void al_player_draw( Mob *player )
{
	int srcX = 0;
	int srcY = 0;
	al_draw_bitmap_region( player->image, srcX, srcY * al_get_bitmap_height(player->image) / 4,
		32, 32, player->location.x, player->location.y, NULL );
}

void al_player_move( Mob *player, Direction dir )
{
	int direction = dir;
	switch( direction )
	{
		case DIR_SOUTH:
			player->location.y += player->speed;
			player->direction = DIR_SOUTH;
			break;
		case DIR_NORTH:
			player->location.y -= player->speed;
			player->direction = DIR_NORTH;
			break;
		case DIR_EAST:
			player->location.x += player->speed;
			player->direction = DIR_EAST;
			break;
		case DIR_WEST:
			player->location.x -= player->speed;
			player->direction = DIR_WEST;
			break;
	}
}

void al_player_free( Mob *player )
{
	if( player->image )
	{
		al_destroy_bitmap( player->image );
	}
}

//
// Getters
//
int al_get_player_id( Mob *player )
{
	return player->id;
}

int al_get_player_width( Mob *player )
{
	return player->width;
}

int al_get_player_height( Mob *player )
{
	return player->height;
}

int al_get_player_level( Mob *player )
{
	return player->level;
}

int al_get_player_lives( Mob *player )
{
	return player->livesLeft;
}

int al_get_player_speed( Mob *player )
{
	return player->speed;
}

int al_get_player_attack( Mob *player )
{
        return player->attrAttack;
}

int al_get_player_defense( Mob *player )
{
        return player->attrDefense;
}

bool al_get_player_visibility( Mob *player )
{
	return player->visible;
}

Point al_get_player_position( Mob *player )
{
	return player->location;
}

Point al_get_player_prev_position( Mob *player )
{
	return player->prevLocation;
}

ALLEGRO_BITMAP *al_get_player_image( Mob *player )
{
	return player->image;
}

Direction al_get_player_direction( Mob *player )
{
	return player->direction;
}

//
// Setters
//
void al_set_player_id( Mob *player, int ident )
{
	player->id = ident;
}

void al_set_player_width( Mob *player, int w )
{
	player->width = w;
}

void al_set_player_height( Mob *player, int h )
{
	player->height = h;
}

void al_set_player_level( Mob *player, int level )
{
	player->level = level;
}

void al_set_player_lives( Mob *player, int life )
{
	player->livesLeft = life;
}

void al_set_player_speed( Mob *player, int moveSpeed )
{
	player->speed = moveSpeed;
}

void al_set_player_attack( Mob *player, int atk )
{
        player->attrAttack = atk;
}

void al_set_player_defense( Mob *player, int def )
{
        player->attrDefense = def;
}


void al_set_player_visibility( Mob *player, bool isVisible )
{
	player->visible = isVisible;
}

void al_set_player_position( Mob *player, Point pos )
{
	player->location = pos;
}

void al_set_player_prev_position( Mob *player, Point pos )
{
        player->prevLocation = pos;
}

void al_set_player_image( Mob *player, ALLEGRO_BITMAP *img )
{
	player->image = img;
}

void al_set_player_direction( Mob *player, Direction dir )
{
	player->direction = dir;
}

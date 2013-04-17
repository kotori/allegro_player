/**
 * \file player.h
 */
#ifndef PLAYER_INC_H
#define PLAYER_INC_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_player.h>

// Single structure representing two points on a plane.
struct _Point
{
        float x; // X-axis point.
        float y; // Y-axis point.
};

// Single structure representing two sides of a rectangle, this sides are made up of points.
// Point 1 - Upper Left Side (upperLeft).
// Point 2 - Lower Right Side (lowerRight).
struct _Rect
{
        Point upperLeft; // Side #1.
        Point lowerRight; // Side #2.
};

// Structure representing our player object. This structure contains many different attributes that
//  are all available via the al_set_player_* and al_get_player_* commands respectively.
struct _Player
{
	int id;		// Player's unique ID tag.
	int width;	// Width of the player's image.
        int height;	// Height of the player's image.
        int level;	// Player's current level.
        int livesLeft;	// Player's current health.
	int speed;	// Player's movement speed.
	bool visible;	// Is this player visible on the screen?
	bool active;	// Is this player moving?

	enum Direction direction;	// Direction this player is facing.

        int attrAttack;		// Player's attack value.
        int attrDefense;	// Player's defensive value.

        Point location;		// Player's current location.
	Point prevLocation;	// Player's previous location.

        ALLEGRO_BITMAP *image;	// Player's image object.

	int animationIndexX;	// Current 'X' position in the animation index.
	int animationIndexY;	// Current 'Y' position in the animatin index.

};

// Player's function declarations

bool al_player_check_collision( Mob *player, Mob *target );
void al_player_draw( Mob *player );
void al_player_move( Mob *player, Direction dir );

void al_player_free( Mob *player );

//
// Getters
//
int al_get_player_id( Mob *player );
int al_get_player_width( Mob *player );
int al_get_player_height( Mob *player );
int al_get_player_level( Mob *player );
int al_get_player_lives( Mob *player );
int al_get_player_speed( Mob *player );
int al_get_player_attack( Mob *player );
int al_get_player_defense( Mob *player );
bool al_get_player_visibility( Mob *player );
bool al_get_player_active( Mob *player );
Point al_get_player_position( Mob *player );
Point al_get_player_prev_position( Mob *player );
ALLEGRO_BITMAP *al_get_player_image( Mob *player );
Direction al_get_player_direction( Mob *player );
int al_get_player_anim_x( Mob *player );
int al_get_player_anim_y( Mob *player );


//
// Setters
//
void al_set_player_id( Mob *player, int ident );
void al_set_player_width( Mob *player, int w );
void al_set_player_height( Mob *player, int h );
void al_set_player_level( Mob *player, int level );
void al_set_player_lives( Mob *player, int life );
void al_set_player_speed( Mob *player, int moveSpeed );
void al_set_player_attack( Mob *player, int atk );
void al_set_player_defense( Mob *player, int def );
void al_set_player_visibility( Mob *player, bool isVisible );
void al_set_player_active( Mob *player, bool isActive );
void al_set_player_position( Mob *player, Point pos );
void al_set_player_prev_position( Mob *player, Point pos );
void al_set_player_image( Mob *player, ALLEGRO_BITMAP *img );
void al_set_player_direction( Mob *player, Direction dir );
void al_set_player_anim_x( Mob *player, int sourceX );
void al_set_player_anim_y( Mob *player, int sourceY );


#endif // PLAYER_INC_H

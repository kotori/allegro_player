#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_player.h>

#define FPS 60
#define DEBUG 0

/*
* Utility debug method
* Used like printf, but only prints if DEBUG is set
*/
void debug( const char *format, ... )
{
	if( !DEBUG )
		return;

	va_list argptr;
	va_start(argptr, format);
	vprintf(format, argptr);
	printf("\n");
}

/*
* Application entry point
*/
int main(int argc, char *argv[])
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_KEYBOARD_STATE keyboard_state;

	bool running = true;
	bool redraw = true;
	bool reload = false;

	int screen_width = 640;
	int screen_height = 480;

	// Initialize allegro
	if (!al_init())
	{
		al_show_native_message_box(NULL, "Error" , NULL, "Could not Initialize Allegro!", NULL, NULL);
		fprintf( stderr, "Failed to Initialize Allegro!\n" );
		return 1;
	}

	// Initialize allegro_image addon
	if (!al_init_image_addon())
	{
		al_show_native_message_box(NULL, "Error" , NULL, "Could not Initialize Allegro Image Addon!", NULL, NULL);
		fprintf( stderr, "Failed to Initialize Allegro Image Addon!\n" );
		return 1;
	}

	// Initialize the timer
	timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		al_show_native_message_box(NULL, "Error" , NULL, "Could not Initialize Allegro Timer!", NULL, NULL);
		fprintf( stderr, "Failed to Initialize Allegro Timer!\n" );
		return 1;
	}

	// Install the keyboard
	if (!al_install_keyboard())
	{
		al_show_native_message_box(NULL, "Error" , NULL, "Could not Initialize Allegro Keyboard Routines!", NULL, NULL);
		fprintf( stderr, "Failed to Setup Keyboard!\n" );
		return 1;
	}

	// Create the display
	display = al_create_display(screen_width, screen_height);
	if( !display )
	{
		al_show_native_message_box(NULL, "Error" , NULL, "Could not Create Display!", NULL, NULL);
		fprintf( stderr, "Failed to Initialize Display!\n" );
		return 1;
	}
	else
	{
		al_set_window_title(display, "allegro_player library example");
	}

	// Create the event queue
	event_queue = al_create_event_queue();
	if( !event_queue )
	{
		al_show_native_message_box(NULL, "Error" , NULL, "Could not Initialize Allegro Event Queue!", NULL, NULL);
		fprintf( stderr, "Failed to Initialize Allegro Event Queue!\n" );
		return 1;
	}

	// Register event sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());


	al_start_timer( timer );

	al_clear_to_color(al_map_rgb(0, 0, 0));

	// FPS counter
	double old_time = al_get_time(), fps = 0;
	int frames_done = 0;

	// Main loop
	while( running )
	{
		ALLEGRO_EVENT event;
		ALLEGRO_TIMEOUT	timeout;

		// Initialize the timeout (not the game's clock, I think)
		al_init_timeout(&timeout, 0.06);

		// Fetch the event (if one exists)
		bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);

			// Handle the event
		if( get_event )
		{
			switch (event.type)
			{
				case ALLEGRO_EVENT_TIMER:
					// is an arrow key being held?
					al_get_keyboard_state( &keyboard_state );
					if( al_key_down( &keyboard_state, ALLEGRO_KEY_RIGHT ) )
					{
						//
					}
					else if( al_key_down(&keyboard_state, ALLEGRO_KEY_LEFT ) )
					{
						//
					}
					else if( al_key_down(&keyboard_state, ALLEGRO_KEY_UP ) )
					{
						//
					}
					else if( al_key_down(&keyboard_state, ALLEGRO_KEY_DOWN ) )
					{
						//
					}
					redraw = true;
					break;
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					running = false;
					break;
				case ALLEGRO_EVENT_KEY_DOWN:
					// ignore
					break;
				case ALLEGRO_EVENT_KEY_UP:
					// ignore
					break;
				case ALLEGRO_EVENT_KEY_CHAR:
					if( event.keyboard.keycode == ALLEGRO_KEY_SPACE )
					{
						reload = true;
					}
					break;
			}
		}

		if( redraw && al_is_event_queue_empty( event_queue ) )
		{
			al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
			#if DEBUG
				double game_time = al_get_time();
				if( game_time - old_time >= 1.0 )
				{
					fps = frames_done / (game_time - old_time);
					frames_done = 0;
					old_time = game_time;
					fprintf( stderr, "FPS:%f\n", fps );
				}
				frames_done++;
			#endif
			al_flip_display();
			redraw = false;
		}
	}

	al_destroy_display( display );
	al_destroy_event_queue( event_queue );
	return 0;
}

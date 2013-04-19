allegro\_player
===============

allegro\_player is an [Allegro5] (http://alleg.sourceforge.net/) module that adds a Player class that makes it easier to handle
all of the different attributes and stats a Player might have. This includes, level, life, animation images, x/y locations, etc.


Compiling the Library
=====================

Linux:
------

Make sure you have installed the following:
* allegro
* allegro_image
* zlib

To generate documentation, a doxygen file is provided.

	doxygen allegro_player.doxy

The run 'make' in the root directory to compile. You can then run 'sudo make install' to install the library to the standard location for your OS.


Other Platforms:
----------------

No other platforms are supported at this time. If you would like to assist in porting this to other Operating Systems, please drop me a line!

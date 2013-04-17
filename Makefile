CC  	:= clang
LIBNAME := allegro_player
PKGS	:= allegro-5 allegro_image-5
CFLAGS  := -g -fPIC -Wall -Iinclude $(shell pkg-config --cflags $(PKGS))
LIBS    := $(shell pkg-config --libs $(PKGS))

TARGET  := lib$(LIBNAME).so
LDFLAGS := -shared -Wl,-soname=$(TARGET)
SOURCES := $(shell find src/ -type f -name *.cpp)
OBJECTS := $(patsubst src/%,build/%,$(SOURCES:.cpp=.o))
DEPS 	:= $(OBJECTS:.o=.deps)

PREFIX	= /usr
INCDIR	= $(PREFIX)/include
ifeq ($(shell getconf LONG_BIT),64)
	LIBDIR = $(PREFIX)/lib64
else
	LIBDIR= $(PREFIX)/lib
endif

HEADER	= "allegro5/allegro_player.h"
PCFILE	= "allegro_player-5.0.pc"
TMPDIR = $(PREFIX)
DOCS = docs

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "  Linking...";
	$(CC) $(LDFLAGS) $^ -o $(TARGET) $(LIBS)

build/%.o: src/%.cpp | init
	@echo "  CC $<";
	$(CC) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<

init:
	@mkdir -p build/

install: all
	@echo "  Installing..."
	@echo " Libs..."
	@install -D -m 0644 "$(TARGET)" "$(DESTDIR)$(LIBDIR)/$(TARGET)"
	@echo " Includes..."
	@install -D -m 0644 "include/$(HEADER)" "$(DESTDIR)$(INCDIR)/$(HEADER)"

	@echo " Moving allegro_tiled-5.0.pc into $(DESTDIR)$(TMPDIR)"

	@cat "misc/$(PCFILE)" | sed 's#@LIBDIR@#$(LIBDIR)#g' | sed 's#@INCDIR@#$(INCDIR)#g' > "$(DESTDIR)$(TMPDIR)/$(PCFILE)"
	@install -D -m 0644 "$(DESTDIR)$(TMPDIR)/$(PCFILE)" "$(DESTDIR)$(LIBDIR)/pkgconfig/$(PCFILE)"
	@$(RM) "$(DESTDIR)$(TMPDIR)/$(PCFILE)"

uninstall:
	@echo "  Uninstalling..."
	$(RM) "$(DESTDIR)$(LIBDIR)/$(TARGET)"
	$(RM) "$(DESTDIR)$(INCDIR)/$(HEADER)"
	$(RM) "$(DESTDIR)$(LIBDIR)/pkgconfig/$(PCFILE)"

clean:
	@echo "  Cleaning...";
	$(RM) -r build/ $(TARGET)
	$(RM) -r docs/

-include $(DEPS)

.PHONY: all clean init install uninstall

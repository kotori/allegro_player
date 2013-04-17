CC := clang
TARGET := example
CFLAGS := -I../include -g
LDFLAGS := -L..
LIBS := -lallegro -lallegro_image -lallegro_dialog -lallegro_player
SOURCES := $(shell find src/ -type f -name "*.cpp")
OBJECTS := $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo " Linking...";
	$(CC) $(LDFLAGS) $^ -o $(TARGET) $(LIBS)

%.o: %.cpp
	@echo " CC $<";
	$(CC) $(CFLAGS) -c -o $@ $<

init:
	@mkdir -p build/

clean:
	@echo " Cleaning...";
	$(RM) -r build/ $(TARGET)
	$(RM) src/*.o

run: $(TARGET)
	@echo " Starting...";
	LD_LIBRARY_PATH=.. ./$(TARGET)

.PHONY: clean run

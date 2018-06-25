CC = g++

SOURCE_PATH = src
BUILD_PATH = build
BIN_PATH = bin

SOURCE_EXT = cc

RUNNER = AddressBook

DEBUG_FLAGS = -g -Wall # -O0
RELEASE_FLAGS = -O3

ifeq ($(TARGET),release)
	TARGET_FLAGS = $(RELEASE_FLAGS)
else
	TARGET_FLAGS = $(DEBUG_FLAGS)
endif

SOURCES = $(SOURCE_PATH)/main.$(SOURCE_EXT) $(SOURCE_PATH)/AddressBook.$(SOURCE_EXT) $(SOURCE_PATH)/User.$(SOURCE_EXT)
OBJECTS = $(SOURCES:$(SOURCE_PATH)/%.$(SOURCE_EXT)=$(BUILD_PATH)/%.o)

COMPILE_FLAGS = -std=c++17 $(TARGET_FLAGS)
INCLUDES = -I include/
LIBS = -L lib

.PHONY: all
all: $(BIN_PATH)/$(RUNNER)

$(BIN_PATH)/$(RUNNER): $(OBJECTS)
	$(CC) $(LIBS) $(OBJECTS) -o $@

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.$(SOURCE_EXT)
	$(CC) -c $(COMPILE_FLAGS) $(INCLUDES) $< -o $@

.PHONY: test
test:
	$(CC) $(COMPILE_FLAGS) $(INCLUDES) $(LIBS) test/test.$(SOURCE_EXT) -o bin/test

.PHONY: clean
clean:
	@$(RM) $(BUILD_PATH)/* bin/*
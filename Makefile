APP_NAME  := wikictl
SRC_DIR   := ./src
OBJ_DIR   := ./build
BIN_DIR   := ./bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
RM        := rm -rf
SHELL     := sh
SILENT    := @

CXX      := gcc
CXXFLAGS := -ggdb -Wall -O0 -I"include/" -I"config/" -fshort-enums -Wunused -Wuninitialized -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wpadded -Wshadow -Waggregate-return

all: clean version compile

version:
	$(SILENT)$(SHELL) generate_version.sh

compile: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(APP_NAME) $^
	$(SILENT)@echo '$(APP_NAME) build: $(BIN_DIR)/$(APP_NAME) generated.'
	$(SILENT)@echo ' '

# For each c file generate an obj file 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(SILENT)@echo ' '
	$(SILENT)@echo 'Building file: $<'
	$(CXX) -c "$<" -o "$@" $(CXXFLAGS)
	$(SILENT)@echo 'Finished building: $<'
	$(SILENT)@echo ' '

clean:
	$(SILENT)@echo 'Cleaning...'
	$(RM) $(OBJ_FILES)
	$(RM) $(BIN_DIR)/$(APP_NAME)
	$(RM) config/version.h

deb: compile
	cp $(BIN_DIR)/$(APP_NAME) $(APP_NAME)/usr/bin
	dpkg-deb --build $(APP_NAME)
APP_NAME  := wikictl
SRC_DIR   := ./src
OBJ_DIR   := ./build
BIN_DIR   := ./bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
RM        := rm -rf
SILENT := @

CXX      := gcc
CXXFLAGS := -ggdb -Wall -O0 -fshort-enums -Wunused -Wuninitialized -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wpadded -Wshadow -Wlogical-op -Waggregate-return

all: clean compile

compile: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(APP_NAME) $^
	$(SILENT)@echo '$(APP_NAME) build: $(BIN_DIR)/$(APP_NAME) generated.'
	$(SILENT)@echo ' '

# For each c file generate an obj file 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(SILENT)@echo 'Building file: $<'
	$(CXX) -c "$<" -o "$@" $(CXXFLAGS)
	$(SILENT)@echo 'Finished building: $<'
	$(SILENT)@echo ' '

clean:
	$(SILENT)@echo 'Cleaning...'
	$(RM) $(OBJ_FILES)
	$(RM) $(BIN_DIR)/$(APP_NAME)
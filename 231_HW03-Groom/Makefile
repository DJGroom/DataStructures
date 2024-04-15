
# ==============================================================================#=
# Makefile
#
# Use this script to build a C++ application.
# Run 'make' from the top-level root folder of your project.
# This works from the MSYS2 MINGW64 shell environment.
#
# SPDX-License-Identifier: MIT-0
# ==============================================================================#=

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
# SOURCE FILES
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
SRC_FILES  = lib/UnsortedList.cpp
SRC_FILES += appl/ItemType.cpp
SRC_FILES += lib/main.cpp

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
# INCLUDE DIRECTORIES
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
INC_DIRS  = lib
INC_DIRS += appl

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
# The name of the app we are building.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
APP_NAME   = main

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
# Compiler & Linker Options
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
CFLAGS   = -g
LDFLAGS  = $(CFLAGS)


# ======================================================================#=
# Makefile Common
# You should not have to change any of the following.
# ======================================================================#=

# List of full-path object files relative to the current directory.
OBJ_FILES     = $(patsubst  %.cpp, build/%.o, $(SRC_FILES))

# Compiler Include Path Options
INC_DIR_OPTS  = $(foreach inc, $(INC_DIRS), $(addprefix -I,$(inc)))
INC_DIR_OPTS += -I.


# --------------------------------------------------------------+-
# help target
# --------------------------------------------------------------+-
help:
	@echo
	@echo "Instructions..."
	@echo
	@echo "To build the application:"
	@echo "    make build"
	@echo
	@echo "Other build targets available:"
	@echo "    clean"
	@echo "    build"
	@echo "    rebuild"
	@echo "    run"
	@echo "    make-debug"
	@echo

# --------------------------------------------------------------+-
# clean target
# --------------------------------------------------------------+-
clean:
	@echo
	@echo "Removing the entire build directory..."
	$(REMOVE) build
	$(REMOVE) $(APP_NAME).exe
	@echo


# --------------------------------------------------------------+-
# build target
# --------------------------------------------------------------+-
build: $(APP_NAME).exe
	@echo
	@echo Build Target Complete.
	@echo


# --------------------------------------------------------------+-
# rebuild target
# --------------------------------------------------------------+-
rebuild: clean build


# --------------------------------------------------------------+-
# test (run executable)
# --------------------------------------------------------------+-
run: 
	.\$(APP_NAME).exe
	@echo
	@echo
	


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
# Link Rule
#
# Rule to build the application of interest.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
$(APP_NAME).exe: $(OBJ_FILES)
	@echo
	@echo $(BANNER)
	@echo Linking: $^
	@echo    Into: $@
	@echo $(BANNER)
	@$(MKDIR) $(@D)
	$(LINK) $(LDFLAGS) $^  -o $@


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
# Compilation Rule
#
# Implicit pattern rule to compile each source file
# into its corresponding object file in the build directory.
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
build/%.o: %.cpp
	@echo
	@echo $(BANNER)
	@echo "Compiling: $< "
	@echo "     Into: $@ "
	@echo $(BANNER)
	@$(MKDIR)  $(@D)
	$(COMPILE) $(CFLAGS)  $(INC_DIR_OPTS)  $<  -o $@


# --------------------------------------------------------------+-
# Tools on this platform.
# Assumes linux or linux like tools are available.
# --------------------------------------------------------------+-
COMPILE = g++ -c
LINK    = g++
MKDIR   = mkdir -p
REMOVE  = rm -rfv
BANNER  = ------------------------------------------------------------------------+-


# --------------------------------------------------------------+-
# make-debug target
#
# To help debug this script,
# dump the essential variables defined in this makefile.
# --------------------------------------------------------------+-
make-debug:
	@echo
	@echo APP_NAME:       $(APP_NAME)
	@echo SRC_FILES:      $(SRC_FILES)
	@echo OBJ_FILES:      $(OBJ_FILES)
	@echo CFLAGS:         $(CFLAGS)
	@echo INC_DIR_OPTS:   $(INC_DIR_OPTS)
	@echo COMPILE:        $(COMPILE)
	@echo LINK:           $(LINK)
	@echo MKDIR:          $(MKDIR)
	@echo REMOVE:         $(REMOVE)
	@echo
	@echo



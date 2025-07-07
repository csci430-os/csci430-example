# compiler flags, tools and include variables
GCC=g++
GCC_FLAGS=-Wall -Werror -pedantic -std=c++20 -g
INCLUDES=-Iinclude
LINKS=

FORMATTER=clang-format
FORMATTER_FLAGS=-i

FORMATTER=clang-format
DOC=doxygen
PANDOC=pandoc
RM=rm -rf

FORMATTER_FLAGS=-i
DOC_FLAGS=config/Doxyfile
PANDOC_FLAGS=-s --variable geometry:margin=0.75in --variable urlcolor:NavyBlue --variable colorlinks:true
PANDOC_HIGHLIGHT=--highlight-style tango

SRC_DIR := src
OBJ_DIR := obj
DOC_DIR := doc
BIN_DIR := bin
INC_DIR := include
HELLO_TARGET=$(BIN_DIR)/hello-world
IOSTRING_TARGET=$(BIN_DIR)/io-string
TEST_TARGET=$(BIN_DIR)/test-mystatslib
PROCESS_TARGET=$(BIN_DIR)/test-process
STL_SEQUENCE_TARGET=$(BIN_DIR)/stl-sequence-containers
STL_MAP_TARGET=$(BIN_DIR)/stl-map-containers


# sources and objects for executables
hello_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(hello_src))
hello_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(hello_src))

iostring_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(iostring_src))
iostring_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(iostring_src))

test_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(test_src))
test_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(test_src))
catch_test_obj := $(OBJ_DIR)/catch2-main.o

process_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(process_src))
process_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(process_src))

stl_sequence_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(stl_sequence_src))
stl_sequence_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(stl_sequence_src))

stl_map_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(stl_map_src))
stl_map_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(stl_map_src))


# pdf files for assignment description documentation
assg_doc := $(patsubst %.pdf, $(DOC_DIR)/%.pdf, $(assg_doc))

## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##
.PHONY : all
all : $(HELLO_TARGET) $(IOSTRING_TARGET) $(TEST_TARGET) $(PROCESS_TARGET) $(STL_SEQUENCE_TARGET) $(STL_MAP_TARGET)


## hello-world  : Build and link together the hello world executable
##
$(HELLO_TARGET) : $(hello_obj) | $(BIN_DIR)
	$(GCC) $(GCC_FLAGS) $(hello_obj)  -o $@

## io-string  : Build and link together the io-string example executable
##
$(IOSTRING_TARGET) : $(iostring_obj) | $(BIN_DIR)
	$(GCC) $(GCC_FLAGS) $(iostring_obj)  -o $@

## test-mystatslib  : Build and link together the test-mystatslib
##                    example executable
##
$(TEST_TARGET) : $(test_obj) $(catch_test_obj) | $(BIN_DIR)
	$(GCC) $(GCC_FLAGS) $(test_obj) $(catch_test_obj)  -o $@

## test-process : Build and link together the test-process
##                    example executable
##
$(PROCESS_TARGET) : $(process_obj) $(catch_test_obj) | $(BIN_DIR)
	$(GCC) $(GCC_FLAGS) $(process_obj) $(catch_test_obj)  -o $@

## stl-sequence-containers : Build and link together the stl sequence containers
##                    example executable
##
$(STL_SEQUENCE_TARGET) : $(stl_sequence_obj) | $(BIN_DIR)
	$(GCC) $(GCC_FLAGS) $(stl_sequence_obj)  -o $@

## stl-map-containers : Build and link together the stl map containers
##                    example executable
##
$(STL_MAP_TARGET) : $(stl_map_obj) | $(BIN_DIR)
	$(GCC) $(GCC_FLAGS) $(stl_map_obj)  -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

## unit-tests   : Run the unit tests showing failing tests only
##
unit-tests : $(TEST_TARGET)
	./$(TEST_TARGET) --use-colour yes

## system-tests : Run the system tests on the full simulation
##
#system-tests: $(SIM_TARGET)
#	./scripts/run-system-tests

## format       : Run the code formatter/beautifier by hand if needed
##
.PHONY : format
format :
	$(FORMATTER) $(FORMATTER_FLAGS) include/*.hpp src/*.cpp


## refdocs      : Create doxygen reference documentation from
##                doc comments.
##
.PHONY : refdocs
refdocs :
	@echo "Generating doxygen documentation..."
	$(DOC) $(DOC_FLAGS) 2>&1 | grep -A 1 warning | egrep -v "assg.*\.md" | grep -v "Found unknown command" | grep -v "Searching for include" | sed -e "s|${PWD}/||g"


## assgdocs     : Create assignment description documentation from
##                README.md project markdown file.
##
.PHONY : assgdocs
assgdocs : $(assg_doc)

$(assg_doc) : README.md
	${PANDOC} ${PANDOC_FLAGS} ${PANDOC_HIGHLIGHT} -o $@ $^


## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) $(HELLO_TARGET) $(IOSTRING_TARGET) $(TEST_TARGET) $(PROCESS_TARGET) $(STL_SEQUENCE_TARGET) $(STL_MAP_TARGET) *.o *.gch
	$(RM) output html latex
	$(RM) $(hello_obj) $(iostring_obj) $(test_obj) $(process_obj) $(stl_sequence_obj) $(stl_map_obj)

## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile include/Makefile.inc
	@sed -n 's/^##//p' $^

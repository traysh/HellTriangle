TARGET := hell_triangle
OUTPUT := build

# Compiler
CXX ?= g++

# Files to be compiled
CPP_FILES = $(sort $(shell find src/ -type f -name '*.cpp'))
CPP_OBJ_FILES = $(patsubst src/%.cpp, $(OUTPUT)/%.o, $(CPP_FILES))

# Includes
INCLUDES = $(sort $(shell find ./src/ -type d -name 'inc' -exec echo " -I"{} \; ) $(INCLUDES_GTEST))
INCLUDES_GTEST = $(foreach header,$(GTEST_HEADERS), -I$(header))

# Compiler flags
CXXFLAGS = -g -Wall -Werror -fstack-protector -O3 -Wfatal-errors -std=c++11 $(INCLUDES)
LD_FLAGS = -pthread

.PHONY: all
all: $(OUTPUT)/$(TARGET)

# Final target will result in binary
$(OUTPUT)/$(TARGET): $(CPP_OBJ_FILES)
	@echo 'Building Target: $@'
	@echo 'Invoking Linker'
	@mkdir -p $(dir $@)
	$(CXX) $(LD_FLAGS) $^ -o $@
	@echo 'Finished building: $@'
	@echo ' '
	
	
$(CPP_OBJ_FILES): $(OUTPUT)/%.o: src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: gcc Compiler'
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c "$<" -o "$@" 
	@echo 'Finished building: $<'
	@echo ' '

CPP_DEPS := $(CPP_OBJ_FILES:.o=.d)

ifneq "$(MAKECMDGOALS)" "clean"
-include $(CPP_DEPS)
endif

CREATE_DEPENDENCY = -MM -MP -MT"$(@:.d=.o) $@" $< | cat -s > $@

$(CPP_DEPS): $(OUTPUT)/%.d: src/%.cpp
	@echo -e '\e[7mCreating dependency for $(notdir $<)...\e[0m'
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(CREATE_DEPENDENCY)
	@echo -e '\e[7mCreated dependency for $(notdir $<)\e[0m'


#######################################################################################################
#######################################################################################################
############################################ GOOGLE TEST #############################################
#######################################################################################################
#######################################################################################################
G_TEST_COMPILER := g++
GTEST_DIR = googletest/googletest
USER_DIR = tests
GTEST_CPPFLAGS += -isystem $(GTEST_DIR)/include
GTEST_CXXFLAGS += -g -Wall -Wextra -pthread -Wfatal-errors

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
	$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS)
	@echo 'Building file: gtest-all.cc'
	$(G_TEST_COMPILER) $(GTEST_CPPFLAGS) -I$(GTEST_DIR) $(GTEST_CPPFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS)
	@echo 'Building file: gtest_main.cc'
	$(G_TEST_COMPILER) $(GTEST_CPPFLAGS) -I$(GTEST_DIR) $(GTEST_CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	@echo 'Running AR for gtest.a'
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	@echo 'Running AR for gtest_main.a'
	$(AR) $(ARFLAGS) $@ $^

GTEST_CPP_FILES := $(shell find tests  -name '*.cpp')

G_TEST_CPP_OBJ_FILES := $(patsubst %.cpp,%.o,$(GTEST_CPP_FILES))
GTEST_C_DEPS := $(patsubst %.cpp,%.d,$(GTEST_CPP_FILES))

CPP_OBJ_FILES_NO_MAIN := $(filter-out $(OUTPUT)/main.o, $(CPP_OBJ_FILES))

$(USER_DIR)/%.o: $(USER_DIR)/%.cpp $(CPP_OBJ_FILES_NO_MAIN) gtest_main.a
	@echo 'Building file: $<'
	@echo 'Invoking: G++ Compiler'
	@echo 'NO MAIN: $(CPP_OBJ_FILES_NO_MAIN)'
	$(G_TEST_COMPILER) -I$(INCLUDES) -I$(GTEST_HEADERS) $(GTEST_CPPFLAGS) $(GTEST_CXXFLAGS) $(LD_FLAGS) gtest_main.a $^ -o $@
	@echo 'Finished building: $<'
	@echo ' '

# Test target
test: $(G_TEST_CPP_OBJ_FILES)
	@echo 'Init on test target'
	@echo 'Compiled tests: $(G_TEST_CPP_OBJ_FILES)'
	$(foreach tst,$(G_TEST_CPP_OBJ_FILES),printf "\n\n\n"; echo '[INFO] executing $(tst)'; ./$(tst);)

# Test target with valgrind for memory analysis
test-valgrind: $(G_TEST_CPP_OBJ_FILES)
	@echo 'Init on test target'
	@echo 'Compiled tests: $(G_TEST_CPP_OBJ_FILES)'
	$(foreach tst,$(G_TEST_CPP_OBJ_FILES),printf "\n\n\n"; echo '[INFO] executing $(tst)'; valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(tst);)

clean:
	$(RM)	$(CPP_OBJ_FILES) $(CPP_DEPS) $(OUTPUT)/$(TARGET) *.a *.o $(USER_DIR)/*.d $(USER_DIR)/*.o

.PHONY: clean test test-valgrind


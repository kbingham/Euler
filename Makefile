MAKEFLAGS =+ -j

CFLAGS += -g -Wall -Werror


LIBRARY_C_FILES = $(shell ls lib/*.c)
LIBRARY_H_FILES = $(shell ls lib/*.h)
LIBRARY_O_FILES = $(LIBRARY_C_FILES:.c=.o)

LIBRARY = lib/common.a

CFLAGS += -Ilib/

TESTS = prime NextPrime IsPrime Factor Triangle
PROBLEM_LIST = 1 2 3 4 5 6 7 8 9 10 12

# Generate a list of all the Problems
PROBLEMS = $(addprefix problem, $(PROBLEM_LIST))

# Create the target list
TARGETS = $(addprefix src/, $(TESTS) $(PROBLEMS))

all: ${TARGETS}

lib: $(LIBRARY)

$(LIBRARY_O_FILES): $(LIBRARY_H_FILES)

$(LIBRARY): $(LIBRARY_O_FILES)
	ar r $(LIBRARY) $(LIBRARY_O_FILES)

${TARGETS}: $(LIBRARY)

clean:
	rm $(LIBRARY) $(LIBRARY_O_FILES) $(TARGETS)


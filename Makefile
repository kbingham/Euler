MAKEFLAGS =+ -j

CFLAGS += -g -Wall -Werror


LIBRARY_C_FILES = $(shell ls lib/*.c)
LIBRARY_O_FILES = $(LIBRARY_C_FILES:.c=.o)

LIBRARY = lib/common.a

CFLAGS += -Ilib/

TESTS = prime NextPrime IsPrime Factor Triangle
PROBLEM_LIST = 1 2 3 4 5 6 7 10 12
PROBLEMS = $(addprefix problem, $(PROBLEM_LIST))

TARGETS = $(addprefix src/, $(TESTS) $(PROBLEMS))

all: ${TARGETS}

$(LIBRARY): $(LIBRARY_O_FILES)
	ar r $(LIBRARY) $(LIBRARY_O_FILES)

${TARGETS}: $(LIBRARY)

clean:
	rm $(LIBRARY) $(LIBRARY_O_FILES) $(TARGETS)


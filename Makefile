CFLAGS += -g -Wall -Werror

LIBRARY = lib/common.o
CFLAGS += -Ilib/

LDFLAGS += $(LIBRARY)

TESTS = prime NextPrime IsPrime Factor Triangle
PROBLEM_LIST = 1 2 3 4 5 6 7 10 12
PROBLEMS = $(addprefix problem, $(PROBLEM_LIST))

TARGETS = $(LIBRARY) $(addprefix src/, $(TESTS) $(PROBLEMS))

all: ${TARGETS}

clean:
	rm ${TARGETS}


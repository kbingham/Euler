CFLAGS += -g -Wall -Werror

LIBRARY = lib/common.o
CFLAGS += -Ilib/

LDFLAGS += $(LIBRARY)

TESTS = prime NextPrime IsPrime Factor Triangle
PROBLEMS = problem1 problem2 problem3 problem5 problem6 problem7 problem10 problem12

TARGETS = $(LIBRARY) $(addprefix src/, $(TESTS) $(PROBLEMS))

all: ${TARGETS}

clean:
	rm ${TARGETS}


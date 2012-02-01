CFLAGS += -g -Wall -Werror

LDFLAGS += common.o

LIBRARY = common.o
TESTS = prime NextPrime IsPrime
PROBLEMS = problem1 problem2 problem3

TARGETS = $(LIBRARY) $(TESTS) $(PROBLEMS)

all: ${TARGETS}

clean:
	rm ${TARGETS}


CFLAGS += -g -Wall -Werror

LDFLAGS += common.o

LIBRARY = common.o
TESTS = prime NextPrime IsPrime Factor Triangle
PROBLEMS = problem1 problem2 problem3 problem5 problem6 problem7 problem10

TARGETS = $(LIBRARY) $(TESTS) $(PROBLEMS)

all: ${TARGETS}

clean:
	rm ${TARGETS}


CFLAGS += -g -Wall -Werror

LDFLAGS += common.o

TARGETS = common.o
TARGETS += problem1

all: ${TARGETS}

clean:
	rm ${TARGETS}

common.o: common.c


MAKEFLAGS =+ -j

CFLAGS += -g -Wall -Werror

# Create the Library Build Lists
LIBRARY_H_FILES = $(wildcard lib/*.h)
LIBRARY_O_FILES = $(patsubst %.c,%.o,$(wildcard lib/*.c))

LIBRARY = lib/common.a

CFLAGS += -Ilib/

# Create the target list
TARGETS = $(patsubst %.c,%,$(wildcard src/*.c))

# Top level Build Rule
all: ${TARGETS}

lib: $(LIBRARY)

$(LIBRARY_O_FILES): $(LIBRARY_H_FILES)

$(LIBRARY): $(LIBRARY_O_FILES)
	ar r $(LIBRARY) $(LIBRARY_O_FILES)

${TARGETS}: $(LIBRARY)

clean:
	rm $(LIBRARY) $(LIBRARY_O_FILES) $(TARGETS)


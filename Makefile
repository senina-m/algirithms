BUILDDIR=build
SRCDIR=src
CC=clang

all: $(BUILDDIR)/task_a.o
	$(CC) -o $(BUILDDIR)/task_a $^

build:
	mkdir -p $(BUILDDIR)

task_a: build
	$(CC) -g -o $(BUILDDIR)/task_a ${SRCDIR}/task_a.c

clean:
	rm -rf $(BUILDDIR)
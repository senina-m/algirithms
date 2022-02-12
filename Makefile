BUILDDIR=build
SRCDIR=src
CC=clang

all: task_a task_a_alternative task_b

build:
	mkdir -p $(BUILDDIR)/week_1

task_a: build
	$(CC) -g -o $(BUILDDIR)/week_1/task_a ${SRCDIR}/week_1/task_a.c

task_a_alternative: build
	$(CC) -g -o $(BUILDDIR)/week_1/task_a ${SRCDIR}/week_1/task_a.c

task_b: build
	$(CC) -g -o $(BUILDDIR)/week_1/task_a ${SRCDIR}/week_1/task_a.c

clean:
	rm -rf $(BUILDDIR)
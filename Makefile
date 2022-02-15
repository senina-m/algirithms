BUILDDIR=build
SRCDIR=src
CC=clang
CCP=g++
ADRESSFLAGS=-fsanitize=address

all: task_a task_a_alternative task_b task_b_alternative task_c

build:
	mkdir -p $(BUILDDIR)/week_1

task_a: build
	$(CC) -g -o $(BUILDDIR)/week_1/task_a ${SRCDIR}/week_1/task_a.c

task_a_alternative: build
	$(CC) -g -o $(BUILDDIR)/week_1/task_a_alternative ${SRCDIR}/week_1/task_a_alternative.c

task_b: build
	$(CCP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/task_b ${SRCDIR}/week_1/task_b.cc

task_b_alternative: build
	$(CCP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/task_b_alternative ${SRCDIR}/week_1/task_b_alternative.cc

task_c: build
	$(CCP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/task_c ${SRCDIR}/week_1/task_c.cc

clean:
	rm -rf $(BUILDDIR)
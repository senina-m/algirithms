BUILDDIR=build
SRCDIR=src
CC=clang
CPP=g++
ADRESSFLAGS=-fsanitize=address

all: task_a task_a_alternative task_b task_b_alternative task_c task_c_v1 task_d 1005 task_j

build:
	mkdir -p $(BUILDDIR)/week_1 $(BUILDDIR)/week_2 $(BUILDDIR)/week_3 $(BUILDDIR)/test

task_a: build
	$(CC) -g -o $(BUILDDIR)/week_1/task_a ${SRCDIR}/week_1/task_a.c

task_a_alternative: build
	$(CC) -g -o $(BUILDDIR)/week_1/task_a_alternative ${SRCDIR}/week_1/task_a_alternative.c

task_b: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/task_b ${SRCDIR}/week_1/task_b.cc

task_b_alternative: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/task_b_alternative ${SRCDIR}/week_1/task_b_alternative.cc

task_c: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/task_c ${SRCDIR}/week_1/task_c.cc

task_c_v1: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/task_c_v1 ${SRCDIR}/week_1/task_c_v1.cc

task_d: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/task_d ${SRCDIR}/week_1/task_d.cc

1005: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/1005 ${SRCDIR}/week_1/1005.cc

1155: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_1/1155 ${SRCDIR}/week_1/1155.cc

task_e: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_2/task_e ${SRCDIR}/week_2/task_e.cc

task_f: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_2/task_f ${SRCDIR}/week_2/task_f.cc

task_g: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_2/task_g ${SRCDIR}/week_2/task_g.cc

task_h: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_2/task_h ${SRCDIR}/week_2/task_h.cc

task_j: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_3/task_j ${SRCDIR}/week_3/task_j.cc

task_j_alt: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_3/task_j_alt ${SRCDIR}/week_3/task_j_alt.cc

task_l: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_3/task_l ${SRCDIR}/week_3/task_l.cc

task_i: build
	$(CPP) $(ADRESSFLAGS) -g -o $(BUILDDIR)/week_3/task_i ${SRCDIR}/week_3/task_i.cc

clean:
	rm -rf $(BUILDDIR)
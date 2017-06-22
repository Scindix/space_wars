AM_CPPFLAGS = --pedantic -Wall -std=gnu++11 -I../lib/nanovg/src -O3
AM_LDFLAGS = -L../lib/nanovg/build

bin_PROGRAMS = spacewars
spacewars_SOURCES = main.cpp
spacewars_LDADD = -lnanovg ../spaceships/_AllSpaceships.o

all-local: spacewars$(EXEEXT)
	cd .. && $(LN_S) src/spacewars$(EXEEXT) ../spacewars$(EXEEXT)

clean-local:
	rm -f ../spacewars$(EXEEXT)


# some variables describing your program source
# in most cases, you'll only need to edit these four variables
PROGRAM = revHW
HEADERS = String.h Stack.h
SOURCES = String.C Stack.C main.cpp
OBJECTS = main.o String.o Stack.o

# some useful others that you may need to edit
CC = g++
CFLAGS = -g
LIBS =

# name of this file
MF = makefile

.SUFFIXES: .o .h .c

# ---------------- Stuff you shoudn't have to change -----------
.C.o:
	$(CC) $(CFLAGS) -c -o $*.o $<

$(PROGRAM): $(OBJECTS)
	$(CC) -o $(PROGRAM) $(CFLAGS) $(OBJECTS) $(LIBS)

clean:
	@rm -f *~ "#*" *.o $(PROGRAM)

depend:
	@echo 'updating the dependencies for:'
	@echo '    ' $(SOURCES)
	@{ \
	< $(MF) sed -n '1,/^###.*SUDDEN DEATH/p'; \
		echo '#' ; \
		echo '# dependencies generated on: ' `date` ; \
		echo '#' ; \
		for i in $(SOURCES); do \
			$(CC) -MM $(CFLAGS) $(DEFINES) $$i ; \
			echo; \
		done \
	} > $(MF).new
	@mv $(MF) $(MF).last
	@mv $(MF).new $(MF)
#
# dependencies generated on:  Fri Oct 17 16:58:18 CST 2014
#
String.o: String.C String.h Stack.h

Stack.o: Stack.C stack.h

main.o: main.cpp String.h

#
# dependencies generated on:  Sat Oct 18 08:34:51 CST 2014
#
String.o: String.C String.h Stack.h

Stack.o: Stack.C stack.h

main.o: main.cpp String.h

#
# dependencies generated on:  Sat Oct 18 08:48:34 CST 2014
#
String.o: String.C String.h Stack.h

Stack.o: Stack.C stack.h

main.o: main.cpp String.h


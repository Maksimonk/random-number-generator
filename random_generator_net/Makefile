
CC=g++
SRCDIR = src
OBJDIR = obj

all: clean start

start: $(OBJDIR)/txtoutput.o $(OBJDIR)/randgen.o $(OBJDIR)/sniffer_linux.o
	$(CC) -o txtout $(OBJDIR)/txtoutput.o $(OBJDIR)/randgen.o $(OBJDIR)/sniffer_linux.o -lpcap
	
$(OBJDIR)/txtoutput.o: $(SRCDIR)/txtoutput.cpp
	$(CC) -c -o $@ $(SRCDIR)/txtoutput.cpp -lpcap
	
$(OBJDIR)/randgen.o: $(SRCDIR)/randgen.cpp
	$(CC) -c -o $@ $(SRCDIR)/randgen.cpp -lpcap
	
$(OBJDIR)/sniffer_linux.o: $(SRCDIR)/sniffer_linux.cpp
	$(CC) -c -o $@ $(SRCDIR)/sniffer_linux.cpp -lpcap
	
clean:
	rm -rf $(OBJDIR)/*.o


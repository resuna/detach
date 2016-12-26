# standard defines
SHELL=/bin/sh
CFLAGS=-O
SHARFILES=Makefile $(MISC) $(CFILES)
SHAR=$(TARGET).shar

# program dependent defines
OFILES=detach.o
CFILES=detach.c
TARGET=detach
MISC=detach.1

default: $(TARGET)

all: $(TARGET) shar

shar: $(SHAR)

$(TARGET): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(TARGET)

$(SHAR): $(SHARFILES)
	shar >$(SHAR) $(SHARFILES)

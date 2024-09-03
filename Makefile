# compiler
CC = gcc

CDIR = bottled
CINCLUDES += -I$(CDIR)/include

# compiler options
CFLAGS += -g

# c source code
COBJS += qfmt.o \
		 coordinate.o

# CFILES += $(CDIR)/lib/commom/qfmt.c \
# 		  $(CDIR)/lib/motor_control/coordinate.c
# library name
TARGET = bottled.lib


$(TARGET): $(COBJS)
	$(CC) $^ $(CFLAGS) $(CINCLUDES) -shared -o $(TARGET)
	@ rm -rf $(COBJS)

$(COBJS): $(CDIR)/lib/**/*.c
	$(CC) -c $^ $(CFLAGS) $(CINCLUDES)


.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -rf $(COBJS)


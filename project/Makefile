# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: Main.elf 

#additional rules for files
Main.elf: ${COMMON_OBJECTS} Main.c stateMachines.o led.o switches.o wdInterruptHandler.o p2_interrupt_handler.o  ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: Main.elf
	msp430loader.sh Main.elf

clean:
	rm -f *.o *.elf
stateMachines.o: stateMachines.c stateMachines.h

led.o: led.c led.h

switches.o: switches.c switches.h

wdInterrruptHandler.o: wdInterrruptHandler.c

p2_interrupt_handler.o: p2_interrupt_handler.c

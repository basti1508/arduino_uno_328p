include ${CURDIR}/../Makefile.inc

PROG=main

I2C=	$(TOP)/sw_i2c
UART=	$(TOP)/hw_uart

SRCS=$(PROG).c \
     $(I2C)/i2c.c \
     $(UART)/uart.c \
     nunchuk.c

CFLAGS+= -I${I2C} -I${UART}

CLEANFILES=$(PROG).hex $(PROG).out

$(PROG).hex: $(PROG).out
	$(OBJCOPY) -O ihex $(PROG).out $(PROG).hex

$(PROG).out: $(SRCS) $(TOP)/Makefile.inc
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(PROG).out $(SRCS)
	$(SIZE) $@

burn: $(PROG).hex
	$(AVR_DUDE) $(AVR_FLAGS) -e -U flash:w:$(PROG).hex

clean:
	rm -f $(CLEANFILES)

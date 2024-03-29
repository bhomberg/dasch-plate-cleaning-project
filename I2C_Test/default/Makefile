###############################################################################
# Makefile for the project I2C_Test
###############################################################################

## General Flags
PROJECT = I2C_Test
MCU = atmega1284p
TARGET = I2C_Test.elf
CC = avr-c++

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=I2C_Test.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"C:\Documents and Settings\Bianca\My Documents\Steven\DASCH\SVN Directory\I2C_Test\i2cmaster" 

## Libraries
LIBS = -lpololu_atmega1284p 

## Objects that must be built in order to link
OBJECTS = I2C_Test.o twimaster.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) I2C_Test.hex I2C_Test.eep I2C_Test.lss size

## Compile
I2C_Test.o: ../I2C_Test.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

twimaster.o: ../i2cmaster/twimaster.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) I2C_Test.elf dep/* I2C_Test.hex I2C_Test.eep I2C_Test.lss I2C_Test.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)


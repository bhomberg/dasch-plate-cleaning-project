################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../i2cmaster


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../i2cmaster/twimaster.c \
../DASCH_Plate_Cleaner_Rev2.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
i2cmaster/twimaster.o \
DASCH_Plate_Cleaner_Rev2.o


OBJS_AS_ARGS +=  \
i2cmaster/twimaster.o \
DASCH_Plate_Cleaner_Rev2.o


C_DEPS +=  \
i2cmaster/twimaster.d \
DASCH_Plate_Cleaner_Rev2.d


C_DEPS_AS_ARGS +=  \
i2cmaster/twimaster.d \
DASCH_Plate_Cleaner_Rev2.d


OUTPUT_FILE_PATH +=DASCH_Plate_Cleaner_Rev2.elf

OUTPUT_FILE_PATH_AS_ARGS +=DASCH_Plate_Cleaner_Rev2.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR32/GNU C Compiler





i2cmaster/%.o: ../i2cmaster/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (WinAVR 20100110) 4.3.3
	$(QUOTE)C:\WinAVR-20100110\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -I"..\..\..\DASCH_Plate_Cleaner_Rev2\i2cmaster" -I"..\..\..\DASCH_Plate_Cleaner_Rev2\."  -Os -fpack-struct -fshort-enums -Wall -c -gdwarf-2  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega1284p   -o"$@" "$<" 
	@echo Finished building: $<

./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (WinAVR 20100110) 4.3.3
	$(QUOTE)C:\WinAVR-20100110\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -I"..\..\..\DASCH_Plate_Cleaner_Rev2\i2cmaster" -I"..\..\..\DASCH_Plate_Cleaner_Rev2\."  -Os -fpack-struct -fshort-enums -Wall -c -gdwarf-2  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega1284p   -o"$@" "$<" 
	@echo Finished building: $<



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : (WinAVR 20100110) 4.3.3
	$(QUOTE)C:\WinAVR-20100110\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="DASCH_Plate_Cleaner_Rev2.map" -Wl,--start-group -Wl,-lpololu_atmega1284p  -Wl,--end-group -Wl,-L"..\..\..\..\..\..\..\..\libpololu-avr"   -mmcu=atmega1284p  
	@echo Finished building target: $@
	"C:\WinAVR-20100110\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "DASCH_Plate_Cleaner_Rev2.elf" "DASCH_Plate_Cleaner_Rev2.hex"
	"C:\WinAVR-20100110\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "DASCH_Plate_Cleaner_Rev2.elf" "DASCH_Plate_Cleaner_Rev2.eep" || exit 0
	"C:\WinAVR-20100110\bin\avr-objdump.exe" -h -S "DASCH_Plate_Cleaner_Rev2.elf" > "DASCH_Plate_Cleaner_Rev2.lss"
	"C:\WinAVR-20100110\bin\avr-size.exe" "DASCH_Plate_Cleaner_Rev2.elf"
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "DASCH_Plate_Cleaner_Rev2.elf" "DASCH_Plate_Cleaner_Rev2.a" "DASCH_Plate_Cleaner_Rev2.hex" "DASCH_Plate_Cleaner_Rev2.lss" "DASCH_Plate_Cleaner_Rev2.eep" "DASCH_Plate_Cleaner_Rev2.map"
	
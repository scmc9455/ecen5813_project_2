#**************************************************************************#
#@file - Makefile
#
#@breif - This is the Makefile that will compiler the project1 executable
#
#@author - Scott McElroy
#
#@data - March 4, 2018
#
#**************************************************************************#

include sources.mk

#***********Variables******
GENFLAGS:= -Wall -Werror -g -O0 -std=c99
LDFLAGS:= -Wl,-Map=main.map

#**************Switch statements for the platform determination**********
ifeq ($(PLATFORM),KL25Z)
CPU = cortex-m0plus
CC = arm-none-eabi-gcc
ARCH= armv6-m	
CFLAGS = $(GENFLAGS) -march=$(ARCH) -mcpu=$(CPU) -mthumb \
-mfloat-abi=soft -mfpu=fpv4-sp-d16 --specs=nosys.specs
INCLUDES = -I./../include/common \
-I./../include/kl25z \
-I./../include/CMSIS \
-I./../platform
LDFLAGS += -T ./../platform/MKL25Z128xxx4_flash.ld

else ifeq ($(PLATFORM),BBB)
CC = arm-linux-gnueabi-gcc
CFLAGS = $(GENFLAGS) -DVERBOSE
INCLUDES = -I./../include/common \
-I./../include/CMSIS

else ifeq ($(PLATFORM),HOST)
CC = gcc
CFLAGS = $(GENFLAGS) -DVERBOSE
INCLUDES:= -I./../include/common \
-I./../include/CMSIS

#added a make line to do unit testing
else ifeq ($(PLATFORM),CMOCKA)
CC = gcc
CFLAGS = $(GENFLAGS) -DVERBOSE
TARGET1 :=  unit_tests.elf
INCLUDES:= -I./../include/common \
-I./../include/CMSIS \
-I./../include/kl25z

#this will default to the native compiler
else 
CC= gcc
CFLAG = $(GENFLAGS) -DVERBOSE
CPPFLAGS = -DHOST
INCLUDES:= -I./../include/common \
-I./../include/CMSIS

endif	

#variables that are needed for the build

ifeq ($(PROJECT),PROJECT1)
CFLAGS += -DPROJECT1
else ifeq ($(PROJECT),PROJECT2)
CFLAGS += -DPROJECT2
else ifeq ($(PROJECT),BOARD)
CFLAGS += -DBOARD
endif

OBJS:= $(SRCS:.c=.o)
PREPRO:= $(SRCS:.c=.i)
ASM:= $(SRCS:.c=.s)
TARGET:= project1.elf
DEPFLAGS = #-MT -$@ -MMD -MP -MF $*.dep


#******************************************************************************
#**********Command "make build"*******************************************
.PHONY: build
build: clean $(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) -o $(TARGET)

#******************************************************************************
#**********Command "make build"*******************************************
.PHONY: build-test
build-test: clean $(TARGET1)
$(TARGET1):$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) -o $(TARGET1)


#**********Command "make clean"*******************************************
.PHONY: clean
clean: 
	rm -f *.o *.i *.s *.elf *.dep *.map

#**********Command "make size"*********************************************
.PHONY: size
size: 
	size $(OBJS) $(TARGET)

#**********Command "make upload_BBB"*********************************************
.PHONY: upload_BBB
upload_BBB: $(TARGET) LOAD

.PHONY: LOAD
LOAD: 
	sudo scp project1.elf root@192.168.7.2:/root/ecen5813_project_1
	
#*************Create only all dependency files**************************
.PHONY: deps
deps:$(DEPS)

$(DEPS):$(SRCS)
	$(CC) $(CFLAG) $(INCLUDES) $(LDFLAGS) $(SRCS) -M -o $(DEPS) 

#******This section will generate the assembly files*********************
memory.s:memory.c
	$(CC) $(CFLAGS) $(INCLUDES) memory.c -S -o memory.s

project1.s:project1.c
	$(CC) $(CFLAGS) $(INCLUDES) project1.c -S -o project1.s

project2.s:project2.c
	$(CC) $(CFLAGS) $(INCLUDES) project2.c -S -o project2.s

data1.s:data1.c
	$(CC) $(CFLAGS) $(INCLUDES) data1.c -S -o data1.s

debug.s:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) debug.c -S -o debug.s

conversion.s:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) conversion.S -c -o conversion.s

main.s:main.c
	$(CC) $(CFLAGS) $(INCLUDES) main.c -S -o main.s

arch_arm32.s:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) arch_arm32.c -S -o arch_arm32.s

gpio.s:gpio.c
	$(CC) $(CFLAGS) $(INCLUDES) gpio.c -S -o gpio.s

circbuf.s:circbuf.c
	$(CC) $(CFLAGS) $(INCLUDES) circbuf.c -S -o circbuf.s

uart.s:uart.c
	$(CC) $(CFLAGS) $(INCLUDES) uart.c -S -o uart.s

unit_tests.s:unit_tests.c
	$(CC) $(CFLAGS) $(INCLUDES) unit_tests.c -S -o unit_tests.s

#******This section will generate the preprocessed files*****************
memory.i:memory.c
	$(CC) $(CFLAGS) $(INCLUDES)  memory.c -E -o memory.i

project1.i:project1.c
	$(CC) $(CFLAGS) $(INCLUDES)  project1.c -E -o project1.i

project2.i:project2.c
	$(CC) $(CFLAGS) $(INCLUDES)  project2.c -E -o project2.i

data1.i:data1.c
	$(CC) $(CFLAGS) $(INCLUDES) data1.c -E -o data1.i 

debug.i:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) debug.c -E -o debug.i 

conversion.i:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) conversion.c -E -o conversion.i 

main.i:main.c
	$(CC) $(CFLAGS) $(INCLUDES) main.c -E -o main.i 

arch_arm32.i:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) arch_arm32.c -E -o arch_arm32.i 

gpio.i:gpio.c
	$(CC) $(CFLAGS) $(INCLUDES) gpio.c -E -o gpio.i

circbuf.i:circbuf.c
	$(CC) $(CFLAGS) $(INCLUDES) circbuf.c -E -o circbuf.i

uart.i:uart.c
	$(CC) $(CFLAGS) $(INCLUDES) uart.c -E -o uart.i

unit_tests.i:unit_tests.c
	$(CC) $(CFLAGS) $(INCLUDES) unit_tests.c -E -o unit_tests.i

#**********Command "make compile-all"*************************************
.PHONY: compile-all
compile-all: $(OBJS)
#*******Create only all object files*************************************
memory.o:memory.c
	$(CC) $(CFLAGS) $(INCLUDES) memory.c -c -o memory.o

project1.o:project1.c
	$(CC) $(CFLAGS) $(INCLUDES) project1.c -c -o project1.o

project2.o:project2.c
	$(CC) $(CFLAGS) $(INCLUDES) project2.c -c -o project2.o

data1.o:data1.c
	$(CC) $(CFLAGS) $(INCLUDES) data1.c -c -o data1.o

debug.o:debug.c
	$(CC) $(CFLAGS) $(INCLUDES) debug.c -c -o debug.o

conversion.o:conversion.c
	$(CC) $(CFLAGS) $(INCLUDES) conversion.c -c -o conversion.o

main.o:main.c
	$(CC) $(CFLAGS) $(INCLUDES) main.c -c -o main.o

arch_arm32.o:arch_arm32.c
	$(CC) $(CFLAGS) $(INCLUDES) arch_arm32.c -c -o arch_arm32.o

system_MKL25Z4.o:system_MKL25Z4.c
	$(CC) $(CFLAGS) $(INCLUDES) system_MKL25Z4.c -c -o system_MKL25Z4.o

startup_MKL25Z4.o:startup_MKL25Z4.S
	$(CC) $(CFLAGS) $(INCLUDES) startup_MKL25Z4.S -M -o startup_MKL25Z4.o

gpio.o:gpio.c
	$(CC) $(CFLAGS) $(INCLUDES) gpio.c -c -o gpio.o

circbuf.o:circbuf.c
	$(CC) $(CFLAGS) $(INCLUDES) circbuf.c -c -o circbuf.o

uart.o:uart.c
	$(CC) $(CFLAGS) $(INCLUDES) uart.c -c -o uart.o

unit_tests.o:unit_tests.c
	$(CC) $(CFLAGS) $(INCLUDES) unit_tests.c -c -o unit_tests.o

#**************************End of File************************************
#************************************************************************


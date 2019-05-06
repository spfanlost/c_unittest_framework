# CC=gcc
# CFLAGS=-g -W -Wall
# APP_NAME := test.run
# INCLUDE :=  
# SOURCES :=  main.c\
# 			ut_fw.c
# all: $(APP_NAME)
# $(APP_NAME): $(SOURCES)
# 	$(CC) $(CFLAGS) $(SOURCES) -o $(APP_NAME) $(LDFLAGS)
# clean:
# 	rm -f *.o
# 	rm -f $(APP_NAME)
# .PHONY: all clean

# CC=gcc
CC=clang
APP_NAME := test.run
INCLUDE := include
# INCLUDE := $(shell find ./ -name "*.h")
CFLAGS=-g -W -Wall
LDFLAGS= -I $(INCLUDE)
SRCDIR = ./source
SOURCES :=  $(shell find $(SRCDIR) -name "*.c")
all: $(APP_NAME)
$(APP_NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(APP_NAME) $(LDFLAGS)
clean:
	rm -f *.o
	rm -f $(APP_NAME)
.PHONY: all clean

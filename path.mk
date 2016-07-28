SHELL= /bin/bash
INCLUDES=	-I$(BUILD_DIR)/messages \
		-I$(BUILD_DIR)/messages/msgPool \
		-I$(BUILD_DIR)/utils \
		-I$(BUILD_DIR)/common \
		-I$(BUILD_DIR)/core

LIBRARIES=	-L$(BUILD_DIR)/lib \
		-L/usr/local/lib \
		-lCore -lMsgPool -lMsgs -lUtils -lCommon -lpthread 

CC=	g++
CFLAGS=	-O2 -fPIC -Wall -Wextra -Werror -std=c++11 -pedantic-errors
COMPILE= $(CC) $(CFLAGS)
AR=ar rcs
RM=rm -rf

LIB=$(BUILD_DIR)/lib
BIN=$(BUILD_DIR)/bin
MainFile=$(BUILD_DIR)/handlers/Main.cc

OBJDIR=	obj

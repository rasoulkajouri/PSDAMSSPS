#!/bin/bash
#Usage:
#make         # display help message
#make run     # to start compiling binary
#make prefire # check to make directories
#make clean   # remove ALL binaries and outputs

BASE = $(shell pwd)
.DEFAULT_GOAL := help

CC = mpic++ 
CFLAGS = -W -std=c++11 -O0 -c

INC := ./include/*.h
CPP := ./source
LIB := ./library/MD_V.a

FUNS := $(CPP)/*.cpp
OBJS := ./*.o

EXE := ./run

outputDir := ./output
inputDir := ./input
libDir := ./library
PRV := ./input/primaryValues

MKdir = mkdir 
TCH = touch 

MSG := "./input/primaryValues is empty!!! fill it"

run: fcompile
	@echo " Clearing old output files ..."
	@rm -fr $(outputDir)/*
	@echo " All rights, Package is ready to fire ..."

fcompile: liBuild
	@echo "Creating Package ..."
	@rm -f $(EXE)
	@$(CC) -o run $(INC) $(LIB)

liBuild: objects
	@echo " Building Functions ..."
	@rm -f $(LIB)
	@ar ruv $(LIB) $(OBJS)
	@ranlib $(LIB)
	@rm -f $(OBJS)

objects: prefire
	@echo " Compiling CPP functions ..."
	@$(CC) $(CFLAGS) $(FUNS)
	
prefire:
	@if [ ! -d "./library" ]; then $(MKdir) "./library"; fi
	@if [ ! -d "./output" ]; then $(MKdir)$(outputDir); fi
	@if [ ! -d "./input" ]; then $(MKdir)$(inputDir); $(TCH)$(PRV); echo $(MSG); fi 
	@echo " prefire completed ..."

clean:
	@rm -fr $(outputDir) $(LIB) $(libDir)
help:
	@echo " Hello user\n This is a makefile to compile and make necessary directories of the PSDAMSSPS."
	@echo " permissive commands are as the following:"
	@echo " make         # display help"
	@echo " make run     # to start compiling binaries"
	@echo " make prefire # check to make necessary directories"
	@echo " make clean   # remove ALL binaries and libraries and outputs"

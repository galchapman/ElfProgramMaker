CC = gcc
CCP = g++
LD = ld

FLAGS = -g
CFLAGS = $(FLAGS)
CPPFLAGS = $(FLAGS)

BUILD = build
SRC = src

all: main
	$(BUILD)/main

main: $(SRC)/main.c $(BUILD)/elflib.o
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^

$(BUILD)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CCP) $(CPPFLAGS) -c -o $@ $^

$(BUILD)/elflib.o: $(BUILD)/elf/program.o $(BUILD)/elf/program64.o $(BUILD)/elf/program32.o
	$(LD) $(FLAGS) -relocatable -o $@ $^


clean:
	rm -r $(BUILD)
	mkdir -p $(BUILD)
	mkdir -p $(BUILD)/elf
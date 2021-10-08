CC = gcc
CCP = g++
LD = ld

FLAGS = -g
CFLAGS = $(FLAGS)
CPPFLAGS = $(FLAGS)

BUILD = build
SRC = src

all: main targets
	$(BUILD)/main targets/bin/a

main: $(SRC)/main.c $(BUILD)/elflib.o
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^

$(BUILD)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CCP) $(CPPFLAGS) -c -o $@ $^

$(BUILD)/elflib.o: $(BUILD)/elf/program.o $(BUILD)/elf/program64.o $(BUILD)/elf/program32.o
	$(LD) $(FLAGS) -relocatable -o $@ $^


targets/bin/:
	mkdir -p $@

targets: targets/bin/ targets/bin/a targets/bin/b

targets/bin/a:
	gcc -c -o targets/bin/a targets/a.c
targets/bin/b:
	gcc -o targets/bin/b targets/a.c

clean:
	rm -r $(BUILD)
	mkdir -p $(BUILD)
	mkdir -p $(BUILD)/elf
#ifndef ELF_PROGRAM_H
#define ELF_PROGRAM_H

#include "program.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef union _program Program;

Program* load(FILE* file);
void freeProgram(Program*);

// Elf common header functions
// getters
uint8_t getClass(const Program*);
uint8_t getData(const Program*);
uint8_t getElfVersion(const Program*);
uint8_t getOSABI(const Program*);
uint8_t getABIVERSION(const Program*);
uint16_t getType(const Program*);
uint16_t getMachine(const Program*);
uint16_t getVersione(const Program*);
// checks
bool checkMagic(const Program*);
bool checkElfVersion(const Program*);
// setters
void setType(Program*, uint16_t);
void setMachine(Program*, uint16_t);

#endif // !ELF_PROGRAM_H
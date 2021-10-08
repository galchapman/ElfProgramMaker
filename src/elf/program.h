#ifndef ELF_PROGRAM_H
#define ELF_PROGRAM_H

#include "program.h"
#include <stdio.h>

typedef union _program Program;

Program* load(FILE* file);
void freeProgram(Program*);

// Elf header functions
int checkMagic(const Program*);
int checkClass(const Program*);


#endif // !ELF_PROGRAM_H
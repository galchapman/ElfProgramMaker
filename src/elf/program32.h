#ifndef ELF32_PROGRAM_H
#define ELF32_PROGRAM_H

#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

struct Elf32_Program{
	Elf32_Ehdr header;
};

void loadProgram32(FILE*, struct Elf32_Program*);
void freeProgram32(struct Elf32_Program);

#endif //!ELF32_PROGRAM_H
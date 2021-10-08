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

// header functions
Elf32_Addr get_entry32(const struct Elf32_Program*); 
Elf32_Off get_phoff32(const struct Elf32_Program*); 
Elf32_Off get_shoff32(const struct Elf32_Program*);

#endif //!ELF32_PROGRAM_H
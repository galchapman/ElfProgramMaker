#ifndef ELF64_PROGRAM_H
#define ELF64_PROGRAM_H

#include <elf.h>
#include <stdlib.h>

struct Elf64_Program{
	Elf64_Ehdr header;
};

void freeProgram64(struct Elf64_Program);

#endif //!ELF64_PROGRAM_H
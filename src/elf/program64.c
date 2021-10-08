#include "program64.h"

void loadProgram64(FILE* stream, struct Elf64_Program* program) {
	fread((char*)&program->header + 0x10, sizeof(Elf64_Ehdr) - 0x10, 1, stream);
}

void freeProgram64(struct Elf64_Program program) {}
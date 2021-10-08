#include "program32.h"

void loadProgram32(FILE* stream, struct Elf32_Program* program) {
	fread((char*)&program->header + 0x10, sizeof(Elf32_Ehdr) - 0x10, 1, stream);
}

void freeProgram32(struct Elf32_Program program) {}
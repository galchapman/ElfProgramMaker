#include "program32.h"

void loadProgram32(FILE* stream, struct Elf32_Program* program) {
	fread((char*)&program->header + 0x10, sizeof(Elf32_Ehdr) - 0x10, 1, stream);
}

void freeProgram32(struct Elf32_Program program) {}

// header functions
Elf32_Addr get_entry32(const struct Elf32_Program* program) {
	return program->header.e_entry;
}

Elf32_Off get_phoff32(const struct Elf32_Program* program) {
	return program->header.e_phoff;
}

Elf32_Off get_shoff32(const struct Elf32_Program* program) {
	return program->header.e_shoff;
}
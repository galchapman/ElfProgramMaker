#include "program64.h"

void loadProgram64(FILE* stream, struct Elf64_Program* program) {
	fread((char*)&program->header + 0x10, sizeof(Elf64_Ehdr) - 0x10, 1, stream);
}

void freeProgram64(struct Elf64_Program program) {}

// header functions
Elf64_Addr get_entry64(const struct Elf64_Program* program) {
	return program->header.e_entry;
}

Elf64_Off get_phoff64(const struct Elf64_Program* program) {
	return program->header.e_phoff;
}

Elf64_Off get_shoff64(const struct Elf64_Program* program) {
	return program->header.e_shoff;
}
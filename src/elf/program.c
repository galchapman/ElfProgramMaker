#include "program.h"

#include <stdlib.h>
#include <string.h>

#include "program32.h"
#include "program64.h"

union _program
{
	struct Elf32_Program x32;
	struct Elf64_Program x64;

	/*
	A strcut for the common fields between 32 and 64 bits elf headers
	*/
	struct {
		unsigned char	e_ident[EI_NIDENT];	/* Magic number and other info */
		Elf32_Half		e_type;				/* Object file type */
		Elf32_Half		e_machine;			/* Architecture */
		Elf32_Word		e_version;			/* Object file version */
	} common;
};

void freeProgram(Program* program) {
	switch (checkClass(program)) {
	case ELFCLASSNONE:
		break;
	case ELFCLASS32:
		freeProgram32(program->x32);
	case ELFCLASS64:
		freeProgram64(program->x64);
	case ELFCLASSNUM:
	default:
		break;
	};
	free(program);
}

int checkMagic(const Program* program) {
	return memcmp(program->common.e_ident, ELFMAG, SELFMAG);
}

int checkClass(const Program* program) {
	return program->common.e_ident[EI_CLASS] == ELFCLASS32;
}
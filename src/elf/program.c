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
	switch (getClass(program)) {
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
// Elf Common Header
uint8_t getClass(const Program* program) {
	return program->common.e_ident[EI_CLASS];
}

uint8_t getData(const Program* program) {
	return program->common.e_ident[EI_DATA];
}

uint8_t getElfVersion(const Program* program) {
	return program->common.e_ident[EI_VERSION];
}

uint8_t getOSABI(const Program* program) {
	return program->common.e_ident[EI_OSABI];
}

uint8_t getABIVERSION(const Program* program) {
	return program->common.e_ident[EI_ABIVERSION];
}

uint16_t getType(const Program* program) {
	return program->common.e_type;
}

uint16_t getMachine(const Program* program) {
	return program->common.e_machine;
}

uint16_t getVersion(const Program* program) {
	return program->common.e_machine;
}

bool checkMagic(const Program* program) {
	return memcmp(program->common.e_ident, ELFMAG, SELFMAG) == 0;
}

bool checkElfVersion(const Program* program) {
	return program->common.e_ident[EI_VERSION] == EV_CURRENT;
}

void setType(Program* program, uint16_t e_type) {
	program->common.e_type = e_type;
}

void setMachine(Program* program, uint16_t e_machine) {
	program->common.e_machine = e_machine;
}
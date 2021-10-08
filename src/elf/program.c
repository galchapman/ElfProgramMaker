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

Program* loadProgrqam(FILE* file) {
	Program* program = (Program*)malloc(sizeof(Program));
	fread(program, sizeof(program->common), 1, file);
	switch (get_class(program)) {
	case ELFCLASS32:
		loadProgram32(file, &program->x32);
		break;
	case ELFCLASS64:
		loadProgram64(file, &program->x64);
		break;
	default:
		break;
	}
	return program; 
}

void freeProgram(Program* program) {
	switch (get_class(program)) {
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
const char* get_magic(const Program* program) {
	return (const char*)program->common.e_ident;
}

Half get_class(const Program* program) {
	return program->common.e_ident[EI_CLASS];
}

Half get_data(const Program* program) {
	return program->common.e_ident[EI_DATA];
}

Half get_ElfVersion(const Program* program) {
	return program->common.e_ident[EI_VERSION];
}

Half get_OSABI(const Program* program) {
	return program->common.e_ident[EI_OSABI];
}

Half get_ABIVERSION(const Program* program) {
	return program->common.e_ident[EI_ABIVERSION];
}

Word get_Flags(const Program* program) {
	return get_class(program) == ELFCLASS32 ? program->x32.header.e_flags : program->x64.header.e_flags;
}

Half get_ehsize(const Program* program) {
	return get_class(program) == ELFCLASS32 ? program->x32.header.e_ehsize : program->x64.header.e_ehsize;
}

Half get_phentsize(const Program* program) {
	return get_class(program) == ELFCLASS32 ? program->x32.header.e_phentsize : program->x64.header.e_phentsize;
}

Half get_phnum(const Program* program) {
	return get_class(program) == ELFCLASS32 ? program->x32.header.e_phnum : program->x64.header.e_phnum;
}

Half get_shentsize(const Program* program) {
	return get_class(program) == ELFCLASS32 ? program->x32.header.e_shentsize : program->x64.header.e_shentsize;
}

Half get_shnum(const Program* program) {
	return get_class(program) == ELFCLASS32 ? program->x32.header.e_shnum : program->x64.header.e_shnum;
}

Half get_shstrndx(const Program* program) {
	return get_class(program) == ELFCLASS32 ? program->x32.header.e_shstrndx : program->x64.header.e_shstrndx;
}

Word get_type(const Program* program) {
	return program->common.e_type;
}

Word get_machine(const Program* program) {
	return program->common.e_machine;
}

Word get_version(const Program* program) {
	return program->common.e_machine;
}

bool check_magic(const Program* program) {
	return memcmp(program->common.e_ident, ELFMAG, SELFMAG) == 0;
}

bool check_ElfVersion(const Program* program) {
	return program->common.e_ident[EI_VERSION] == EV_CURRENT;
}

void set_type(Program* program, Word e_type) {
	program->common.e_type = e_type;
}

void set_machine(Program* program, Word e_machine) {
	program->common.e_machine = e_machine;
}

#define SET_HEADER(field) \
if (get_class(program) == ELFCLASS32) { \
	program->x32.header.field = field; \
} else { \
	program->x64.header.field = field; \
}

#define SETTER(field, t) \
void set_##field(Program* program, t e_##field) { \
	SET_HEADER(e_##field) \
}

SETTER(flags, Word)
SETTER(ehsize, Half)
SETTER(phentsize, Half)
SETTER(phnum, Half)
SETTER(shentsize, Half)
SETTER(shnum, Half)
SETTER(shstrndx, Half)

#undef SET_HEADER
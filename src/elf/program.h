#ifndef ELF_PROGRAM_H
#define ELF_PROGRAM_H

#include "program.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef union _program Program;

typedef uint16_t Word;
typedef uint8_t Half;

Program* loadProgrqam(FILE* file);
void freeProgram(Program*);

// Elf common header functions
// getters
const char* get_magic(const Program*);
Half get_class(const Program*);
Half get_data(const Program*);
Half get_elfVersion(const Program*);
Half get_OSABI(const Program*);
Half get_ABIVERSION(const Program*);
Word get_type(const Program*);
Word get_machine(const Program*);
Word get_versione(const Program*);
Word get_flags(const Program*);
Half get_ehsize(const Program*);
Half get_phentsize(const Program*);
Half get_phnum(const Program*);
Half get_shentsize(const Program*);
Half get_shnum(const Program*);
Half get_shstrndx(const Program*);
// checks
bool check_magic(const Program*);
bool check_ElfVersion(const Program*);
// setters
void set_type(Program*, Word);
void set_machine(Program*, Word);
void set_version(Program*, Word);
void set_flags(Program*, Word);
void set_ehsize(Program*, Half);
void set_phentsize(Program*, Half);
void set_phnum(Program*, Half);
void set_shentsize(Program*, Half);
void set_shnum(Program*, Half);
void set_shstrndx(Program*, Half);

#endif // !ELF_PROGRAM_H
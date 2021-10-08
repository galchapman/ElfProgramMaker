#ifndef ELF64_PROGRAM_H
#define ELF64_PROGRAM_H

#include <elf.h>
#include <stdio.h>
#include <stdlib.h>


// Program header value
typedef union {
	void* raw;
	char* string;
} Elf64_Phdr_Value;

// Section value
typedef union {
	// default value (SHT_PROGBITS)
	void* raw;
	char* string;
	// SHT_SYMTAB
	Elf64_Sym* symbols;
	// SHT_REL
	Elf64_Rel* rels;
	// SHT_RELA
	Elf64_Rela* relas;
} Elf64_SectionValue;

/*
to view arrays in gdb add
*(Elf64_Phdr(*)[program->x64.header.phnum])program->x64.program_headers
*/
struct Elf64_Program{
	Elf64_Ehdr header;
	Elf64_Phdr* program_headers;
	Elf64_Phdr_Value* phdr_Values;
	Elf64_Shdr* sections;
	Elf64_SectionValue* shdr_values;
};

void loadProgram64(FILE*, struct Elf64_Program*);
void freeProgram64(struct Elf64_Program);

// header functions
Elf64_Addr get_entry64(const struct Elf64_Program*); 
Elf64_Off get_phoff64(const struct Elf64_Program*); 
Elf64_Off get_shoff64(const struct Elf64_Program*);

#endif //!ELF64_PROGRAM_H
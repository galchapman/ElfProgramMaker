#include <stdio.h>
#include <elf.h>
#include "elf/program.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, ERROR_RED("Usage: %s <target>") , argv[0]);
		return 1;
	}

	FILE* pf = fopen("targets/bin/a", "rb");
	Program* program = loadProgrqam(pf);
	fclose(pf);

	freeProgram(program);
	return 0;
}
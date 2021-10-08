#include <stdio.h>
#include <elf.h>
#include "elf/program.h"

#define COLOR_RED(s) "\033[91m" s "\033[0m"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(stderr, COLOR_RED("Usage: %s <target>") , argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; i++) {

		FILE* pf = fopen(argv[i], "rb");
		Program* program = loadProgrqam(pf);
		fclose(pf);

		freeProgram(program);
	}
	return 0;
}
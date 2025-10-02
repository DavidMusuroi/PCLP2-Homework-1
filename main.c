#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i = 0, caz, jump_fwd = 0, loops = 0;
	char sir[101], registru;
	while (fgets(sir, sizeof(sir), stdin)) {
		caz = -1;
		if (sir[0] == '}' && loops == 0) {
			printf("end_label:");
		} else if (sir[0] == '}' && loops == 1) {
			printf("JMP start_loop\n");
			printf("end_label:");
		} else if (sir[0] == '}' && loops == 2) {
			printf("ADD e%cx, 1\n", registru);
			printf("JMP start_loop\n");
			printf("end_loop:");
		} else if (sir[1] == 'f') {
			printf("CMP ");
			caz = 5;
			jump_fwd = 1;
		} else if (sir[1] == 'h') {
			printf("start_loop:\n");
			printf("CMP ");
			loops = 1;
			caz = 6;
			jump_fwd = 1;
		} else if (sir[1] == 'o') {
			printf("MOV ");
			loops = 2;
			jump_fwd = 1;
			if (sir[5] == 'a') {
				printf("eax, ");
				registru = 'a';
			} else if (sir[5] == 'b') {
				printf("ebx, ");
				registru = 'b';
			} else if (sir[5] == 'c') {
				printf("ecx, ");
				registru = 'c';
			} else if (sir[5] == 'd') {
				printf("edx, ");
				registru = 'd';
			}
			printf("0\n");
			printf("start_loop:\nCMP ");
			if (sir[5] == 'a')
				printf("eax, ");
			else if (sir[5] == 'b')
				printf("ebx, ");
			else if (sir[5] == 'c')
				printf("ecx, ");
			else if (sir[5] == 'd')
				printf("edx, ");
			if (sir[15] == ' ')
				for (i = 16; sir[i] != ';'; i++)
					printf("%c", sir[i]);
			else
				for (i = 17; sir[i] != ';'; i++)
					printf("%c", sir[i]);
			printf("\n");
			if (sir[14] == '>' && sir[15] == ' ')
				printf("JLE end_label");
			else if (sir[14] == '<' && sir[15] == ' ')
				printf("JGE end_label");
			else if (sir[14] == '>' && sir[15] == '=')
				printf("JL end_label");
			else if (sir[14] == '<' && sir[15] == '=')
				printf("JG end_label");
			else if (sir[14] == '=' && sir[15] == '=')
				printf("JNE end_label");
		} else if (sir[2 + jump_fwd] == '=') {
			if (sir[6 + jump_fwd] == '^') {
				printf("XOR ");
				caz = 1;
			} else if (sir[6 + jump_fwd] == '|') {
				printf("OR ");
				caz = 1;
			} else if (sir[6 + jump_fwd] == '&') {
				printf("AND ");
				caz = 1;
			} else if (sir[6 + jump_fwd] == '+') {
				printf("ADD ");
				caz = 2;
			} else if (sir[6 + jump_fwd] == '-') {
				printf("SUB ");
				caz = 2;
			} else if (sir[6 + jump_fwd] == '/' && sir[8 + jump_fwd] == '0') {
				printf("Error");
			} else if (sir[6 + jump_fwd] == '*' || sir[6 + jump_fwd] == '/') {
				caz = 3;
			} else if (sir[6 + jump_fwd] == '>') {
				printf("SHR ");
				caz = 4;
			} else if (sir[6 + jump_fwd] == '<') {
				printf("SHL ");
				caz = 4;
			} else {
				caz = 0;
				printf("MOV ");
			}
		}
		if (caz == 0) {
			if (sir[0 + jump_fwd] == 'a')
				printf("eax, ");
			else if (sir[0 + jump_fwd] == 'b')
				printf("ebx, ");
			else if (sir[0 + jump_fwd] == 'c')
				printf("ecx, ");
			else if (sir[0 + jump_fwd] == 'd')
				printf("edx, ");
			if (sir[4 + jump_fwd] == 'a')
				printf("eax");
			else if (sir[4 + jump_fwd] == 'b')
				printf("ebx");
			else if (sir[4 + jump_fwd] == 'c')
				printf("ecx");
			else if (sir[4 + jump_fwd] == 'd')
				printf("edx");
			else
				for (i = 4 + jump_fwd; sir[i + 2] != '\0'; i++)
					printf("%c", sir[i]);
		} else if (caz == 1 || caz == 2) {
			if (sir[0 + jump_fwd] == 'a')
				printf("eax, ");
			else if (sir[0 + jump_fwd] == 'b')
				printf("ebx, ");
			else if (sir[0 + jump_fwd] == 'c')
				printf("ecx, ");
			else if (sir[0 + jump_fwd] == 'd')
				printf("edx, ");
			if (sir[8 + jump_fwd] == 'a') {
				printf("eax");
			} else if (sir[8 + jump_fwd] == 'b') {
				printf("ebx");
			} else if (sir[8 + jump_fwd] == 'c') {
				printf("ecx");
			} else if (sir[8 + jump_fwd] == 'd') {
				printf("edx");
			} else {
				for (i = 8 + jump_fwd; sir[i + 2] != '\0'; i++)
					printf("%c", sir[i]);
			}
		} else if (caz == 3 && sir[0 + jump_fwd] != 'a') {
			printf("MOV eax, ");
			if (sir[0 + jump_fwd] == 'b')
				printf("ebx");
			else if (sir[0 + jump_fwd] == 'c')
				printf("ecx");
			else if (sir[0 + jump_fwd] == 'd')
				printf("edx");
			if (sir[6 + jump_fwd] == '*')
				printf("\nMUL ");
			else if (sir[6 + jump_fwd] == '/')
				printf("\nDIV ");
			if (sir[8 + jump_fwd] == 'a') {
				printf("eax");
			} else if (sir[8 + jump_fwd] == 'b') {
				printf("ebx");
			} else if (sir[8 + jump_fwd] == 'c') {
				printf("ecx");
			} else if (sir[8 + jump_fwd] == 'd') {
				printf("edx");
			} else {
				for (i = 8 + jump_fwd; sir[i + 2] != '\0'; i++)
					printf("%c", sir[i]);
			}
			printf("\nMOV ");
			if (sir[0 + jump_fwd] == 'b')
				printf("ebx, ");
			else if (sir[0 + jump_fwd] == 'c')
				printf("ecx, ");
			else if (sir[0 + jump_fwd] == 'd')
				printf("edx, ");
			printf("eax");
		} else if (caz == 3 && sir[0 + jump_fwd] == 'a') {
			if (sir[6 + jump_fwd] == '*')
				printf("MUL ");
			else if (sir[6 + jump_fwd] == '/')
				printf("DIV ");
			if (sir[8 + jump_fwd] == 'a') {
				printf("eax");
			} else if (sir[8 + jump_fwd] == 'b') {
				printf("eb");
			} else if (sir[8 + jump_fwd] == 'c') {
				printf("ecx");
			} else if (sir[8 + jump_fwd] == 'd') {
				printf("edx");
			} else {
				for (i = 8 + jump_fwd; sir[i + 2] != '\0'; i++)
					printf("%c", sir[i]);
			}
		} else if (caz == 4) {
			if (sir[0 + jump_fwd] == 'a')
				printf("eax, ");
			else if (sir[0 + jump_fwd] == 'b')
				printf("ebx, ");
			else if (sir[0 + jump_fwd] == 'c')
				printf("ecx, ");
			else if (sir[0 + jump_fwd] == 'd')
				printf("edx, ");
			for (i = 9 + jump_fwd; sir[i + 2] != '\0'; i++)
				printf("%c", sir[i]);
		} else if (caz == 5) {
			if (sir[4] == 'a')
				printf("eax, ");
			else if (sir[4] == 'b')
				printf("ebx, ");
			else if (sir[4] == 'c')
				printf("ecx, ");
			else if (sir[4] == 'd')
				printf("edx, ");
			if (sir[7] == ' ')
				for (i = 8; sir[i] != ')'; i++)
					printf("%c", sir[i]);
			else
				for (i = 9; sir[i] != ')'; i++)
					printf("%c", sir[i]);
			printf("\n");
			if (sir[6] == '>' && sir[7] == ' ')
				printf("JLE end_label");
			else if (sir[6] == '<' && sir[7] == ' ')
				printf("JGE end_label");
			else if (sir[6] == '>' && sir[7] == '=')
				printf("JL end_label");
			else if (sir[6] == '<' && sir[7] == '=')
				printf("JG end_label");
			else if (sir[6] == '=' && sir[7] == '=')
				printf("JNE end_label");
		} else if (caz == 6) {
			if (sir[7] == 'a')
				printf("eax, ");
			else if (sir[7] == 'b')
				printf("ebx, ");
			else if (sir[7] == 'c')
				printf("ecx, ");
			else if (sir[7] == 'd')
				printf("edx, ");
			if (sir[10] == ' ')
				for (i = 11; sir[i] != ')'; i++)
					printf("%c", sir[i]);
			else
				for (i = 12; sir[i] != ')'; i++)
					printf("%c", sir[i]);
			printf("\n");
			if (sir[9] == '>' && sir[10] == ' ')
				printf("JLE end_label");
			else if (sir[9] == '<' && sir[10] == ' ')
				printf("JGE end_label");
			else if (sir[9] == '>' && sir[10] == '=')
				printf("JL end_label");
			else if (sir[9] == '<' && sir[10] == '=')
				printf("JG end_label");
			else if (sir[9] == '=' && sir[10] == '=')
				printf("JNE end_label");
		}
		printf("\n");
	}
	return 0;
}

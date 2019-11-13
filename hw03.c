#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
	NAME_ONLY = 0,
	MAJOR_AND_NAME = 1,
	YEAR_AND_NAME = 2
} Mode;

typedef struct {
	char *first_name;
	char *last_name;
	char *major;
	int year;

} Student;

void print_student(Mode m, Student s) {
	switch (m) {
		case NAME_ONLY:
			printf("%s %s\n", s.first_name, s.last_name);
			break;
		case MAJOR_AND_NAME:
			printf("%s %s %s\n", s.major, s.first_name, s.last_name);
			break;
		case YEAR_AND_NAME:
			printf("%d %s %s\n", s.year, s.first_name, s.last_name);
			break;
	}
}


int main(int argc, char **argv) {

int mode = atoi(argv[1]);

for(int b=2; b < argc; b+=4)
{
	Student s;
	s.first_name = argv[b];
	s.last_name = argv[b+1];
	s.major = argv[b+2];
	s.year = atoi(argv[b+3]);
	print_student(mode, s);
}

	return 0;
}
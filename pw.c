#include "pw.h"

int main (int args, char *argv[]) {
	//define variables
	char line[15];
	int length, error;

	//code

	length = 0;

	if(args >= 2) {
		printf("error at input to many arguments \n");
		return -1;
	}

	printf("max number is 2^32 -1 \n ");
	fgets(line, sizeof(line), stdin);

	error = sscanf(line, "%d", &length);

	if (error == -1) {
		printf("error at input");
	}

	working(length);
}

void working(int length) {
	//define variables
	int i;
	char toOut[length + 1];

	//code
	for(i = 0; i < length; i++) {
		toOut[i] = randomCharacter();
	}

	toOut[length] = (char) 0;

	printf("\n %s \n", toOut);
}

char randomCharacter() {
	//define variables
	int cache;
	int found;

	//code
	found = 0;
	while(found == 0) {
		srand(clock());
		cache = rand();
		cache = cache % 128;
		if (cache > 33 && cache < 94) {
			found = 1;
		}
		if (cache > 96 && cache < 126) {
			found = 1;
		}
	}

	return (char) cache;
}

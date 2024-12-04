#include <stdio.h>
#include <stdlib.h>
#include "../src/randgen.cpp"

#define SIZE 4096

int main(int argc, char **argv)
{
	int PULL;
	PULL = strtol(argv[1], NULL, 10);
	char  data[PULL][SIZE];
	int err;
	
	for(int i = 0; i < PULL; i++){
		err = generate_randnum(data[i], SIZE);
		printf("%d\n", i);
		if(err != 0){
			printf("Error\n");
			return 2;
		}
	}
	
	FILE* ff;
	
	ff = fopen("numbers.txt","wb");
	for(int i = 0; i < PULL; i++){
		fwrite(data[i], (size_t) SIZE*8, 1, ff);
		fprintf(ff, "\n");
	}
	fclose(ff);
	return 0;
}


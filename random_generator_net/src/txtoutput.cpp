#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "structs.h"

#define BITFILE

int main(int argc, char **argv)
{
	int PULL;
	PULL = strtol(argv[1], NULL, 10);
	char  data[PULL][SIZE];
	int err;
	
	for(int i = 0; i < PULL; i++){
		err = generate_randnum(data[i], SIZE);
		printf("%d\n", i);
		//printf("%c\n", data[i][0]);
		if(err != 0){
			printf("Error\n");
			return 2;
		}
	}
	unsigned long long int* a;
	FILE* ff;
	#ifdef BITFILE
		ff = fopen("bitnumber","wb");
		for(int i = 0; i < PULL; i++){
			fwrite(data[i], sizeof(char), SIZE, ff);
		}
		fclose(ff);
	#endif
	#ifndef BITFILE
		ff = fopen("numbers.txt","w");
		for(int i = 0; i < PULL; i++){
			a = (unsigned long long int*) data[i];
			fprintf(ff, "%lld\n", *a);
		}
		fclose(ff);
	#endif
	return 0;
}


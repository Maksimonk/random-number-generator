#include <stdio.h>
#include <stdlib.h>
#include "../src/randgen.cpp"

#define SIZE 8

int main(int argc, char **argv)
{
	int PULL;
	PULL = strtol(argv[1], NULL, 10);
	char  data[PULL][SIZE];
	int err;
	
	for(int i = 0; i < PULL; i++){
		err = generate_randnum(data[i], SIZE);
		if(err != 0){
			printf("Error\n");
			return 2;
		}
	}
	
	FILE* ff;
	
	ff = fopen("numbers.txt","w");
	for(int i = 0; i < PULL; i++){
		for(int j = 0; j < SIZE; j++){
			for (int k = 0; k < 8; k++)
			{
				if (data[i][j] & 0x80)
					fprintf(ff, "1");
				else
					fprintf(ff, "0");
				data[i][j] = data[i][j] << 1;
			}
		}
	}
	fclose(ff);
	return 0;
}


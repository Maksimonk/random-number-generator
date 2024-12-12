#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "structs.h"

//#define BITFILE

int main(int argc, char **argv)
{
	int PULL;
	PULL = strtol(argv[1], NULL, 10);
	std::string data[PULL];
	int err;
	
	for(int i = 0; i < PULL; i++){
		data[i] = generate_randnum();
		printf("%d\n", i);
		//printf("%c\n", data[i][0]);
		if(err != 0){
			printf("Error\n");
			return 2;
		}
	}
	unsigned long long int* a;
	FILE* ff;
	ff = fopen("bitnumbers.txt","w");
	for(int i = 0; i < PULL; i++){
		for(int j = 0; j < 64; j++){
			switch(data[i][j])
			{
				case '0': 
					fprintf(ff, "0000");
					break;
				case '1': 
					fprintf(ff, "0001");
					break;
				case '2': 
					fprintf(ff, "0010");
					break;
				case '3': 
					fprintf(ff, "0011");
					break;
				case '4': 
					fprintf(ff, "0100");
					break;
				case '5': 
					fprintf(ff, "0101");
					break;
				case '6': 
					fprintf(ff, "0110");
					break;
				case '7': 
					fprintf(ff, "0111");
					break;
				case '8': 
					fprintf(ff, "1000");
					break;
				case '9': 
					fprintf(ff, "1001");
					break;
				case 'a': 
					fprintf(ff, "1010");
					break;
				case 'b': 
					fprintf(ff, "1011");
					break;
				case 'c': 
					fprintf(ff, "1100");
					break;
				case 'd': 
					fprintf(ff, "1101");
					break;
				case 'e': 
					fprintf(ff, "1110");
					break;
				case 'f': 
					fprintf(ff, "1111");
					break;
			}
		}
		fprintf(ff, "\n");
	}
	fclose(ff);
	ff = fopen("numbers.txt","w");
	for(int i = 0; i < PULL; i++){
		fprintf(ff, "%s\n", data[i].c_str());
	}
	fclose(ff);
	return 0;
}


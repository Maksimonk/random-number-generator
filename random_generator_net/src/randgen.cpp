#include "defines.h"
#include "structs.h"
#include <random>

char gen(int a, int iter)
{
	for(int i = 0; i < iter; i++){
		return (char) (a * 127 + 57);
	}
}

int generate_randnum(char* ptr,const int lenght)
{
	std::string buffer;
	std::string mem = "";
	int err;
	int n = 0;
	while(n < lenght){
		err = sniff_packet(&buffer);
		if(err == 4){
			return 2;
		}
		if(err == 0){
			mem = mem + buffer;
			n += buffer.size();
		}
	}
	//printf("%s\n", mem.c_str());
	mem.resize((size_t) lenght);
	mem.copy(ptr, lenght);
	
	for(int i = 0; i < lenght; i++){
		ptr[i] = gen((int) ptr[i], i);
	}
	//printf("%s\n", ptr);
	return 0;
}


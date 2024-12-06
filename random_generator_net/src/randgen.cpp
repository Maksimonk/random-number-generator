#include "defines.h"
#include "structs.h"
#include <random>

char gen(int a)
{
	std::mt19937 gen(a);
	std::uniform_int_distribution<> distr(0, 255);
	return (char) distr(gen);
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
		ptr[i] = gen((int) ptr[i]);
	}
	//printf("%s\n", ptr);
	return 0;
}


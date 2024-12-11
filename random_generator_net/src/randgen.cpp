#include "defines.h"
#include "structs.h"
#include <random>
#include "sha256.h"

#define LEN 64

std::string generate_randnum()
{
	std::string buffer;
	std::string mem = "";
	int err;
	int n = 0;
	while(n < LEN){
		err = sniff_packet(&buffer);
		/*if(err == 4){
			return 2;
		}*/
		if(err == 0){
			mem = mem + buffer;
			n += buffer.size();
		}
	}
	//printf("%s\n", mem.c_str());
	mem.resize((size_t) LEN);
	
	return sha256(mem);
	//mem.copy(ptr, LEN);
	//printf("%s\n", ptr);
	return 0;
}


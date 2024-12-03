#include "../src/sniffer_linux.cpp"



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
			//printf("%s\n", buffer.c_str());
			mem = mem + buffer;
			// printf("%ld\n", buffer.size());
			n += buffer.size();
		}
	}
	
	mem.resize((size_t) lenght);
	mem.copy(ptr, lenght);
	return 0;
}


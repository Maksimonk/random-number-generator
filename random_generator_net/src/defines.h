

#include <stdio.h>
#include <pcap.h>
#include <cstring>
#include <string>

#define SIZE 8
#define BUFFSIZE 3000

int sniff_packet(std::string* result);

std::string generate_randnum();

#define SIZE_ETHERNET 14

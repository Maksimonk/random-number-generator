

#include <stdio.h>
#include <pcap.h>
#include <cstring>
#include <string>

#define SIZE 10
#define BUFFSIZE 3000

int sniff_packet(std::string* result);

#define SIZE_ETHERNET 14

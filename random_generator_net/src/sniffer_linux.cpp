/* Прослушка первого попавшегося интерфейса и вывод его содержимого */

#include "defines.h"
#include "structs.h"

int sniff_packet(std::string* result)
{
	char *dev, errbuf[PCAP_ERRBUF_SIZE];
	struct pcap_pkthdr header;
	const u_char *packet;

  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) 
  {
  	fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
  	return(4);
  }
  //printf("Device: %s\n", dev);
  pcap_t *handle;

	handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
	if (handle == NULL) 
	{
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return(4);
	}
	packet = pcap_next(handle, &header);
	
  /* Вывод его длины */
  //printf("Jacked a packet with length of [%d]\n", header.len);
  
  /*  */
  const struct sniff_ethernet *ethernet; /* Заголовок Ethernet */
	const struct sniff_ip *ip; /* Заголовок IP */
	const struct sniff_tcp *tcp; /* Заголовок TCP */
	/*std::string*/ char* payload; /* Данные пакета */

	u_int size_ip;
	u_int size_tcp;
    
  ethernet = (struct sniff_ethernet*)(packet);
	ip = (struct sniff_ip*)(packet + SIZE_ETHERNET);
	size_ip = IP_HL(ip)*4;
	if (size_ip < 20) {
    //printf("   * Invalid IP header length: %u bytes\n", size_ip);
    return 2;
	}
	tcp = (struct sniff_tcp*)(packet + SIZE_ETHERNET + size_ip);
	size_tcp = TH_OFF(tcp)*4;
	if (size_tcp < 20) {
    //printf("   * Invalid TCP header length: %u bytes\n", size_tcp);
    return 2;
	}
	payload = (char*) (packet + SIZE_ETHERNET + size_ip + size_tcp);
	int n = strlen(payload);
	result->assign(payload, payload + n);
  //printf("Data: %s\n", payload);
  pcap_close(handle);
  return(0);
}

#include <stdio.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";
int* count = 0;
int* list1 = 0;
int* list2 = 0;



void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

void copycodes(char * text_address, int * list_address, int * count_address) {

	//printf("%p (*val=%c)\n", text_address, *text_address);
	//text_address++;
	while(*text_address != 0) {

		char list_address = *text_address;
		text_address++;
		list_address++;
	}

	


	//int * list = list_adress;


	//laddar en byte från text_addressen -> det motsvarar det första som pekaren pekar på
	//sparar till list1_ adress
	//om pekaren i text1 inte är lika med ett
	// incrementerar adressen för text1 med 1 byte
	//icrementerar list1 med 4 bytes
	//laddar in count värdet i en variabel
	//ökar den variabeln med 1
	//sparar det värdet i adressen för count
	//loopa om
}

void work(){


	copycodes(text1, list1, count);
	

	//laddar in adress för text1, list1 och count i olika platser
	//hoppar till copycodes

}

int main(void){
  work();

  printf("\nlist1: ");
  printlist(list1);

}

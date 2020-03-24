#include <stdio.h>

char* text1 = "This is a string.";		//Vi vill kunna referera till varje enskild bokstav. "text1 blir automatiskt en pekare till första karaktären".
char* text2 = "Yet another thing.";
int count = 0;					//Här vill vi använda oss av en global variabel.
int list1[80];
int list2[80];



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

void copycodes(char * text_address, int * list_address, int * count_pointer) {

	while(*text_address != 0) {

		*list_address = *text_address;
		text_address++;
		list_address++;
		(*count_pointer)++;
	}


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


	copycodes(text1, list1, &count);
	copycodes(text2, list2, &count);
	

	//laddar in adress för text1, list1 och count i olika platser
	//hoppar till copycodes

}

int main(void){
  work();

  printf("\nlist1: ");
  printlist(list1);

  printf("\nlist2: ");
  printlist(list2);

  printf("Count: %d\n", count);

  endian_proof((char*) &count);
}

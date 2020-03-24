#include <stdio.h>

char* text1 = "This is a string.";	//Vi vill kunna referera till varje enskild bokstav. "text1 blir automatiskt en pekare till första karaktären".
char* text2 = "Yet another thing.";	
int count = 0;				//Global variabel
int list1[20];
int list2[20];



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

	//TOLKNING AV "copycodes" I ASSEMBLY

	//laddar en byte från text_addressen -> det motsvarar det första som pekaren pekar på
	//sparar till list1_ adress
	//om pekaren i text1 inte är lika med ett
	// incrementerar adressen för text1 med 1 byte
	//icrementerar list1 med 4 bytes
	//laddar in count värdet i en variabel
	//ökar den variabeln med 1
	//sparar det värdet i adressen för count
	//loopa om

void copycodes(char * text_pointer, int * list_pointer, int * count_pointer) {

	while(*text_pointer != 0) {

		*list_pointer = *text_pointer;		//Här utför vi motsvarigheten till "load word" och sedan "save word". Vi "load word" med differentiering 								*text_pointer samtidigt som vi "save word" med differentiering i "*list_pointer".
		text_pointer++;				//Flyttar pekaren till nästa karaktär. (assembly: $a0,$a0,1)
		list_pointer++;				//Flyttar pekaren till nästa lediga plats i listan. (assembly: $a1,$a1,4)
		(*count_pointer)++;			//Med samma princip som första raden i while loopen så inkrementerar vi "count_pointer".
	}
}

void work(){

	copycodes(text1, ^list1, &count);

	copycodes(text2, list2, &count);

}

int main(void){
  work();
	
  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);

}




//Questions for assignment 4

//text1 and text2 are already initialized as pointer variables to the character array. This means that by default text1 and text2 are already pointing to the first character in the character array.
//This means that we can just use these as pointer arguments in copycodes.

//Incrementing a pointer means that we can reach elements in a array just by moving the default pointer "n steps". 
//In the case of incrementing the ASCII pointer we are just referring to the next character the ASCII corresponds.
//In the case of incrementing the integer array we are referring to the next free spot in our list which in turn has space for 80 elements.
//In C we don't need to take in consideration that an integer requires a space of 4 bytes (word), meaning that we need to move 4 bytes in our list to fit the next instruction.

//The difference between incrementing "count" and a pointer is that we need to make sure that "count" diferentiates first and then we can correctly increment its value.
//Regarding pointers we just increment the pointer variable since it's the addresses we are after to increment.
//If we want to keep our "count" variable global, i.e. updated after the subfunctions, we need to save the new data outside the subfunctions. That is why we keep redirecting the count variabel with "&". Otherwise the new data will disappear after it exits a subfunction.

//Read row 42.


//Är inte säker men intel datorer ska tydligen läsa med Little-endian som första byte. Således från höger till vänster.
//Det spelar ingen större roll prestanda mässigt vilken man använder men det kan dock ge problem om en dator med Big-endian proceduren ska läsa något från en dator som har Little-endian proceduren.
//Big-endian = man läser från vänster till höger.
//Little-endian = man läser från höger till vänster.













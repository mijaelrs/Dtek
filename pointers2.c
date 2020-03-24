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

void copycodes() {
	char next_letter = *text1;	//spara värdet för det text1 pekar på

	int next = (int) next_letter;

	list1 = &next;			//låt list1 peka på next
	printf("innfffan");
	printf("%d", *list1);
	
	printf("efter");
	while (*list1 != 0) {
		text1++;
		list1++;

		counter = *count;	//hämtar värdet för pekaren count, sparar i variabeln counter
		counter++;		//inkrementerar värdet med 1
		count = &counter;	//låt vår pekare peka på adressen som counter är 
		printf("Kör igen!");		
		next_letter = *text1;	//spara värdet för det text1 pekar på
		next = (int) next_letter;
		list1 = &next;	
	}
	
}

void work() {
	copycodes();
}



int main(void){
	
  work();

  printf("\nlist1: ");
  printlist(list1);
  //printf("\nlist2: ");
  //printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}


#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>   
#define SIZETHREEROOMS 3
#define FILERANDOMNUMBER "myFile.txt"
#define MYHOTELFILE "MyHotel.bin"
#define BALCONIINDEX 1
#ifndef _HeaderGeneral
#define _HeaderGeneral


char setBitFromRight(unsigned char ch, int index, int value);
int getBitFromRight(unsigned char ch, int index);
int getNumOfBeds();
int getAnswerFromCustomer(int index);
void printRoomDetails(int index, int answer);
void encodingBits(void* a, int typeSize, char* fileName);
void printCharAsBinary(char ch);
void decodingBits(void* a, int typeSize, char* fileName);

#endif // !_HeaderGeneral
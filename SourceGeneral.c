#include "HeaderGeneral.h"

int getNumOfBeds() 
{
	int beds;
	printf("enter bed number");
	scanf("%d", &beds);
	return beds;
	
}

int getAnswerFromCustomer(int index) 
{
	int answer;
	switch (index)
	{
	case 0:
		printf("do the room have a pool view? n->0,yes->1\n");
		scanf("%d", &answer);
		break;

	case 1:
		printf("do the room have a balconi? n->0,yes->1\n");
		scanf("%d", &answer);
		break;
	case 2:
		printf("do the room have a teapot? n->0,yes->1\n");
		scanf("%d", &answer);
		break;
	case 3:
		printf("do the room have a free wifi? n->0,yes->1\n");
		scanf("%d", &answer);
		break;
	case 4:
		printf("do the room have a sofa? n->0,yes->1\n");
		scanf("%d", &answer);
		break;
	case 5:
		printf("do the room have a TV? n->0,yes->1\n");
		scanf("%d", &answer);
		break;
	case 6:
		printf("do the occupied ? n->0,yes->1\n");
		scanf("%d", &answer);
		break;
	}
	return answer;

}

void printRoomDetails(int index, int answer)
{
	
	switch (index)
	{
	case 0:
		if (answer == 0) 
			printf("the room doesnt have pool view\n");	
		else
			printf("the room have pool view\n");		
		break;

	case 1:
		if (answer == 0)
			printf("the room doesnt have a balconi\n");
		else
			printf("the room have a balconi\n");
		break;
	case 2:
		if (answer == 0)
			printf("the room doesnt have teapot\n");
		else
			printf("the room have teapot\n");
		break;
		
	case 3:
		if (answer == 0)
			printf("the room doesnt have free wifi\n");
		else
			printf("the room have free wifi\n");
		break;
		
	case 4:
		if (answer == 0)
			printf("the room doesnt have a sofa\n");
		else
			printf("the room have sofa\n");
		break;;
		
	case 5:
		if (answer == 0)
			printf("the room doesnt have TV\n");
		else
			printf("the room have TV\n");
		break;
	case 6:
		if (answer == 0)
			printf("the room free\n");
		else
			printf("the room is occupied\n");
		break;

	}

}

char setBitFromRight(unsigned char ch, int index, int value)
{
	unsigned char mask = 1; // 00000001
	unsigned char result;
	mask <<= index;

	if (value == 1)
	{
		result = ch | mask;
	}

	else
	{
		mask = ~mask;
		result = (ch & mask);
	}
	return result;

}

int getBitFromRight(unsigned char ch, int index)
{
	unsigned char mask = 1; // 00000001
	mask = mask << index;

	if ((ch & mask) == 0)
	{
		return 0;
	}

	else
	{
		return 1;
	}



}

void printCharAsBinary(char ch)
{
	int i;
	unsigned char temp;
	for (i = 0;i < 8;i++)
	{
		temp = ch << i;
		temp = temp >> 7;
		printf("%d", temp);
	}
	printf("\n");
}

void encodingBits(void* a, int typeSize,char* fileName)
{
	unsigned char* tempChar = (unsigned char*)a;	
	int randomNumber=0,tempBit;
	FILE* useFile = fopen(fileName, "r");
	fscanf(useFile, "%d", &randomNumber);
	fclose(useFile);
	
	for (int i = 0; i < typeSize; i++)
	{
		
		int tempbitCurrent, tempbitNext, next;
		next = (randomNumber + 1) % 8;
		tempbitCurrent = getBitFromRight(*(tempChar + i), randomNumber);
		tempbitNext = getBitFromRight(*(tempChar + i), next);
		*(tempChar + i) = setBitFromRight(*(tempChar + i),next, tempbitCurrent);
		*(tempChar + i) = setBitFromRight(*(tempChar + i), randomNumber, tempbitNext);
		
		*(tempChar + i) ^= 255;
		
		for (int j = 0; j < randomNumber;j++)
		{
			tempBit = getBitFromRight(*(tempChar + i), 0);
			*(tempChar + i) >>= 1;
			*(tempChar + i) = setBitFromRight(*(tempChar + i), 7, tempBit);

		}
		

	}



}

void decodingBits(void* a, int typeSize, char* fileName)
{
	unsigned char* tempChar = (unsigned char*)a;
	int randomNumber = 0, tempBit;
	FILE* useFile = fopen(fileName, "r");
	fscanf(useFile, "%d", &randomNumber);
	fclose(useFile);
	
	for (int i = 0; i < typeSize; i++)
	{
		for (int j = 0; j < randomNumber;j++)
		{
			tempBit = getBitFromRight(*(tempChar + i), 7);
			*(tempChar + i) <<= 1;
			*(tempChar + i) = setBitFromRight(*(tempChar + i), 0, tempBit);

		}
		

		*(tempChar + i) ^= 255;

		int tempbitCurrent, tempbitNext, next;
		next = (randomNumber + 1) % 8;
		tempbitCurrent = getBitFromRight(*(tempChar + i), randomNumber);
		tempbitNext = getBitFromRight(*(tempChar + i), next);
		*(tempChar + i) = setBitFromRight(*(tempChar + i), next, tempbitCurrent);
		*(tempChar + i) = setBitFromRight(*(tempChar + i), randomNumber, tempbitNext);


	}

}



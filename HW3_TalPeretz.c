#include "Hotel.h"
#include <time.h> 

void main(int argc, char* argv[])
{
	hotel_t theHotel;
	if (argc > 1)
	{
		FILE* fileToread  = fopen(argv[1], "rb");
		decodingHotelDetailsFromFile(&theHotel, FILERANDOMNUMBER, fileToread);
		fclose(fileToread);
	}
	else
	{
		int floorsNumber = 0, roomsNumber = 0;
		printf("enter floor number for the hotel");
		scanf("%d", &floorsNumber);
		getchar();
		printf("enter room number for the hotel");
		scanf("%d", &roomsNumber);
		getchar();
		theHotel = buildHotel(floorsNumber, roomsNumber);
	}

	if (theHotel.numberOfRoomInFloor >= 3)
	{
		getAttributeFrom3Rooms(BALCONIINDEX, &(theHotel.roomMatrix[0][0]), &(theHotel.roomMatrix[0][1]), &(theHotel.roomMatrix[0][2]), NULL);
	}
	else
	{
		printf("there no three rooms in this floor");
	}
	int attributeIndex=0;

	printf("Welcome to Peretz Hotel\n");
	int question = 90;
	do
	{
		printf("1)show hotel status press->1\n");
		printf("2)show free rooms with specific attrbiute press->2\n");
		printf("3)for exit press->0\n");
		scanf("%d", &question);

		switch (question)
		{
		case 1:
			showHotelStatus(theHotel);
			break;
		case 2:
			printf("enter your Attribute index for checking:\npool view-0\nbalconi-1\nkomkom-2\nfree wifi-3\nsofa-4\ntv-5\nis occupied?-6\n");
			scanf("%d", &attributeIndex);
			allFreeRoomsWithAttribute(&theHotel, attributeIndex);
			break;
		case 0:
			question = 0;
			break;

		}


	} while (question != 0);
	printf("good bye\n");

	srand((unsigned long)time(NULL));
	int randomNumber = rand() % 8;
	FILE* txtFile = fopen(FILERANDOMNUMBER, "w");
	fprintf(txtFile, "%d\n", randomNumber);
	fclose(txtFile);
	FILE* binaryFile = fopen(MYHOTELFILE, "wb");
	encodingHotelDetails(&(theHotel), FILERANDOMNUMBER, binaryFile);


	freeHotel(&theHotel);

	system("pause");
}


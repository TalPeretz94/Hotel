#include "Hotel.h"

hotel_t buildHotel(int floorsNumber, int roomsNumber)
{
	hotel_t theHotel;

	theHotel.floorNumber = floorsNumber;
	theHotel.numberOfRoomInFloor = roomsNumber;
	theHotel.roomMatrix = (room_t**)malloc(floorsNumber * sizeof(room_t*));
	for (int i = 0; i < floorsNumber; i++)
	{
		theHotel.roomMatrix[i] = (room_t*)calloc(roomsNumber, sizeof(room_t));
	}
	for (int i = 0; i < theHotel.floorNumber; i++)
	{
		for (int j = 0;j < theHotel.numberOfRoomInFloor;j++)
		{
			int roomIndex = ((i + 1) * 100) + j;
			printf("enter the details for room %d\n", roomIndex);
			setRoom(&(theHotel.roomMatrix[i][j]));
		}
	}

	return theHotel;

}
void showHotelStatus(hotel_t theHotel)
{
	for (int i = 0; i < theHotel.floorNumber; i++)
	{
		for (int j = 0; j < theHotel.numberOfRoomInFloor; j++)
		{
			int roomInedx = (((i + 1) * 100) + j);
			printf("the room number is: %d\n", roomInedx);
			getRoom(&(theHotel.roomMatrix[i][j]));
		}
	}
}

void allFreeRoomsWithAttribute(hotel_t* theHotel, int attributeIndex)
{
	int checkRoom,roomNumber;
	for (int i = 0;i < theHotel->floorNumber;i++)
	{
		for (int j = 0;j < theHotel->numberOfRoomInFloor;j++)
		{
			checkRoom = isAttributeInRoom(&(theHotel->roomMatrix[i][j]), attributeIndex);
			if (checkRoom == 1)
			{
				if (isAttributeInRoom(&(theHotel->roomMatrix[i][j]), 6) == 0)
				{
					roomNumber = ((i + 1) * 100) + j;
					printf("the room number is: %d \n", roomNumber);
					getRoom(&(theHotel->roomMatrix[i][j]));
				}
				else 
				{
					roomNumber = ((i + 1) * 100) + j;
					printf("the room- %d is occupied \n", roomNumber);
				}

			}
		}
	}
}

void getAttributeFrom3Rooms(attributeIndex, ...)
{
	int check;
	va_list allRoom;
	va_start(allRoom, attributeIndex);
	room_t* tempRoom = va_arg(allRoom, room_t*);
	while (tempRoom != NULL)
	{
		check = isAttributeInRoom(tempRoom, attributeIndex);
		if (check == 1)
		{
			getRoom(tempRoom);
		}
		tempRoom = va_arg(allRoom, room_t*);

	}
	va_end(allRoom);



}

void encodingHotelDetails(hotel_t* theHotel, char* RandomNumberFile, FILE* BinfileNameWrite)
{
	BinfileNameWrite = fopen(MYHOTELFILE, "wb");
	int tempFloor = theHotel->floorNumber;
	int tempRoom = theHotel->numberOfRoomInFloor;
	
	encodingBits(&theHotel->floorNumber, sizeof(int), RandomNumberFile);
	fwrite(&(theHotel->floorNumber), sizeof(int), 1, BinfileNameWrite);
	encodingBits(&(theHotel->numberOfRoomInFloor), sizeof(int), RandomNumberFile);
	fwrite(&(theHotel->numberOfRoomInFloor), sizeof(int), 1, BinfileNameWrite);



	for (int i = 0;i <tempFloor;i++)
	{
		
		encodingBits(theHotel->roomMatrix[i], sizeof(room_t) * (tempRoom), RandomNumberFile);
		fwrite(theHotel->roomMatrix[i], sizeof(room_t), tempRoom, BinfileNameWrite);

	}
	fclose(BinfileNameWrite);
}

void decodingHotelDetailsFromFile(hotel_t* theHotel, char* RandomNumberFile, FILE* BinfileNameWrite)
{
	
	int floornumber, roomnumber;
	fread(&floornumber, sizeof(int),1, BinfileNameWrite);
	fread(&roomnumber, sizeof(int), 1, BinfileNameWrite);
	decodingBits(&floornumber, sizeof(int), RandomNumberFile);
	decodingBits(&roomnumber, sizeof(int), RandomNumberFile);
	theHotel->floorNumber = floornumber;
	theHotel->numberOfRoomInFloor = roomnumber;
	
	theHotel->roomMatrix = (room_t**)malloc(floornumber * sizeof(room_t*));
	for (int i = 0; i < floornumber; i++)
	{
		theHotel->roomMatrix[i] = (room_t*)calloc(roomnumber, sizeof(room_t));

		fread(theHotel->roomMatrix[i], sizeof(room_t), theHotel->numberOfRoomInFloor, BinfileNameWrite);

		decodingBits(theHotel->roomMatrix[i], sizeof(room_t) * (theHotel->numberOfRoomInFloor), RandomNumberFile);

		
	}

	
	
}

void freeHotel(hotel_t* hotel)
{
	for (int i = 0; i < hotel->floorNumber; i++)
	{

		free(hotel->roomMatrix[i]);
	}
	free(hotel->roomMatrix);
}


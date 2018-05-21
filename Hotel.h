
#include "Room.h"
#ifndef _Hotel
#define _Hotel



struct  Hotel
{
	int floorNumber;
	int numberOfRoomInFloor;
	room_t** roomMatrix;
};
typedef  struct  Hotel  hotel_t;

hotel_t buildHotel(int floorsNumber, int roomsNumber);
void showHotelStatus(hotel_t theHotel);
void allFreeRoomsWithAttribute(hotel_t* hotel, int attributeIndex);
void getAttributeFrom3Rooms(attributeIndex, ...);
void encodingHotelDetails(hotel_t* theHotel, char* RandomNumberFile, FILE* BinfileNameWrite);
void decodingHotelDetailsFromFile(hotel_t* theHotel, char* RandomNumberFile, FILE* BinfileNameWrite);
void freeHotel(hotel_t* hotel);


#endif // !_Hotel
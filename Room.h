
#include "HeaderGeneral.h"
#ifndef _Room
#define _Room

struct  Room
{
	int numOfBeds;
	unsigned char roomDetails;
};
typedef  struct  Room  room_t;

void setRoom(room_t* theRoom);
void getRoom(room_t* theRoom);
int isAttributeInRoom(room_t* theRoom, int attributeIndex);


#endif // !_Room
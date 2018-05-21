#include "Room.h"
#define SIZEDETAILS 7


void setRoom(room_t* theRoom) 
{
	
	theRoom->numOfBeds = getNumOfBeds();
	int answer;
	for (int i = 0;i < SIZEDETAILS;i++) 
	{

		answer=getAnswerFromCustomer(i);
		theRoom->roomDetails= setBitFromRight(theRoom->roomDetails, i, answer);
			
	}
}

void getRoom(room_t* theRoom)
{
	int answer;
	
	printf("the number of beds in the room is: %d\n", theRoom->numOfBeds);
	for (int i = 0;i < SIZEDETAILS;i++) 
	{
		answer=getBitFromRight(theRoom->roomDetails, i);
		printRoomDetails(i, answer);
		
	}
	printf("-------------------------------\n");
}

int isAttributeInRoom(room_t* theRoom,int attributeIndex)
{
	int attributeTemp;
	attributeTemp=getBitFromRight(theRoom->roomDetails, attributeIndex);
	if (attributeTemp == 0) 
	{
		return 0;
	}
	else 
	{
		return 1;
	}


}


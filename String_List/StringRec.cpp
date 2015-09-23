#include "StringRec.h"


bool StringRec::operator <(StringRec otherBook)
{
	return id<otherBook.id;
}


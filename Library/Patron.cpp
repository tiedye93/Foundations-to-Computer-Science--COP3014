#include "Patron.h"


bool Patron::operator <(Patron otherPatron)
{
	return id<otherPatron.id;
}


bool compareByPatron(Patron & p1, Patron & p2)
{
	return p1.name<p2.name;
}

#include "Book.h"


bool Book::operator <(Book otherBook)
{
	return id<otherBook.id;
}


bool compareByName(Book & b1, Book & b2)
{
	return b1.name<b2.name;
}
bool compareByAuthor(Book & b1, Book & b2)
{
	return b1.author<b2.author;
}
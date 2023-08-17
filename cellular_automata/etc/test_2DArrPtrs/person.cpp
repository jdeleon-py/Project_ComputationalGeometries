#include "person.h"

Person::Person(std::string name, std::string email) : name{name}, email{email} {}

std::string Person::to_string() const
{
	return name;
}

std::string Person::full_info() const
{
	return name + " (" + email + ") ";
}

std::ostream& operator<<(std::ostream& ost, const Person& person)
{
	ost << person.to_string();
	return ost;
}

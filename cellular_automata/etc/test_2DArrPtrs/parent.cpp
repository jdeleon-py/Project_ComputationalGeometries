#include "person.h"
#include "parent.h"
#include "student.h"

Parent::Parent(std::string name, std::string email) : Person(name, email) {}

void Parent::add_student(Student& student)
{
	students.push_back(&student);
}

int Parent::num_students()
{
	return students.size();
}

Student& Parent::student(int index)
{
	if((index < 0) || (index >= students.size()))
	{
		throw std::out_of_range("Index not within range!");
	}
	else
	{
		return *(students.at(index));
	}
}

std::string Parent::full_info() const
{
	std::string info = Person::full_info() + " - Students: ";
	std::string seperator;
	for(auto s : students)
	{
		info += seperator + (s -> to_string());
		seperator = ", ";
	}
	return info;
}

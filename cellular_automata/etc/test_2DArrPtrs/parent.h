#ifndef __PARENT_H
#define __PARENT_H

#include <iostream>
#include <vector>
#include "person.h"

class Student;

class Parent : public Person
{
public:
	Parent(std::string name, std::string email);
	void add_student(Student& student);
	int num_students();
	Student& student(int index);
	std::string full_info() const override;
protected:
	std::vector<Student*> students;
};

#endif

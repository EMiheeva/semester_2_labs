#include <memory>
#include <iostream>
#include <vector>

class Person
{
public:
	std::string name;

	Person(std::string new_name)
	{
		name = new_name;
	}
	~Person()
	{
		std::cout << "Person is deleted" << std::endl;
	}
};
class Student : Person
{
public:
	std::shared_ptr<Person> teacher;

	~Student()
	{
		std::cout << "Student is deleted"<< std::endl;
	}
};
class Teacher : Person
{
public:
	std::vector< std::shared_ptr<Student> > students;

	~Teacher()
	{
		std::cout << "Teacher is deleted" << std::endl;
	}
};
int main()
{
	auto student1{ std::make_shared<Student>("Kate") };
	auto student2{ std::make_shared<Student>("Liza") };
	auto student3{ std::make_shared<Student>("Mike") };

	auto teacher0{ std::make_shared<Teacher>("Peter Parker") };

	student1->teacher = teacher0;
	student2->teacher = teacher0;
	student3->teacher = teacher0;

	teacher0->students.push_back(student1);
	teacher0->students.push_back(student2);
	teacher0->students.push_back(student3);
}


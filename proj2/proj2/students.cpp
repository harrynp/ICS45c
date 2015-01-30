//Harry Pham 79422112
#include <iostream>
#include <string>
#include "structs.hpp"

void zero_filled_array(unsigned int* a, unsigned int size)
{
	for (unsigned int* p = a; p < a + size; p++)
	{
		*p = 0;
	}
}

Student* student_array_creator(const unsigned int &number_of_students, const unsigned int &number_of_graded_artifacts)
{
	Student* student_array = new Student[number_of_students];
	for (unsigned int i = 0; i < number_of_students; i++)
	{
		std::cin >> student_array[i].student_id;
		std::cin.ignore(1);
		getline(std::cin, student_array[i].name);
		student_array[i].raw_scores = new unsigned int[number_of_graded_artifacts];
		zero_filled_array(student_array[i].raw_scores, number_of_graded_artifacts);
	}
	return student_array;
}

void raw_scores_input(const unsigned int &number_of_raw_scores, const unsigned int &number_of_graded_artifacts, const unsigned int &number_of_students, Student* &student_array)
{
	for (unsigned int i = 0; i < number_of_raw_scores; i++)
	{
		bool student_in_class = false;
		unsigned int student_id;
		unsigned int index;
		std::cin >> student_id;
		for (unsigned int n = 0; n < number_of_students; n++)
		{
			if (student_array[n].student_id == student_id)
			{
				student_in_class = true;
				index = n;
				break;
			}
		}
		if (student_in_class == true)
		{
			for (unsigned int i = 0; i < number_of_graded_artifacts; i++)
			{
				std::cin >> student_array[index].raw_scores[i];
			}
		}
		else
		{
			std::string not_in_class;
			getline(std::cin, not_in_class);
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//not working in virtual machine
		}
	}
}

void print_total_score(Student* student_array, const unsigned int &number_of_students)
{
	std::cout << "TOTAL SCORES" << std::endl;
	for (unsigned int i = 0; i < number_of_students; i++)
	{
		std::cout << student_array[i].student_id << " " << student_array[i].name << " " << student_array[i].total_score << std::endl;
	}
}

void print_letter_grade(Student* student_array, const unsigned int &number_of_students, const unsigned int &number_of_cutpoints)
{
	for (unsigned int i = 0; i < number_of_cutpoints; i++)
	{
		double cutpoints[4];
		std::cin >> cutpoints[0] >> cutpoints[1] >> cutpoints[2] >> cutpoints[3];
		std::cout << "CUTPOINT SET " << i + 1 << std::endl;
		for (int n = 0; n < number_of_students; n++)
		{
			if (student_array[n].total_score < cutpoints[3])
			{
				std::cout << student_array[n].student_id << " " << student_array[n].name << " F" << std::endl;
			}
			else if (student_array[n].total_score < cutpoints[2])
			{
				std::cout << student_array[n].student_id << " " << student_array[n].name << " D" << std::endl;
			}
			else if (student_array[n].total_score < cutpoints[1])
			{
				std::cout << student_array[n].student_id << " " << student_array[n].name << " C" << std::endl;
			}
			else if (student_array[n].total_score < cutpoints[0])
			{
				std::cout << student_array[n].student_id << " " << student_array[n].name << " B" << std::endl;
			}
			else
			{
				std::cout << student_array[n].student_id << " " << student_array[n].name << " A" << std::endl;
			}
		}
	}
}
//Harry Pham 79422112
#include <iostream>
#include <string>
#include "structs.hpp"
#include "students.hpp"
#include "grades.hpp"

int main()
{
	unsigned int number_of_graded_artifacts;
	unsigned int number_of_students;
	unsigned int number_of_raw_scores;
	unsigned int number_of_cutpoints;
	std::cin >> number_of_graded_artifacts;
	Graded_Artifacts artifacts = grades(number_of_graded_artifacts);
	std::cin >> number_of_students;
	Student* student_array = student_array_creator(number_of_students, number_of_graded_artifacts);
	std::cin >> number_of_raw_scores;
	raw_scores_input(number_of_raw_scores, number_of_graded_artifacts, number_of_students, student_array);
	for (unsigned int i = 0; i < number_of_students; i++)
	{
		calculate_total_score(student_array[i], artifacts, number_of_graded_artifacts);
	}
	delete[] artifacts.possible_points;
	delete[] artifacts.weights;
	print_total_score(student_array, number_of_students);
	std::cin >> number_of_cutpoints;
	print_letter_grade(student_array, number_of_students, number_of_cutpoints);
	delete[] student_array;
	return 0;
}
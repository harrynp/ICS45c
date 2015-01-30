//Harry Pham 79422112
#include <iostream>
#include "structs.hpp"

Graded_Artifacts grades(const unsigned int &number_of_graded_artifacts)
{
	Graded_Artifacts artifacts;
	artifacts.possible_points = new unsigned int[number_of_graded_artifacts];
	for (unsigned int i = 0; i < number_of_graded_artifacts; i++)
	{
		std::cin >> artifacts.possible_points[i];
	}
	artifacts.weights = new unsigned int[number_of_graded_artifacts];
	for (unsigned int i = 0; i < number_of_graded_artifacts; i++)
	{
		std::cin >> artifacts.weights[i];
	}
	return artifacts;
}

void calculate_total_score(Student &student, const Graded_Artifacts &artifacts, const unsigned int &number_of_graded_artifacts)
{
	double total_score = 0;
	for (unsigned int i = 0; i < number_of_graded_artifacts; i++)
	{
		total_score += (static_cast<double>(student.raw_scores[i]) / static_cast<double>(artifacts.possible_points[i])) * static_cast<double>(artifacts.weights[i]);
	}
	delete[] student.raw_scores;
	student.total_score = total_score;
}
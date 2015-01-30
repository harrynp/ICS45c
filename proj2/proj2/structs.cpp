//Harry Pham 79422112
#include <string>

struct Student
{
	unsigned int student_id;
	std::string name;
	unsigned int* raw_scores;
	double total_score;
};

struct Graded_Artifacts
{
	unsigned int* possible_points;
	unsigned int* weights;
};
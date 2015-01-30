//Harry Pham 79422112
#ifndef STUDENTS_HPP
#define STUDENTS_HPP

void zero_filled_array(unsigned int* a, unsigned int size);

Student* student_array_creator(const unsigned int &number_of_students, const unsigned int &number_of_graded_artifacts);

void raw_scores_input(const unsigned int &number_of_raw_scores, const unsigned int &number_of_graded_artifacts, const unsigned int &number_of_students, Student* &student_array);

void print_total_score(Student* student_array, const unsigned int &number_of_students);

void print_letter_grade(Student* student_array, const unsigned int &number_of_students, const unsigned int &number_of_cutpoints);

#endif // STUDENTS_HPP
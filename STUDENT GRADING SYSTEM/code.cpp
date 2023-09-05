#include <iostream>
#include <vector>
#include <string>
#include <limits>

const int SUBJECT_COUNT = 5;

struct Student {
    std::string name;
    float grades[SUBJECT_COUNT];
    char finalGrade;
};

class GradeManager {
private:
    std::vector<Student> students;

    char assignGrade(float percentage) {
        if (percentage >= 90) return 'A';
        else if (percentage >= 80) return 'B';
        else if (percentage >= 70) return 'C';
        else if (percentage >= 60) return 'D';
        else if (percentage >= 50) return 'E';
        else return 'F';
    }

public:
    void addStudent() {
        Student student;
        std::cout << "Enter student's name: ";
        std::cin.ignore();
        std::getline(std::cin, student.name);
        
        float sum = 0.0;
        for (int i = 0; i < SUBJECT_COUNT; i++) {
            std::cout << "Enter grade for subject " << (i + 1) << ": ";
            while (!(std::cin >> student.grades[i]) || student.grades[i] < 0 || student.grades[i] > 100) {
                std::cout << "Please enter a valid grade between 0 and 100: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            sum += student.grades[i];
        }

        float average = sum / SUBJECT_COUNT;
        student.finalGrade = assignGrade(average);

        students.push_back(student);
    }

    void displayStats() {
        if (students.empty()) {
            std::cout << "No student data entered." << std::endl;
            return;
        }

        int gradeCounts[6] = {0}; // For grades A-F respectively

        for (const auto& student : students) {
            switch (student.finalGrade) {
                case 'A': gradeCounts[0]++; break;
                case 'B': gradeCounts[1]++; break;
                case 'C': gradeCounts[2]++; break;
                case 'D': gradeCounts[3]++; break;
                case 'E': gradeCounts[4]++; break;
                case 'F': gradeCounts[5]++; break;
            }
        }

        std::cout << "Grade Statistics:" << std::endl;
        std::cout << "A: " << gradeCounts[0] << " students" << std::endl;
        std::cout << "B: " << gradeCounts[1] << " students" << std::endl;
        std::cout << "C: " << gradeCounts[2] << " students" << std::endl;
        std::cout << "D: " << gradeCounts[3] << " students" << std::endl;
        std::cout << "E: " << gradeCounts[4] << " students" << std::endl;
        std::cout << "F (Fail): " << gradeCounts[5] << " students" << std::endl;
    }

    void displayAllGrades() {
        for (const auto& student : students) {
            std::cout << student.name << ": Grade - " << student.finalGrade << std::endl;
        }
    }
};

int main() {
    GradeManager manager;
    while (true) {
        std::cout << "\nMENU:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Statistics\n";
        std::cout << "3. Display All Grades\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.displayStats();
            break;
        case 3:
            manager.displayAllGrades();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

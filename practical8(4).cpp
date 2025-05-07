#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int score;

    Student(string n, int s) : name(n), score(s) {}
};

bool compareScores(const Student &a, const Student &b) {
    return a.score > b.score;
}

int main() {
    vector<Student> students;
    int n;
    string name;
    int score;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter name and score for student " << i + 1 << ": ";
        cin >> name >> score;
        students.push_back(Student(name, score));
    }

    sort(students.begin(), students.end(), compareScores);

    cout << "\nRanked List of Students:\n";
    cout << "Rank\tName\t\tScore\n";
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << (it - students.begin() + 1) << "\t" << it->name << "\t" << it->score << endl;
    }

    return 0;
}


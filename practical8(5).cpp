#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void addFolder(map<string, vector<string>>& directory, const string& folderName) {
    // If folder doesn't exist, create it
    if (directory.find(folderName) == directory.end()) {
        directory[folderName] = vector<string>();
        cout << "Folder '" << folderName << "' created.\n";
    } else {
        cout << "Folder '" << folderName << "' already exists.\n";
    }
}

void addFileToFolder(map<string, vector<string>>& directory, const string& folderName, const string& fileName) {
    if (directory.find(folderName) != directory.end()) {
        directory[folderName].push_back(fileName);
        cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
    } else {
        cout << "Folder '" << folderName << "' does not exist.\n";
    }
}

void displayDirectory(const map<string, vector<string>>& directory) {
    cout << "\nDirectory Structure:\n";
    for (auto folderIt = directory.begin(); folderIt != directory.end(); ++folderIt) {
        cout << folderIt->first << ":\n";
        for (auto fileIt = folderIt->second.begin(); fileIt != folderIt->second.end(); ++fileIt) {
            cout << "  - " << *fileIt << endl;
        }
    }
}

int main() {
    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    do {
        cout << "\n--- Directory Management Menu ---\n";
        cout << "1. Create Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                getline(cin, folder);
                addFolder(directory, folder);
                break;
            case 2:
                cout << "Enter folder name: ";
                getline(cin, folder);
                cout << "Enter file name: ";
                getline(cin, file);
                addFileToFolder(directory, folder, file);
                break;
            case 3:
                displayDirectory(directory);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}


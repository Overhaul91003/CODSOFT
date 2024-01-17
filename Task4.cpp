//Task 4 :

// Create a To-do List :

//Build a simple console-based to-do list
//manager that allows users to add, view, and
//delete tasks


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
public:
    ToDoList() {
        customTasks = {};
    }

    void addCustomTask(const string& customTask) {
        customTasks.push_back(customTask);
    }

    void displayCustomTasks() {
        if (customTasks.empty()) {
            cout << "No custom tasks to display." << endl;
        } else {
            for (size_t i = 0; i < customTasks.size(); i++) {
                cout << i + 1 << ". " << customTasks[i] << endl;
            }
        }
    }

    void completeCustomTask(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= customTasks.size()) {
            customTasks[taskNumber - 1] = "[COMPLETED] " + customTasks[taskNumber - 1];
        } else {
            cout << "Invalid custom task number." << endl;
        }
    }

    void removeCustomTask(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= customTasks.size()) {
            customTasks.erase(customTasks.begin() + taskNumber - 1);
        } else {
            cout << "Invalid custom task number." << endl;
        }
    }

private:
    vector<string> customTasks;
};

int main() {
    ToDoList ToDoList;

    int choice;
    do {
        cout << "\n===== Unique ToDoList Menu =====" << endl;
        cout << "1. Add Custom Task\n";
        cout << "2. Display Custom Tasks\n";
        cout << "3. Complete Custom Task\n";
        cout << "4. Remove Custom Task\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the custom task: ";
                cin.ignore();  
                getline(cin, task);
                ToDoList.addCustomTask(task);
                cout << "Custom task added successfully!" << endl;
                break;
            }
            case 2:
                ToDoList.displayCustomTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter the custom task number to mark as complete: ";
                cin >> taskNumber;
                ToDoList.completeCustomTask(taskNumber);
                cout << "Custom task marked as complete!" << endl;
                break;
            }
            case 4: {
                int taskNumber;
                cout << "Enter the custom task number to remove: ";
                cin >> taskNumber;
                ToDoList.removeCustomTask(taskNumber);
                cout << "Custom task removed successfully!" << endl;
                break;
            }
            case 0:
                cout << "Exiting ToDoList. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

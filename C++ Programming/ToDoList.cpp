#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayList(const vector<pair<string, bool>>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].first;
            if (tasks[i].second) {
                cout << " (Completed)";
            } else {
                cout << " (Pending)";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<pair<string, bool>> todoList; // Each task is paired with a boolean indicating completion status

    cout << "Welcome to the To-Do List Manager!" << endl;

    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task to add: ";
                cin.ignore(); // Clear the newline character
                getline(cin, task);
                todoList.push_back(make_pair(task, false)); //task pending by default
                cout << "Task added: " << task << endl;
                break;
            }
            case 2:
                displayList(todoList);
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                if (index >= 1 && index <= static_cast<int>(todoList.size())) {
                    todoList[index - 1].second = true; // Marking the task as completed
                    cout << "Task marked as completed: " << todoList[index - 1].first << endl;
                } else {
                    cout << "Invalid task index." << endl;
                }
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                if (index >= 1 && index <= static_cast<int>(todoList.size())) {
                    cout << "Task removed: " << todoList[index - 1].first << endl;
                    todoList.erase(todoList.begin() + index - 1);
                } else {
                    cout << "Invalid task index." << endl;
                }
                break;
            }
            case 5:
                cout << "Thanks for using the To-Do List Manager!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

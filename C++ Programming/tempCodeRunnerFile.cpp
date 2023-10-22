#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> todoList;
    
    cout << "Welcome to the Simple To-Do List Manager!" << endl;

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
                cin.ignore();
                getline(cin, task);
                todoList.push_back(task);
                cout << "Task added: " << task << endl;
                break;
            }
            case 2: {
                cout << "To-Do List:" << endl;
                for (size_t i = 0; i < todoList.size(); i++) {
                    cout << i + 1 << ". " << todoList[i] << endl;
                }
                if (todoList.empty()) {
                    cout << "Your to-do list is empty." << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "Enter the task number to mark as completed (1-" << todoList.size() << "): ";
                cin >> index;
                if (index >= 1 && index <= static_cast<int>(todoList.size())) {
                    cout << "Task marked as completed: " << todoList[index - 1] << endl;
                    todoList.erase(todoList.begin() + index - 1);
                } else {
                    cout << "Invalid task number." << endl;
                }
                break;
            }
            case 4: {
                int index;
                cout << "Enter the task number to remove (1-" << todoList.size() << "): ";
                cin >> index;
                if (index >= 1 && index <= static_cast<int>(todoList.size())) {
                    cout << "Task removed: " << todoList[index - 1] << endl;
                    todoList.erase(todoList.begin() + index - 1);
                } else {
                    cout << "Invalid task number." << endl;
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

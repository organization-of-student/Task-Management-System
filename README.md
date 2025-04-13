# Task-Management-System
Task Management System
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    int id;
    string title;
    string description;
    string status;
};

vector<Task> tasks;
int nextId = 1;

void loadTasksFromFile() {
    ifstream file("tasks.txt");
    Task task;
    while (file >> task.id) {
        file.ignore();
        getline(file, task.title);
        getline(file, task.description);
        getline(file, task.status);
        tasks.push_back(task);
        if (task.id >= nextId)
            nextId = task.id + 1;
    }
    file.close();
}

void saveTasksToFile() {
    ofstream file("tasks.txt");
    for (auto& task : tasks) {
        file << task.id << endl;
        file << task.title << endl;
        file << task.description << endl;
        file << task.status << endl;
    }
    file.close();
}

void addTask() {
    Task task;
    task.id = nextId++;
    cin.ignore();
    cout << "Enter task title: ";
    getline(cin, task.title);
    cout << "Enter task description: ";
    getline(cin, task.description);
    task.status = "Pending";
    tasks.push_back(task);
    saveTasksToFile();
    cout << "Task added successfully!\n";
}

void viewTasks() {
    cout << "\n--- All Tasks ---\n";
    for (auto& task : tasks) {
        cout << "ID: " << task.id << "\nTitle: " << task.title
             << "\nDescription: " << task.description
             << "\nStatus: " << task.status << "\n\n";
    }
}

void updateTask() {
    int id;
    cout << "Enter Task ID to update: ";
    cin >> id;
    for (auto& task : tasks) {
        if (task.id == id) {
            cin.ignore();
            cout << "Enter new title: ";
            getline(cin, task.title);
            cout << "Enter new description: ";
            getline(cin, task.description);
            cout << "Enter new status (Pending/In Progress/Completed): ";
            getline(cin, task.status);
            saveTasksToFile();
            cout << "Task updated!\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void deleteTask() {
    int id;
    cout << "Enter Task ID to delete: ";
    cin >> id;
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            saveTasksToFile();
            cout << "Task deleted.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

int main() {
    loadTasksFromFile();
    int choice;
    do {
        cout << "\n--- Task Management System ---\n";
        cout << "1. Add Task\n2. View Tasks\n3. Update Task\n4. Delete Task\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: updateTask(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> undoStack, redoStack;
    string currentText = "";
    int choice;
    string newText;

    while (true) {
        cout << "\n----- Undo,Redo Editor -----\n";
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter text to add: ";
                cin >> newText;
                undoStack.push(currentText);
                
                if (!currentText.empty()) currentText += " ";
                currentText += newText;
                
                while (!redoStack.empty()) redoStack.pop();

                cout << "Text added successfully!\n";
                break;

            case 2:
                if (currentText.empty()) {
                    cout << "Nothing to delete!\n";
                } else {
                    undoStack.push(currentText);
                    size_t pos = currentText.find_last_of(' ');
                    if (pos == string::npos)
                        currentText = "";
                    else
                        currentText = currentText.substr(0, pos);
                    while (!redoStack.empty()) redoStack.pop();

                    cout << "Last word deleted successfully!\n";
                }
                break;

            case 3:
                if (!undoStack.empty()) {
                    redoStack.push(currentText);
                    currentText = undoStack.top();
                    undoStack.pop();
                    cout << "Undo successful!\n";
                } else {
                    cout << "Nothing to undo!\n";
                }
                break;

            case 4:
                if (!redoStack.empty()) {
                    undoStack.push(currentText);
                    currentText = redoStack.top();
                    redoStack.pop();
                    cout << "Redo successful!\n";
                } else {
                    cout << "Nothing to redo!\n";
                }
                break;

            case 5:
                if (currentText.empty())
                    cout << "Current Text: (empty)\n";
                else
                    cout << "Current Text: " << currentText << endl;
                break;

            case 6:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

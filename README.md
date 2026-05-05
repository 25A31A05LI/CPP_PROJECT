# Undo/Redo Text Editor

A simple, console-based text editor built in C++ that demonstrates how the **Stack** data structure can be used to implement complex features like "Undo" and "Redo". 

## 📌 Features
- **Insertion**: Add new words or sentences to your text.
- **Deletion**: Remove the last word entered.
- **Undo**: Revert your last action seamlessly.
- **Redo**: Restore an action you previously undid.
- **Display**: View the current state of your text.

## 🛠️ Tech Stack
- **Language**: C++
- **Core Library**: Standard Template Library (STL)
- **Data Structure used**: `std::stack`

## 🚀 How to Run the Project

### Prerequisites
Make sure you have a C++ compiler installed (like GCC or MinGW) on your computer.

### Compilation
Open your terminal or command prompt, navigate to the folder containing `main.cpp`, and run:
```bash
g++ main.cpp -o undo_redo
```

### Execution
Run the compiled executable:
- **On Windows**:
  ```bash
  undo_redo.exe
  ```
- **On Mac/Linux**:
  ```bash
  ./undo_redo
  ```

## 📂 Project Structure
- `main.cpp` - The core C++ source code.
- `Project_Documentation.docx` - A detailed breakdown of the algorithms, flowchart, and methodology.
- `Undo_Redo_Presentation.pptx` - A presentation summarizing the application.

## 💡 How it works under the hood
1. We use an `undoStack` to record the state of the text every time an **Insertion** or **Deletion** occurs.
2. When the user selects **Undo**, the current text is pushed into the `redoStack`, and the text reverts to the top of the `undoStack`.
3. When the user selects **Redo**, the current text is pushed back into the `undoStack`, and the text is updated from the top of the `redoStack`.
4. Any new **Insertion** or **Deletion** automatically clears the `redoStack` because a new alternate history timeline has been created.

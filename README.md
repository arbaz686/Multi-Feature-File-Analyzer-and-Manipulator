# **File Analyzer and Manipulator**
This advanced C++ application serves as a tool to analyze and manipulate text-based files efficiently.

## **Project Overview**
The **File Analyzer and Manipulator** is a C++ console application that allows users to:
- **Analyze files** for detailed metrics like word count, character count, line count, frequency of each word, and more.
- **Manipulate files** by performing operations such as searching, replacing, and case conversions.
- **Handle large files** with efficient memory management to ensure optimal performance.

The tool is designed to be modular, robust, and suitable for experienced developers looking for a high-performance text-processing application.

---

## **Features**
### 1. **File Analysis**
- **Word Count**: Counts the number of words in a file.
- **Line Count**: Counts the number of lines.
- **Character Count**: Includes both spaces and non-space characters.
- **Word Frequency**: Calculates how many times each word occurs in the file.
  
### 2. **File Manipulation**
- **Search and Replace**: Allows you to search for specific words and replace them with others.
- **Convert Case**: Convert the text in the file to **UPPERCASE** or **lowercase**.
- **Remove Blank Lines**: Automatically removes all the blank lines from the file.
  
### 3. **Error Handling and Performance Optimization**
- Includes error handling for invalid inputs, file not found errors, and other edge cases.
- Optimized for large files with minimal memory usage.

---

## **Getting Started**
### **Prerequisites**
To compile and run this project, you'll need:
- **C++ Compiler**: Any modern C++ compiler, such as GCC or MinGW for Windows.
- **Text Editor**: VS Code or any other editor that supports C++ development.

### **Installation**
1. Clone the repository:
    ```
    git clone https://github.com/YourUsername/File-Analyzer-and-Manipulator.git
    cd File-Analyzer-and-Manipulator
    ```

2. Compile the source code:
    ```
    g++ File_Analyzer_and_Manipulator.cpp -o File_Analyzer_and_Manipulator
    ```

3. Run the executable:
    ```
    ./File_Analyzer_and_Manipulator
    ```

---

## **How to Use**
Once the program is running, follow the prompts to select the operation you'd like to perform:

1. **Select the File**: You will be prompted to enter the file path.
2. **Choose Operation**: Choose between various operations such as:
   - Analyze file (word count, line count, etc.)
   - Search and replace words
   - Convert case
3. **View Results**: The application will display the results of the analysis or modification directly in the console.
   
### **Sample Usage:**

Enter file path: testfile.txt
Choose operation:
1. Analyze file
2. Search and Replace
3. Convert to Uppercase
4. Convert to Lowercase
5. Remove Blank Lines

---

## **Contributing**
Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature (`git checkout -b feature-name`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Open a Pull Request.

---

## **License**
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

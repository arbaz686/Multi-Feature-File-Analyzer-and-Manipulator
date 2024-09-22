#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Function Declarations 
void displayMenu();
string loadFile();
void wordFrequencyAnalysis(const string &content);
void patternSearch(const string &content);
void modifyFileContent(const string &fileName, string &content);
void backupFile(const string &fileName);
void restoreFile(const string &fileName);
int getUserChoice();
string getFileContent(const string &fileName);
void saveFile(const string &fileName, const string &content);
void showStatistics(const string &content);
void filterCommonWords(map<string, int>& wordFreq);

// Set of common words to filter out during word frequency analysis
set<string> commonWords = {"and", "the", "is", "in", "at", "of", "a", "to", "with", "for"};

// Main function
int main() {
    string fileName;
    string content;
    int choice;

    do {
        displayMenu();
        choice = getUserChoice();
        
        switch (choice) {
            case 1:
                fileName = loadFile();
                content = getFileContent(fileName);
                break;
            case 2:
                if (!content.empty()) {
                    wordFrequencyAnalysis(content);
                } else {
                    cout << "No file loaded. Please load a file first.\n";
                }
                break;
            case 3:
                if (!content.empty()) {
                    patternSearch(content);
                } else {
                    cout << "No file loaded. Please load a file first.\n";
                }
                break;
            case 4:
                if (!content.empty()) {
                    modifyFileContent(fileName, content);
                } else {
                    cout << "No file loaded. Please load a file first.\n";
                }
                break;
            case 5:
                backupFile(fileName);
                break;
            case 6:
                restoreFile(fileName);
                content = getFileContent(fileName);
                break;
            case 7:
                if (!content.empty()) {
                    showStatistics(content);
                } else {
                    cout << "No file loaded. Please load a file first.\n";
                }
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    cout << "Made by Arbaz Ahmad\n";
    return 0;
}

// Function to display the menu options
void displayMenu() {
    cout << "\nMulti-Feature File Analyzer and Manipulator\n";
    cout << "1. Load File\n";
    cout << "2. Word Frequency Analysis\n";
    cout << "3. Pattern Search (Regex)\n";
    cout << "4. Modify File Content\n";
    cout << "5. Backup File\n";
    cout << "6. Restore File\n";
    cout << "7. Show File Statistics\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

// Function to load the file name from the user
string loadFile() {
    string fileName;
    cout << "Enter the file name to load: ";
    cin >> fileName;
    ifstream file(fileName);
    if (!file) {
        cout << "Error: Could not open the file.\n";
        return "";
    }
    cout << "File loaded successfully!\n";
    return fileName;
}

// Function to get the content of the file as a string
string getFileContent(const string &fileName) {
    ifstream file(fileName);
    if (!file) {
        cout << "Error: Could not open file.\n";
        return "";
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Function to analyze word frequency
void wordFrequencyAnalysis(const string &content) {
    map<string, int> wordFreq;
    stringstream ss(content);
    string word;

    while (ss >> word) {
        wordFreq[word]++;
    }

    filterCommonWords(wordFreq);

    cout << "\nWord Frequency Analysis:\n";
    for (const auto& entry : wordFreq) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

// Function to search for a pattern using regex
void patternSearch(const string &content) {
    string pattern;
    cout << "Enter a regex pattern to search: ";
    cin >> pattern;

    regex r(pattern);
    smatch match;
    string::const_iterator searchStart(content.cbegin());

    cout << "Pattern matches found:\n";
    while (regex_search(searchStart, content.cend(), match, r)) {
        cout << match[0] << " found at position " << match.position(0) << endl;
        searchStart = match.suffix().first;
    }
}

// Function to modify file content (append, replace, delete)
void modifyFileContent(const string &fileName, string &content) {
    string oldWord, newWord;
    cout << "Enter the word/phrase to replace: ";
    cin >> oldWord;
    cout << "Enter the new word/phrase: ";
    cin >> newWord;

    size_t pos = content.find(oldWord);
    if (pos != string::npos) {
        content.replace(pos, oldWord.length(), newWord);
        saveFile(fileName, content);
        cout << "File updated successfully!\n";
    } else {
        cout << "Word/phrase not found in the file.\n";
    }
}

// Function to create a backup of the original file
void backupFile(const string &fileName) {
    ifstream src(fileName, ios::binary);
    ofstream dst(fileName + ".bak", ios::binary);
    dst << src.rdbuf();
    cout << "Backup created successfully.\n";
}

// Function to restore the original file from the backup
void restoreFile(const string &fileName) {
    ifstream src(fileName + ".bak", ios::binary);
    if (!src) {
        cout << "Error: Backup not found.\n";
        return;
    }
    ofstream dst(fileName, ios::binary);
    dst << src.rdbuf();
    cout << "File restored successfully.\n";
}

// Function to save the modified content to the file
void saveFile(const string &fileName, const string &content) {
    ofstream file(fileName);
    file << content;
}

// Function to display statistics about the file content
void showStatistics(const string &content) {
    int charCount = content.length();
    int wordCount = 0, sentenceCount = 0, paraCount = 1;
    stringstream ss(content);
    string word;

    while (ss >> word) {
        wordCount++;
        if (word.find('.') != string::npos) {
            sentenceCount++;
        }
    }

    for (char c : content) {
        if (c == '\n') paraCount++;
    }

    cout << "\nFile Statistics:\n";
    cout << "Characters: " << charCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Sentences: " << sentenceCount << endl;
    cout << "Paragraphs: " << paraCount << endl;
    cout << "Average sentence length: " << (wordCount / (double)sentenceCount) << " words\n";
}

// Function to filter common words from the word frequency analysis
void filterCommonWords(map<string, int>& wordFreq) {
    for (const auto& word : commonWords) {
        wordFreq.erase(word);
    }
}

// Function to get the user's choice
int getUserChoice() {
    int choice;
    cin >> choice;
    return choice;
}

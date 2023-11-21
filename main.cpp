/**
 * @file main.cpp
 * @author Jason Moss
 * @date 2023-11-09
 * @brief Uses a BST to count words
 * 
 * Creates a BST and offer the user choices to test it
 */


#include "BST.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
  BST tree;

  int option = 0;
  while(option < 8){
    cout << "Please select an option" << endl;
    cout << "1. Add words yourself" << endl;
    cout << "2. Create a Tree from a file" << endl;
    cout << "3. Find where the value of a word in the tree" << endl;
    cout << "4. Print the tree" << endl;
    cout << "5. Find the smallest value in the tree" << endl;
    cout << "6. Find the largest value in the tree" << endl;
    cout << "7. Remove a word from the tree" << endl;
    cout << "8. Exit" << endl;

    cin >> option;
    cout << endl;

    if(option == 1){
      string word;
      cout << "Please enter word: ";
      cin >> word;
      cout << endl << "Please enter number:";
      int num = 0;
      cin >> num;
      cout << endl;
      tree.set(word, num);
    }

    if(option == 2){
      string file;
      cout << "Please enter file name: ";
      cin >> file;
      cout << endl;
      tree.save_file(file);
    }
    if(option == 3){
      string word;
      cout << "Please enter a word: ";
      cin >> word;
      cout << endl;
      tree.find(word);
    }
    if(option == 4){
      cout << "Printing..." << endl;
      tree.print();
    }
    if(option == 5){
      cout << "Finding smallest...: ";
      tree.min();
      cout << endl;
    }
    if(option == 6){
      cout << "Finding largest...: ";
      tree.max();
      cout << endl;
    }
    if(option == 7){
      cout << "Please enter a word to remove: ";
      string word;
      cin >> word;
      tree.remove(word);
    }
  }
  return 0;
}

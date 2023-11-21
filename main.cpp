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
  while(option < 7){
    cout << "Please select an option" << endl;
    cout << "1. Create a Tree from a file" << endl;
    cout << "2. Find where the value of a word in the tree" << endl;
    cout << "3. Print the tree" << endl;
    cout << "4. Find the smallest value in the tree" << endl;
    cout << "5. Find the largest value in the tree" << endl;
    cout << "6. Remove a word from the tree" << endl;
    cout << "7. Exit" << endl;

    cin >> option;
    cout << endl;

    if(option == 1){
      string file;
      cout << "Please enter file name: ";
      cin >> file;
      cout << endl;
      tree.save_file(file);
    }
    if(option == 2){
      string word;
      cout << "Please enter a word: ";
      cin >> word;
      cout << endl;
      tree.find(word);
    }
    if(option == 3){
      cout << "Printing..." << endl;
      tree.print();
    }
    if(option == 4){
      cout << "Finding smallest...: ";
      tree.min();
      cout << endl;
    }
    if(option == 5){
      cout << "Finding largest...: ";
      tree.max();
      cout << endl;
    }
    if(option == 6){
      cout << "Please enter a word to remove: ";
      string word;
      cin >> word;
      tree.remove(word);
    }
  }
  return 0;
}

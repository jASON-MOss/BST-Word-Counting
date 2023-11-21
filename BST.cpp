/**
 * @file BST.cpp
 * @author Jason Moss
 * @date 2023-11-09
 * @brief Implements the BST class
 * 
 * Contains the code for the BST Class
 */

#include "BST.h"
#include "Node.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;



/**
 * constructor
 *
 * @pre 
 * @post 
 * 
 */
BST::BST(){
  root = NULL;
}


/**
 * deconstructor
 *
 * @pre 
 * @post 
 * 
 */
BST::~BST(){
  destructHelp(root);
}


/**
 * function designed to help deconstructor
 *
 * @param Node *current current spot in tree
 * @pre valid tree
 * @return void 
 * @post tree deconstructed
 * 
 */
void BST::destructHelp(Node *current){
  if(current == NULL){
    return;
  }
  if(current ->left != NULL){
    destructHelp(current ->left);
  }
  if(current ->right != NULL){
    destructHelp(current ->right);
  }
  delete current;
}


/**
 * sets new entry in tree
 *
 * @param string word word to be added to tree
 * @param int value the number that goes with that word
 * @pre valid entry
 * @return void 
 * @post word has been added
 * 
 */
void BST::set(string word, int value){
  if(root == NULL){
    root = new Node(word, value);
  }else{
    string inTree;
    string *exist = &inTree;
    countHelper(root, word, value, exist);
    if(*exist == "no"){
      insertHelp(root, word, value);
    }
  }
}


/**
 * function designed to help with inserting
 *
 * @param Node *current current spot in tree
 * @param string value number value
 * @param int num number
 * @pre 
 * @return void 
 * @post data has been added
 * 
 */
void BST::insertHelp(Node *current, string value, int num){
  if(current == NULL){
    return;
  }
    if(num < current ->data){
      if(current ->left == NULL){
	current ->left = new Node(value, num);
      }else{
	insertHelp(current ->left, value, num);
      }
    }else{
      if((*current).right == NULL){
	(*current).right = new Node(value, num);
      }else{
	insertHelp((*current).right, value, num);
      }
    }
}


/**
 * finds a string and shows its value
 *
 * @param string param word
 * @pre 
 * @return void 
 * @post word's number has been found
 * 
 */
void BST::find(string param){
  findHelp(root, param);
}


/**
 * helps with the find function
 *
 * @param Node *current current spot in tree
 * @param string param word
 * @pre valid tree
 * @return int number
 * @post word's number has been found
 * 
 */
int BST::findHelp(Node *current, string param){
  //findHelp(root, param);
  if(current == NULL){
    return 0;
  }else if(current ->Key == param){
    cout << current ->data << endl;
    return current ->data;
  }else{
    findHelp(current ->left, param);
    findHelp(current ->right, param);
    return 0;
  }
}


/**
 * looks through the tree to check if a word is already there
 *
 * @param Node *current spot to start from
 * @param string word word to look for
 * @param int val number
 * @param string *exist used to see if word is already in tree
 * @pre valid tree
 * @return void 
 * @post 
 * 
 */
void BST::countHelper(Node *current, string word, int val, string *exist){
  if(current == NULL){
    return;
  }
  string leftSearched;
  string rightSearched;
    if(current ->Key == word){
      *exist = "yes";
      return;
    }else{
      if(leftSearched != "yes"){
	if(current ->left == NULL){
	  leftSearched = "yes";
	}else{
	  countHelper(current ->left, word, val,exist);
	}
      }
      if(rightSearched != "yes"){
	if(current ->right == NULL){
	  rightSearched = "yes";
	}else{
	  countHelper(current ->right, word, val, exist);
	}
      }
    }
    if(rightSearched == "yes" && leftSearched == "yes"){
      string inTheTree = "no";
      *exist = "no";
      return;
    }
}

/**
 * prints tree
 *
 * @pre valid tree
 * @return void 
 * @post tree has been printed
 * 
 */
void BST::print(){
  printHelper(root);
  cout << endl;
}


/**
 * helps with the print function
 *
 * @param Node *current spot to start from
 * @pre valid tree
 * @return void 
 * @post tree has been printed
 * 
 */
void BST::printHelper(Node *current){
  if (current == NULL){
    return;
  }
  printHelper(current ->left);
  cout << current ->Key << current ->data << " ";
  printHelper(current ->right);
}


/**
 * finds smallest key in tree
 *
 * @pre valid tree
 * @return void 
 * @post 
 * 
 */
void BST::min(){
  minHelp(root);
}



/**
 * helps with min function
 *
 * @param Node *current spot to start from
 * @pre valid tree
 * @return void 
 * @post 
 * 
 */
void BST::minHelp(Node *current){
  if(current == NULL){
    return;
  }else if(current ->left == NULL){
    cout << "Min value: " << current ->Key << current ->data << endl;
    return;
  }else{
    minHelp(current ->left);
  }
}


/**
 * find rightmost key in tree
 *
 * @pre valid tree
 * @return void 
 * @post 
 * 
 */
void BST::max(){
  maxHelp(root);
}


/**
 * helps with max function
 *
 * @param Node *current spot to start from
 * @pre valid tree
 * @return void 
 * @post max found
 * 
 */
void BST::maxHelp(Node *current){
  if(current == NULL){
    return;
  }else if(current ->right == NULL){
    cout << "Max Value: " << current ->Key << current ->data << endl;
    return;
  }else{
    maxHelp(current ->right);
  }
}


/**
 * inserts file into tree
 *
 * @param string fileName name of file
 * @pre valid file
 * @return void 
 * @post file in tree
 * 
 */
void BST::save_file(string fileName){
  saveHelp(fileName);
}


/**
 * helps with file function
 *
 * @param string fileName name of file
 * @pre 
 * @return void 
 * @post file added in
 * 
 */
void BST::saveHelp(string fileName){
  ifstream myFile;
  myFile.open(fileName);
  int i = 1;
  while(!myFile.eof()){
    string word;
    myFile >> word;
    set(word, i);
    i = i + 1;
  }
  myFile.close();
}


/**
 * removes one word from tree
 *
 * @param string val word to remove
 * @pre 
 * @return void 
 * @post word removed
 * 
 */
void BST::remove(string val){
  deleteHelp(root, val);
}

/**
 * helps with remove function
 *
 * @param Node *&current spot to start from
 * @param string value word to remove
 * @pre 
 * @return void 
 * @post word removed
 * 
 */
void BST::deleteHelp(Node *&current, string value){
  if(current == NULL){
    return;
  }else if(current ->Key != value){
    deleteHelp(current ->left, value);
    deleteHelp(current ->right, value);
  }else if(current ->Key == value){
    Node *temp;
    temp = current;
    Node *replace;
    if(current ->left == NULL && current ->right != NULL){
      replace = current ->right;
      delete temp;
      current = replace;
    }else if(current ->left != NULL && current ->right == NULL){
      replace = current ->left;
      delete temp;
      current = replace;
    }else{
      replace = current ->left;
      delete temp;
      current = replace;
    }
  }
}

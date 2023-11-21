/**
 * @file BST.h
 * @author Jason Moss
 * @date 2023-11-09
 * @brief Contains protypes for the BST class
 * 
 * lists the prototypes for the BST class
 */

#ifndef BST_H
#define BST_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Node.h"
using namespace std;

class BST{
private:
  Node *root;
  void destructHelp(Node *current);
  void insertHelp(Node *current, string value, int num);//might need a string passed to it as well
  void deleteHelp(Node * &current, string value);//same as above and might need to be reworked
  void printHelper(Node *current);
  void minHelp(Node *current);
  void maxHelp(Node *current);
  void saveHelp(string fileName);
  void countHelper(Node *current, string word, int val, string *exist);
  int findHelp(Node *current, string param);
 public:
  BST();
  ~BST();
  void set(string word, int value);
  void find(string param);
  void print();
  void min();
  void max();
  void save_file(string fileName);
  void remove(string val);
};
#endif


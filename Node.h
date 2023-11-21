/**
 * @file Node.h
 * @author Jason Moss
 * @date 2023-11-09
 * @brief Contains Node prototypes
 * 
 * Contains prototypes for the Node Class
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Node{
 public:
  Node *left;
  Node *right;
  string Key;
  int data;
  Node(string key, int num);
};
#endif

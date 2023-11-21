/**
 * @file Node.cpp
 * @author Jason Moss
 * @date 2023-11-09
 * @brief Contains the code for the Node class
 * 
 * Contains the implementation for the Node class
 */

#include "Node.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
Node::Node(string key, int num){
  left = NULL;
  right = NULL;
  Key = key;
  data = num;
}

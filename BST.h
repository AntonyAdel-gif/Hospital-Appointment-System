#ifndef HOSPITAL_APPOINTMENT_SYSTEM_BST_H
#define HOSPITAL_APPOINTMENT_SYSTEM_BST_H

#include <iostream>
#include <string>
using namespace std;

class appointment {
   public:
      string patient_name;
      int priority_level;
      string medical_department;
      appointment *left;
      appointment *right;
      /*appointment() {
         left = NULL;
         right = NULL;
      */
};


class BST {
   private:
      appointment *root;

      void insert(appointment *& nodeptr, appointment *& newNode) {
         if (nodeptr == NULL) {
            nodeptr = newNode;
         }
         else if (newNode->priority_level < nodeptr->priority_level) {
            insert(nodeptr->left, newNode);
         }
         else {
            insert(nodeptr->right, newNode);
         }
      }
      void cancel_app(int num, appointment *& nodeptr) {
         if (nodeptr->priority_level > num) {
            cancel_app(num, nodeptr->right);
         }
         else if (nodeptr->priority_level < num) {
            cancel_app(num, nodeptr->left);
         }
         else {
            make_deletion(nodeptr);
         }
      }
      void make_deletion(appointment *& nodeptr) {

         appointment *temp_Node = new appointment;


         if (nodeptr == nullptr) {
            cout << "cannot delete empty appointment" << endl;
         }
         else if (nodeptr->right == nullptr) {
            temp_Node = nodeptr;
            nodeptr = nodeptr->left;
            temp_Node = nullptr;
         }
         else if (nodeptr->left == nullptr) {
            temp_Node = nodeptr;
            nodeptr = nodeptr->right;
            temp_Node = nullptr;
         }
         else {
            temp_Node =nodeptr->right;
            while (temp_Node->left) {
               temp_Node = temp_Node->left;
            }
            temp_Node->left = nodeptr->left;
            temp_Node = nodeptr;
            nodeptr = nodepyt->right;
            delete temp_Node;
         }
      }



   public:
      void insert_app(int num) {
         appointment * newNode = nullptr;
         newNode = new appointment;

         newNode->priority_level = num;
         newNode->left = nullptr;
         newNode->left = nullptr;
         insert(root, newNode);
      }

      void cancel(int num) {
         cancel_app(num, root)
      }

      void pre_order(appointment *r){};
      void post_order(appointment *r){};
      void in_order(appointment *r){};

};




#endif //HOSPITAL_APPOINTMENT_SYSTEM_BST_H
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

      void insert(appointment *& first_appoint, appointment *& new_appoint) {
         if (first_appoint == NULL) {
            first_appoint = new_appoint;
         }
         else if (new_appoint->priority_level < first_appoint->priority_level) {
            insert(first_appoint->left, new_appoint);
         }
         else {
            insert(first_appoint->right, new_appoint);
         }
      }
      void cancel_appoint(int num, appointment *& appoint) {
         if (appoint->priority_level > num) {
            cancel_appoint(num, appoint->right);
         }
         else if (appoint->priority_level < num) {
            cancel_appoint(num, appoint->left);
         }
         else {
            make_deletion(appoint);
         }
      }
      void make_deletion(appointment *& appoint) {

         appointment *temp_appoint = new appointment;


         if (appoint == nullptr) {
            cout << "cannot delete empty appointment" << endl;
         }
         else if (appoint->right == nullptr) {
            temp_appoint = appoint;
            appoint = appoint->left;
            temp_appoint = nullptr;
         }
         else if (appoint->left == nullptr) {
            temp_appoint = appoint;
            appoint = appoint->right;
            temp_appoint = nullptr;
         }
         else {
            temp_appoint = appoint->right;
            while (temp_appoint->left) {
               temp_appoint = temp_appoint->left;
            }
            temp_appoint->left = appoint->left;
            temp_appoint = appoint;
            appoint = appoint->right;
            delete temp_appoint;
         }
      }



   public:
      void insert_appoint(int num) {
         appointment * newNode = nullptr;
         newNode = new appointment;

         newNode->priority_level = num;
         newNode->left = nullptr;
         newNode->left = nullptr;
         insert(root, newNode);
      }

      void cancel_appoint(int num) {
         cancel_appoint(num, root);
      }

      void pre_order(appointment *r){};
      void post_order(appointment *r){};
      void in_order(appointment *r){};

};




#endif //HOSPITAL_APPOINTMENT_SYSTEM_BST_H
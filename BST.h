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

      void pre_order(appointment *r)
      {
         if (r == nullptr)
            return nullptr;
         else
         {
            cout<<"["<<r->patient_name<<", " <<r->priority_level<<", "<< r->medical_department << "]" <<endl;
            pre_order(r->left);
            pre_order(r->right);
         }
      };
      void post_order(appointment *r)
      {
         if (r ==nullptr)
            return nullptr;
         else
         {
            post_order(r->left);
            post_order(r->right);
            cout<<"["<<r->patient_name<<", " <<r->priority_level<<", "<< r->medical_department << "]" <<endl;
         }
      }
      void in_order(appointment *r)
      {
         if (r == nullptr)
            return nullptr;
         else
         {
            in_order(r->left);
            cout<<"["<<r->patient_name<<", " <<r->priority_level<<", "<< r->medical_department << "]" <<endl;
            in_order(r->left);

         }

      }
   appointment* Search(appointment* r, int key)
      {
         if (r == nullptr)
            return nullptr;
         else if (r->priority_level == key)
            return r;
         else if (key < r->priority_level)
            return Search(r->left, key);
         else
            return Search(r->right, key);
      }
   bool Search(int key)
      {
         appointment* result = Search(root, key);
         if (result==nullptr)
            return false;
         else
            return true;
      }

};




#endif //HOSPITAL_APPOINTMENT_SYSTEM_BST_H
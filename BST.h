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
};


class BST {
   private:
      appointment *root;

      void insert(appointment *& first_appoint, appointment *& new_appoint) {
         if (first_appoint == nullptr) {
            first_appoint = new_appoint;
         }
         else if (new_appoint->priority_level <= first_appoint->priority_level) {
            insert(first_appoint->left, new_appoint);
         }
         else {
            insert(first_appoint->right, new_appoint);
         }
      }


      void cancel_appoint(int num, appointment *& appoint, bool &flag) {
         if (appoint) {
            display_all(appoint->left);
            display_all(appoint->right);
            if (appoint->priority_level == num) {
               flag = true;
               cout<<"Cancelling appointment: ["<<appoint->patient_name<<", " <<appoint->priority_level<<", "<< appoint->medical_department << "]" <<endl;
               make_deletion(appoint);
            }
         }
      }


      void make_deletion(appointment *& appoint) {

         appointment *temp_appoint = nullptr;

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

      void display_all(appointment *r){ //in order
         if (r) {
            display_all(r->left);
            cout<<"["<<r->patient_name<<", " <<r->priority_level<<", "<< r->medical_department << "]" <<endl;
            display_all(r->right);
         }
      }

      void display_more_urgent(appointment* r, int num, bool &flag){
         if (r) {
            display_more_urgent(r->left, num, flag);
            if (r->priority_level <= num) {
               flag = true;
               cout << "[" << r->patient_name << ", "
                    << r->priority_level << ", "
                    << r->medical_department << "]" << endl;
            }
            display_more_urgent(r->right, num, flag);
         }
      }

      void display_less_urgent(appointment* r, int num, bool &flag){
         if (r) {
            display_less_urgent(r->left, num, flag);
            if (r->priority_level >= num)
               flag = true;
               cout << "[" << r->patient_name << ", "
                    << r->priority_level << ", "
                    << r->medical_department << "]" << endl;
            display_less_urgent(r->right, num, flag);
         }
      }


      void search_all(appointment *r, int key, bool &flag) {
         if (r == nullptr)
            return;

         if (key <= r->priority_level)
            search_all(r->left, key, flag);

         if (r->priority_level == key) {
            flag = true;
            cout<<"["<<r->patient_name<<", " <<r->priority_level<<", "<< r->medical_department << "]" <<endl;
         }
         if (key >= r->priority_level)
            search_all(r->right, key, flag);
      }

   public:

      BST() {
         root = nullptr;
      }

      void insert_appoint(int num , string n, string dep) {
         appointment * new_appoint = nullptr;
         new_appoint = new appointment;

         new_appoint->priority_level = num;
         new_appoint->medical_department = dep;
         new_appoint->patient_name = n;
         new_appoint->left = nullptr;
         new_appoint->left = nullptr;
         insert(root, new_appoint);
      }



      void cancel_appoint(int num) {
         if (root == nullptr) {
            cout << "No appointments in system to cancel" << endl;
            return;
         }
         bool found = false;
         cancel_appoint(num, root, found);
         if (found != true) {
            cout << "No appointment found with priority: " << num << endl;
         }
      }

      void display_all() {
         if (root == nullptr) {
            cout << "No appointments in system to display" << endl;
            return;
         }
         display_all(root);
      }

      void display_more_urgent(int num) {
         if (root == nullptr) {
            cout << "No appointments in system to display" << endl;
            return;
         }
         bool found = false;
         display_more_urgent(root, num, found);
         if (found != true) {
            cout << "No appointment found with priority level more urgent than: " << num << endl;
         }
      }

      void display_less_urgent(int num) {
         if (root == nullptr) {
            cout << "No appointments in system to display" << endl;
            return;
         }
         bool found = false;
         display_less_urgent(root, num, found);

         if (found != true) {
            cout << "No appointment found with priority level less urgent than: " << num << endl;
         }
      }



      void search_all(int key) {
         if (root == nullptr) {
            cout << "No appointments in system to search" << endl;
         }
         bool found = false;
         search_all(root, key, found);

         if (found != true) {
            cout << "No appointment found with priority level: " << key << endl;
         }
      }

};
#endif //HOSPITAL_APPOINTMENT_SYSTEM_BST_H

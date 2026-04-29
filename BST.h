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

      void insert(appointment *& nodeptr, appointment *& newNode){};
      void cance_app(int num, appointment *& newNode){};

   public:
      void insert_app(int num){};
      void cancel(int num){};

      void pre_order(appointment *r){};
      void post_order(appointment *r){};
      void in_order(appointment *r){};



};




#endif //HOSPITAL_APPOINTMENT_SYSTEM_BST_H
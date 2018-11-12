#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>


#include"observer.h"

 class Subject {
  std::vector<Observer*> observers;

 public:
  void attach(Observer *o);  
  void notifyObservers();
};

void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}


void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}


#endif

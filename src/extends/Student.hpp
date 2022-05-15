#pragma once

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>

using namespace std;

enum Specialty
{
  ME,
  MF,
  FI,
  INF,
  KN,
};

#pragma pack(push, 1)
struct Student
{
  std::string lastName;
  unsigned rank;
  Specialty specialty;
  unsigned physics;
  unsigned mathematics;
  union
  {
    unsigned programing;
    unsigned numMethods;
    unsigned pedagogy;
  };
};
#pragma pack(pop)

#endif // !STUDENT_H_
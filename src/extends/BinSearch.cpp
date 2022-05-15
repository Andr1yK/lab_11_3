#pragma once

#ifndef _BINSEARCH_
#define _BINSEARCH_

#include <fstream>

#include "./FileHelper.cpp"
#include "./Student.hpp"
#include "./getCondition.cpp"

int BinSearch(
  char* fname, const int N,
  const string lastName, const unsigned rank, const unsigned physics
) {
  int left = 0, right = N - 1, mid;
  Student student;
  ifstream f(fname, ios::binary);

  do {
    mid = (int)((left + right) / 2);
    student = FileHelper::fRead<Student>(f, mid);

    if (student.lastName == lastName && student.rank == rank && student.physics == physics)
      return mid;

    if (getCondition(
      student.physics, student.rank, student.lastName,
      physics, rank, lastName
    ))
      left = mid + 1;
    else
      right = mid - 1;

  } while (left <= right);

  return -1;
}

#endif

#pragma once

#ifndef _SORTBIN_
#define _SORTBIN_

#include <iostream>

#include "./FileHelper.cpp"
#include "./Student.hpp"
#include "./getCondition.cpp"

void SortBIN(char* fname, const int N) {
  fstream f(fname, ios::binary | ios::in | ios::out);

  f.seekg(0, ios::end);

  f.seekg(0, ios::beg);
  for (int i = 1; i<N; i++)
    for (int j = 0; j<N-i; j++) {
      Student current = FileHelper::fRead<Student>(f, j);
      Student prev = FileHelper::fRead<Student>(f, j+1);

      if (getCondition(
        prev.physics, prev.rank, prev.lastName,
        current.physics, current.rank, current.lastName
      )) FileHelper::fChange<Student>(f, j, j+1);
    }

  f.seekp(0, ios::end);
}

#endif

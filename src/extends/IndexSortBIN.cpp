#pragma once

#ifndef _INDEXSORTBIN_
#define _INDEXSORTBIN_

#include "./FileHelper.cpp"
#include "./Student.hpp"
#include "./getCondition.cpp"

void IndexSortBIN(char* fname, char* fname_res, const int N) {
  ifstream f(fname, ios::binary);

  int* sorted = new int[N];
  for (int i = 0; i < N; i++)
    sorted[i] = i;

  int index, j, key;

  for (index = 1; index < N; index++)
  {
    key = sorted[index];
    Student current = FileHelper::fRead<Student>(f, key);

    for (j = index - 1; j >= 0; j--) {
      Student prev = FileHelper::fRead<Student>(f, sorted[j]);

      if(getCondition(
          prev.physics, prev.rank, prev.lastName,
          current.physics, current.rank, current.lastName
      )) sorted[j + 1] = sorted[j];
      else break;
    }

    sorted[j + 1] = key;
  }

  f.close();

  ofstream f_res(fname_res, ios::binary);

  for (size_t i = 0; i < N; i++) {
    FileHelper::fWrite(f_res, i, sorted[i]);
  }
}

#endif

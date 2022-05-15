#pragma once

#ifndef _CREATEBIN_
#define _CREATEBIN_
#include <fstream>
#include "./Student.hpp"
#include "./FileHelper.cpp"

using namespace std;

void CreateBIN(char* fname, Student* students, const int N) {
  ofstream fout(fname, ios::binary);

  for (size_t i = 0; i < N; i++)
    FileHelper::fWrite(fout, i, students[i]);
}
#endif

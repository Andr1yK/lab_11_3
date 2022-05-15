#pragma once

#ifndef _PRINTBIN_
#define _PRINTBIN_
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "./Student.hpp"
#include "./FileHelper.cpp"

using namespace std;

void PrintHeder() {
  #pragma region Header
  cout << "============================================================================================================" << endl;

  cout << "| " << setw(2) << "№ " << " | "
    << setw(12) << left << "Lastname" << " | "
    << setw(4) << "Rank" << " | "
    << setw(20) << "Specialty" << " | "
    << setw(7) << "Physics" << " | "
    << setw(5) << "Math." << " | "
    << setw(10) << "Programing" << " | "
    << setw(12) << "Num. methods" << " | "
    << setw(8) << "Pedagogy" << " |"
    << endl;

  cout << "------------------------------------------------------------------------------------------------------------" << endl;
  #pragma endregion
}

void PrintRow(
  Student student,
  string* specialtyList,
  int index,
  int countRows
) {
  cout << "|" << setw(2) << right << index + 1 << " "
    << " | " << setw(12) << left << student.lastName
    << " | " << setw(4) << right << student.rank
    << " | " << setw(20) << left << specialtyList[student.specialty]
    << " | " << setw(7) << right << student.physics
    << " | " << setw(5) << right << student.mathematics;

  switch (student.specialty)
  {
  case KN:
    cout << " | " << setw(10) << right << student.programing
      << " | " << setw(15)
      << " | " << setw(10)
      << " |"
      << endl;
    break;

  case INF:
    cout << " | " << setw(13)
      << " | " << setw(12) << right << student.numMethods
      << " | " << setw(10)
      << " |"
      << endl;
    break;

  default:
    cout << " | " << setw(13)
      << " | " << setw(15)
      << " | " << setw(8) << right << student.pedagogy
      << " |"
      << endl;
  }

  if (index + 1 < countRows) {
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
  }
}

void PrintBIN(
  char* filename, const int N, 
  string* specialtyList,
  char* sortedIndex_fname = nullptr
) {
  PrintHeder();

  ifstream fromFile(filename, ios::binary);
  ifstream fromFile_indexes;
  if (sortedIndex_fname != nullptr) {
    fromFile_indexes.open(sortedIndex_fname, ios::binary);
  }
  int index;

  for (int i = 0; i < N; i++) {
    if (sortedIndex_fname != nullptr) {
      index = FileHelper::fRead<int>(fromFile_indexes, i);
    } else {
      index = i;
    }

    PrintRow(
      FileHelper::fRead<Student>(fromFile, index),
      specialtyList,
      i,
      N
    );
  }

  cout << "============================================================================================================"
    << endl << endl;
}

#endif

#include <gtest/gtest.h>
#include <fstream>
#include <string>

#include "../src/extends/Student.hpp"
#include "../src/extends/SortBIN.cpp"
#include "../src/extends/FileHelper.cpp"
#include "../src/extends/IndexSortBIN.cpp"
#include "../src/extends/BinSearch.cpp"

using namespace std;

struct WorkWithFile : public testing::Test
{
  char input_fname[30] = "unittests.temp";
  char input_fname_indexes[30] = "unittests_indexes.temp";

  ofstream fout;
  const int N = 10;

  Student excepted[10] = {
    {"Tkachenko", 4, FI,  5, 5, 2},
    {"Petrenko",  1, ME,  5, 4, 2},
    {"Tkachuk",   4, INF, 4, 3, 4},
    {"Savchenko", 4, MF,  4, 3, 5},
    {"Lysenko",   2, INF, 4, 5, 3},
    {"Moroz",     1, KN,  4, 4, 5},
    {"Koval",     3, KN,  3, 3, 3},
    {"Rudenko",   1, INF, 3, 5, 5},
    {"Boyko",     5, FI,  2, 4, 4},
    {"Melnyk",    3, FI,  1, 3, 5},
  };

  Student students[10] = {
    {"Moroz",     1, KN,  4, 4, 5},
    {"Tkachuk",   4, INF, 4, 3, 4},
    {"Petrenko",  1, ME,  5, 4, 2},
    {"Koval",     3, KN,  3, 3, 3},
    {"Tkachenko", 4, FI,  5, 5, 2},
    {"Rudenko",   1, INF, 3, 5, 5},
    {"Boyko",     5, FI,  2, 4, 4},
    {"Savchenko", 4, MF,  4, 3, 5},
    {"Lysenko",   2, INF, 4, 5, 3},
    {"Melnyk",    3, FI,  1, 3, 5},
  };

  void SetUp() override {
    fout.open(input_fname);

    for (size_t i = 0; i < N; i++)
      fout.write((char*)&students[i], sizeof(students[i]));

    fout.close();

    fout.open(input_fname_indexes);

    for (size_t i = 0; i < N; i++)
      fout.write((char*)&students[i], sizeof(students[i]));

    fout.close();
  }

  void TearDown() override {
    remove(input_fname);
    remove(input_fname_indexes);
  }
};


TEST_F(WorkWithFile, SortBIN) {
  SortBIN(input_fname, N);

  ifstream f(input_fname);

  for(int i = 0; i < N; i++)
    EXPECT_EQ(FileHelper::fRead<Student>(f, i).lastName, excepted[i].lastName);
  
  f.close();
}

TEST_F(WorkWithFile, SortIndexes) {
  IndexSortBIN(input_fname, input_fname_indexes, N);

  ifstream f_indexes(input_fname_indexes);
  ifstream f_data(input_fname);

  int index = 0;

  for(int i = 0; i < N; i++) {
    index = FileHelper::fRead<int>(f_indexes, i);

    EXPECT_EQ(FileHelper::fRead<Student>(f_data, index).lastName, excepted[i].lastName);
  }

  f_indexes.close();
  f_data.close();
}

TEST_F(WorkWithFile, BinSearch) {
  SortBIN(input_fname, N);

  int index = BinSearch(input_fname, N, "Boyko", 5, 2);

  ifstream f(input_fname);

  EXPECT_EQ(index, 8);
  
  f.close();
}

TEST_F(WorkWithFile, BinSearchNotFound) {
  SortBIN(input_fname, N);
  
  int index = BinSearch(input_fname, N, "Boyko", 0, 0);

  ifstream f(input_fname);

  EXPECT_EQ(index, -1);

  f.close();
}
#include <iostream>

#include "./extends/Student.hpp"

#include "./extends/CreateBIN.cpp"
#include "./extends/PrintBIN.cpp"
#include "./extends/SortBIN.cpp"
#include "./extends/IndexSortBIN.cpp"
#include "./extends/BinSearch.cpp"

using namespace std;

int main()
{
  string specialtyList[] = {
    "Math and economics",
    "Craft",
    "Physics and inform.",
    "Informatics",
    "Computer science"
  };

  const int N = 10;

  Student students[N] = {
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

  char fname[100] = "test";
  char fname_indexes[100] = "";
  cout << "Enter file name: "; cin >> fname;

  strcat(fname_indexes, fname);
  strcat(fname_indexes, "_indexes");

  CreateBIN(fname, students, N);

  string findLastName;
  unsigned findRank;
  int findPhysics;
  int found;

  int menuItem;
  do {
    cout << endl << endl;
    cout << "Виберіть дію:" << endl << endl;
    cout << " [1] - вивід даних на екран" << endl;
    cout << " [2] - фізичне впорядкування даних" << endl;
    cout << " [3] - індексне впорядкування та вивід даних" << endl;
    cout << " [4] - бінарний пошук студента за прізвищем, курсом та оцінкою з фізики" << endl;

    cout << endl;

    cout << " [0] - вихід та завершення роботи програми" << endl << endl;
    cout << "Введіть значення: "; cin >> menuItem;
    cout << endl << endl << endl;
    
    switch (menuItem)
    {
    case 1:
      PrintBIN(fname, N, specialtyList);
      break;

    case 2:
      SortBIN(fname, N);

      PrintBIN(fname, N, specialtyList);
      break;
    case 3:
      IndexSortBIN(fname, fname_indexes, N);

      PrintBIN(fname, N, specialtyList, fname_indexes);
      break;
    case 4:
      cin.get();
      cin.sync();

      cout << "Введіть ключі пошуку:" << endl;
      cout << " прізвище: "; getline(cin, findLastName);

      cout << " курс: "; cin >> findRank;
      cout << endl;

      cout << " оцінка з фізики: "; cin >> findPhysics;
      cout << endl;

      SortBIN(fname, N);

      if ((found = BinSearch(fname, N, findLastName, findRank, findPhysics)) != -1)
        cout << "Знайдено студента в позиції " << found + 1 << endl;
      else
        cout << "Шуканого студента не знайдено" << endl;

      break;
    case 0:
      break;

    default:
      cout << "Ви ввели помилкове значення! "
        "Слід ввести число - номер вибраного пункту меню" << endl;
    }
  } while (menuItem != 0);

  return 0;
}
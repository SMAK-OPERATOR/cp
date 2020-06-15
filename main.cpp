// 2 �������
#include "input.hpp"

int const n = 3;

struct man {
  string surname;
  string name;
  long long int number;
  int date[3];
};

man people[n];

void add(int m) {
  for (int i = 0; i < m; i++) {
    cout << "Person's data:" << endl;
    cout << "Surname-";
    fflush(stdin);
    people[i].surname = get_char();
    cout << "Name-";
    people[i].name = get_char();
    cout << "Enter phone number:";
    people[i].number = get_long_int();
    cout << "Date of birth (in format \"year month day\")-";
    for (int j = 0; j < 3; j++) {
      switch (j) {
        case 0:
          cout << "Enter year:";
          break;
        case 1:
          cout << "Enter month:";
          break;
        case 2:
          cout << "Enter day:";
          break;
      }
      people[i].date[j] = get_int();
      if (j == 0 && (people[i].date[j] < 0 || people[i].date[j] > 2020)) {
        cout << "Year can not be less than 0 and more than 2020, try again"
             << endl;
        j--;
      }
      if (j == 1 && (people[i].date[j] < 1 || people[i].date[j] > 12)) {
        cout << "Month can not be less than 1 and more than 12, try again"
             << endl;
        j--;
      }
      if (j == 2 && (people[i].date[j] < 1 || people[i].date[j] > 31)) {
        cout << "Day can not be less than 1 and more than 31, try again"
             << endl;
        j--;
      }
    }
  }
}

void view_1() {
  int k = 1;
  long long int m;
  while (k == 1) {
    while (true) {
      cout << "Enter number:" << endl;
      cin >> m;
      if (!cin) {
        cout << "Invalid input, try again" << endl;
        cin.clear();
        while (cin.get() != '\n')
          ;
      } else
        break;
    }
    for (int i = 0; i < n; i++) {
      if (m == people[i].number) {
        cout << people[i].surname << ' ' << people[i].name << ' '
             << people[i].number << ' ' << people[i].date[0] << '.'
             << people[i].date[1] << '.' << people[i].date[2] << endl;
        k--;
      }
    }
    if (k == 1) {
      cout << "Person not found! " << endl;
    }
  }
}

void view_all() {
  man buf;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (people[j].date[0] * 10000 + people[j].date[1] * 100 +
              people[j].date[2] <
          people[j + 1].date[0] * 10000 + people[j + 1].date[1] * 100 +
              people[j + 1].date[2]) {
        buf = people[j];
        people[j] = people[j + 1];
        people[j + 1] = buf;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << people[i].surname << ' ';
    cout << people[i].date[0] << '.' << people[i].date[1] << '.'
         << people[i].date[2] << endl;
  }
}

int main() {
  int k = 1, a;
  add(n);
  while (k != 0) {
    cout << "________________________________________________" << endl;
    cout << "Menu" << endl
         << "View all notes (sorted by birth date) <<1>>" << endl
         << "View particular note (search by phone number) <<2>>" << endl
         << "Exit <<0>>" << endl;
    cout << "________________________________________________" << endl;
    while (true) {
      cin >> a;
      if (!cin) {
        cout << "Invalid input, try using int values" << endl;
        cin.clear();
        while (cin.get() != '\n')
          ;
      } else
        break;
    }
    switch (a) {
      case 0:
        system("pause");
        return 0;
      case 1:
        view_all();
        break;
      case 2:
        view_1();
        break;
      default:
        break;
    }
  }
  return 0;
}
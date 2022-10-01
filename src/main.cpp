
#include <iostream>
#include <string>
#include "converter.hpp"

using namespace std;

int main () {
  Converter converter;
  char exit = 'n';

  while (exit == 'n') {
    double input;

    cout << "Enter number to convert to words: ";
    cin >> input;

    string words = converter.convert(input);
    cout << "Converted: " << words << endl;

    cout << "Exit? [Y/n]" << endl;
    cin >> exit;
  }

  return 0;
}

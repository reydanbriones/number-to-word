
#include <string>
#include <cmath>
#include "converter.hpp"

using namespace std;

Converter::Converter () {}

string Converter::convert (double input) {
  string words;

  const string ones[] = {
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine"
  };

  const string tens[] = {
    "Ten",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety"
  };

  const string teens[] = {
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen"
  };

  const string addons[] = {
    "Billion",
    "Million",
    "Thousand",
    ""
  };

  /**
   *  Split number every 3 digit then parse each split by adding additional word
   *  such as thousand, million, etc...
   *  eg. 1234567 -> 1 million 234 thousand 567
   */
  unsigned int add = -1;
  for (double i = 100000000000; i >= 100; i /= 1000) {
    add++;
    if (input < (i / 100)) continue;

    string split_word = "";

    // C/C++ "%" only supports integers
    int h = fmod(input, i * 10) / i;
    int t = fmod(input, i) / (i / 10);
    int o = fmod(input, i / 10) / (i / 100);

    if (h > 0) split_word += ones[h - 1] + " Hundred ";

    // Make an exception for teens eg. fourteen, fifteen, etc.
    if (t == 1 && o != 0) {
      split_word += teens[o - 1] + " ";
    } else {
      if (t > 0) split_word += tens[t - 1] + " ";
      if (o > 0) split_word += ones[o - 1] + " ";
    }

    if (h > 0 || t > 0 || o > 0) {
      split_word += addons[add] + " ";
    }

    words += split_word;
  }

  return words;
}

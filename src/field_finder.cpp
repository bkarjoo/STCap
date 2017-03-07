#include "field_finder.h"
#include "field.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;



void field_finder::update(shared_ptr<message> m)
{
  // get the vector
  vector<shared_ptr<field>>& fields = m->get_fields();


  for (auto& a : fields) {
      char c = a->get_char_code();
      int code = a->get_char_code_value();
      switch (c) {
        case 'a':
          count.a++;
          break;
        case 'b':
          count.b++;
          break;
        case 'c':
          count.c++;
          break;
        case 'd':
          count.d++;
          break;
        case 'e':
          count.e++;
          break;
        case 'f':
          count.f++;
          count.fcodes[code]++;
          break;
        case 'g':
          count.g++;
          count.gcodes[code]++;
          break;
        case 'h':
          count.h++;
          break;
        case 'i':
          count.i++;
          break;
        case 'j':
          count.j++;
          break;
        case 'k':
          count.k++;
          break;
        case 'l':
          count.l++;
          break;
        case 'm':
          count.m++;
          break;
        case 'n':
          count.n++;
          break;
        case 'o':
          count.o++;
          break;
        case 'p':
          count.p++;
          break;
        case 'q':
          count.q++;
          break;
        case 'r':
          count.r++;
          break;
        case 's':
          count.s++;
          break;
        case 't':
          count.t++;
          break;
        case 'u':
          count.u++;
          break;
        case 'v':
          count.v++;
          break;
        case 'w':
          count.w++;
          break;
        case 'x':
          count.x++;
          break;
        case 'y':
          count.y++;
          break;
        case 'z':
          count.z++;
          switch (code) {
            case 237:
              count.z237++;
              break;
            case 243:
              count.z243++;
              break;
            case 244:
              count.z244++;
              break;
            case 245:
              count.z245++;
              break;
            case 258:
              count.z258++;
              break;
            case 650:
              count.z650++;
              break;
            case 941:
              count.z941++;
              break;
            case 942:
              count.z942++;
              break;
            case 943:
              count.z943++;
              break;
          }
          break;
      }
  }

}

void field_finder::print_counts_to_cout()
{
  cout << "a," << count.a << endl;
  cout << "b," << count.b << endl;
  cout << "c," << count.c << endl;
  cout << "d," << count.d << endl;
  cout << "e," << count.e << endl;
  cout << "f," << count.f << endl;
  for (int i = 1; i <= 100; ++i)
  cout << "f" << i << "," << count.fcodes[i] << endl;
  cout << "g," << count.g << endl;
  for (int i = 1; i <= 100; ++i)
  cout << "g" << i << "," << count.gcodes[i] << endl;
  cout << "h," << count.h << endl;
  cout << "i," << count.i << endl;
  cout << "j," << count.j << endl;
  cout << "k," << count.k << endl;
  cout << "l," << count.l << endl;
  cout << "m," << count.m << endl;
  cout << "n," << count.n << endl;
  cout << "o," << count.o << endl;
  cout << "p," << count.p << endl;
  cout << "q," << count.q << endl;
  cout << "r," << count.r << endl;
  cout << "s," << count.s << endl;
  cout << "t," << count.t << endl;
  cout << "u," << count.u << endl;
  cout << "v," << count.v << endl;
  cout << "w," << count.w << endl;
  cout << "x," << count.x << endl;
  cout << "y," << count.y << endl;
  cout << "z," << count.z << endl;
}

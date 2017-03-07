#include "field.h"
#include <string>
#include <iostream> // for testing
using std::string;
using std::cout;
using std::endl;

void field::add_char(const char& c)
{
  /* field grammar :
   * field delimiter may be one or two chars (set by constructor)
   * field delimiter is followed by one or two values
   * if it's followed by two values it's separated by a comma
   */
   if (c == ',') {
      comma_encountered = true;
   } else if (!comma_encountered) {
      first_value_str += c;
   } else {
      second_value_str += c;
   }
}

bool field::is_single_char()
{
  return first_value_str == "" && second_value_str == "" && char_code_value == 0 && value == "";
}

void field::on_field_complete()
{
  if (first_value_str.length() == 0 && second_value_str.length() == 0) return;

  try {
    if (comma_encountered) {
      // second value is real value
      //cout << "FIRST STOI: " << first_value_str << endl;
      if (first_value_str != "") char_code_value = stoi(first_value_str);
      value.swap(second_value_str);
    } else {
      value.swap(first_value_str);
    }
  } catch (const std::invalid_argument& ia) {
  } catch (const std::out_of_range& oor) {
  } catch (...) {
  }
}

const string& field::get_field_str()
{
  if (all_chars != "") return all_chars;

  all_chars += char_code;
  if (exchange_code != 0) all_chars += exchange_code;
  if (comma_encountered) all_chars += first_value_str;
  if (comma_encountered) all_chars += ',';
  all_chars += value;
  return all_chars;
}

field_name field::get_all_field_name(const char& char_code, const int& char_code_value) const {
  switch (char_code) {
    case 'a':
      return field_name::a;
      break;
    case 'b':
      return field_name::b;
      break;
    case 'c':
      return field_name::c;
      break;
    case 'd':
      return field_name::d;
      break;
    case 'e':
      return field_name::e;
      break;
    case 'f':
      return comma_encountered ? get_f_field_name(char_code_value) : field_name::f;
      break;
    case 'g':
      return comma_encountered ? get_g_field_name(char_code_value) : field_name::g;
      break;
    case 'h':
      return field_name::h;
      break;
    case 'i':
      return field_name::i;
      break;
    case 'j':
      return field_name::j;
      break;
    case 'k':
      return field_name::k;
      break;
    case 'l':
      return field_name::l;
      break;
    case 'm':
      return field_name::m;
      break;
    case 'n':
      return field_name::n;
      break;
    case 'o':
      return field_name::o;
      break;
    case 'p':
      return field_name::p;
      break;
    case 'q':
      return field_name::q;
      break;
    case 'r':
      return field_name::r;
      break;
    case 's':
      return field_name::s;
      break;
    case 't':
      return field_name::t;
      break;
    case 'u':
      return field_name::u;
      break;
    case 'v':
      return field_name::v;
      break;
    case 'w':
      return field_name::w;
      break;
    case 'x':
      return field_name::x;
      break;
    case 'y':
      return field_name::y;
      break;
    case 'z':
      return field_name::z;
      break;
  }
}

field_name field::get_f_field_name(const int& char_code_value) const {
  switch (char_code_value) {
    case 10 ... 19:
      switch (char_code_value) {
        case 10:
          return field_name::f10;
          break;
        case 11:
          return field_name::f11;
          break;
        case 12:
          return field_name::f12;
          break;
        case 13:
          return field_name::f13;
          break;
        case 14:
          return field_name::f14;
          break;
        case 15:
          return field_name::f15;
          break;
        case 16:
          return field_name::f16;
          break;
        case 17:
          return field_name::f17;
          break;
        case 18:
          return field_name::f18;
          break;
        case 19:
          return field_name::f19;
          break;
      }
      break;
    case 20 ... 29:
      switch (char_code_value) {
        case 20:
          return field_name::f20;
          break;
        case 21:
          return field_name::f21;
          break;
        case 22:
          return field_name::f22;
          break;
        case 23:
          return field_name::f23;
          break;
        case 24:
          return field_name::f24;
          break;
        case 25:
          return field_name::f25;
          break;
        case 26:
          return field_name::f26;
          break;
        case 27:
          return field_name::f27;
          break;
        case 28:
          return field_name::f28;
          break;
        case 29:
          return field_name::f29;
          break;
      }
      break;
    case 30 ... 39:
      switch (char_code_value) {
        case 30:
          return field_name::f30;
          break;
        case 31:
          return field_name::f31;
          break;
        case 32:
          return field_name::f32;
          break;
        case 33:
          return field_name::f33;
          break;
        case 34:
          return field_name::f34;
          break;
        case 35:
          return field_name::f35;
          break;
        case 36:
          return field_name::f36;
          break;
        case 37:
          return field_name::f37;
          break;
        case 38:
          return field_name::f38;
          break;
        case 39:
          return field_name::f39;
          break;
      }
      break;
    case 40 ... 49:
      switch (char_code_value) {
        case40:
          return field_name::f40;
          break;
        case41:
          return field_name::f41;
          break;
        case42:
          return field_name::f42;
          break;
        case43:
          return field_name::f43;
          break;
        case44:
          return field_name::f44;
          break;
        case45:
          return field_name::f45;
          break;
        case46:
          return field_name::f46;
          break;
        case47:
          return field_name::f47;
          break;
        case48:
          return field_name::f48;
          break;
        case49:
          return field_name::f49;
          break;
      }
      break;
    case 50 ... 59:
      switch (char_code_value) {
        case 50:
          return field_name::f50;
          break;
        case 51:
          return field_name::f51;
          break;
        case 52:
          return field_name::f52;
          break;
        case 53:
          return field_name::f53;
          break;
        case 54:
          return field_name::f54;
          break;
        case 55:
          return field_name::f55;
          break;
        case 56:
          return field_name::f56;
          break;
        case 57:
          return field_name::f57;
          break;
        case 58:
          return field_name::f58;
          break;
        case 59:
          return field_name::f59;
          break;
      }
      break;
    case 60 ... 69:
      switch (char_code_value) {
        case 60:
          return field_name::f60;
          break;
        case 61:
          return field_name::f61;
          break;
        case 62:
          return field_name::f62;
          break;
        case 63:
          return field_name::f63;
          break;
        case 64:
          return field_name::f64;
          break;
        case 65:
          return field_name::f65;
          break;
        case 66:
          return field_name::f66;
          break;
        case 67:
          return field_name::f67;
          break;
        case 68:
          return field_name::f68;
          break;
        case 69:
          return field_name::f69;
          break;
      }
      break;
    case 70 ... 79:
      switch (char_code_value) {
        cas70:
          return field_name::f70;
          break;
        cas71:
          return field_name::f71;
          break;
        cas72:
          return field_name::f72;
          break;
        cas73:
          return field_name::f73;
          break;
        cas74:
          return field_name::f74;
          break;
        cas75:
          return field_name::f75;
          break;
        cas76:
          return field_name::f76;
          break;
        cas77:
          return field_name::f77;
          break;
        cas78:
          return field_name::f78;
          break;
        cas79:
          return field_name::f79;
          break;
      }
      break;
    case 80 ... 89:
      switch (char_code_value) {
        case 80:
          return field_name::f80;
          break;
        case 81:
          return field_name::f81;
          break;
        case 82:
          return field_name::f82;
          break;
        case 83:
          return field_name::f83;
          break;
        case 84:
          return field_name::f84;
          break;
        case 85:
          return field_name::f85;
          break;
        case 86:
          return field_name::f86;
          break;
        case 87:
          return field_name::f87;
          break;
        case 88:
          return field_name::f88;
          break;
        case 89:
          return field_name::f89;
          break;
      }
      break;
    case 90 ... 99:
      switch (char_code_value) {
        case 90:
          return field_name::f90;
          break;
        case 91:
          return field_name::f91;
          break;
        case 92:
          return field_name::f92;
          break;
        case 93:
          return field_name::f93;
          break;
        case 94:
          return field_name::f94;
          break;
        case 95:
          return field_name::f95;
          break;
        case 96:
          return field_name::f96;
          break;
        case 97:
          return field_name::f97;
          break;
        case 98:
          return field_name::f98;
          break;
        case 99:
          return field_name::f99;
          break;
      }
      break;
  }
}

field_name field::get_g_field_name(const int& char_code_value) const {
  switch (char_code_value) {
    case 10 ... 19:
      switch (char_code_value) {
        case 10:
          return field_name::g10;
          break;
        case 11:
          return field_name::g11;
          break;
        case 12:
          return field_name::g12;
          break;
        case 13:
          return field_name::g13;
          break;
        case 14:
          return field_name::g14;
          break;
        case 15:
          return field_name::g15;
          break;
        case 16:
          return field_name::g16;
          break;
        case 17:
          return field_name::g17;
          break;
        case 18:
          return field_name::g18;
          break;
        case 19:
          return field_name::g19;
          break;
      }
      break;
    case 20 ... 29:
      switch (char_code_value) {
        cas20:
          return field_name::g20;
          break;
        cas21:
          return field_name::g21;
          break;
        cas22:
          return field_name::g22;
          break;
        cas23:
          return field_name::g23;
          break;
        cas24:
          return field_name::g24;
          break;
        cas25:
          return field_name::g25;
          break;
        cas26:
          return field_name::g26;
          break;
        cas27:
          return field_name::g27;
          break;
        cas28:
          return field_name::g28;
          break;
        cas29:
          return field_name::g29;
          break;
      }
      break;
    case 30 ... 39:
      switch (char_code_value) {
        case 30:
          return field_name::g30;
          break;
        case 31:
          return field_name::g31;
          break;
        case 32:
          return field_name::g32;
          break;
        case 33:
          return field_name::g33;
          break;
        case 34:
          return field_name::g34;
          break;
        case 35:
          return field_name::g35;
          break;
        case 36:
          return field_name::g36;
          break;
        case 37:
          return field_name::g37;
          break;
        case 38:
          return field_name::g38;
          break;
        case 39:
          return field_name::g39;
          break;
      }
      break;
    case 40 ... 49:
      switch (char_code_value) {
        case40:
          return field_name::g40;
          break;
        case41:
          return field_name::g41;
          break;
        case42:
          return field_name::g42;
          break;
        case43:
          return field_name::g43;
          break;
        case44:
          return field_name::g44;
          break;
        case45:
          return field_name::g45;
          break;
        case46:
          return field_name::g46;
          break;
        case47:
          return field_name::g47;
          break;
        case48:
          return field_name::g48;
          break;
        case49:
          return field_name::g49;
          break;
      }
      break;
    case 50 ... 59:
      switch (char_code_value) {
        case 50:
          return field_name::g50;
          break;
        case 51:
          return field_name::g51;
          break;
        case 52:
          return field_name::g52;
          break;
        case 53:
          return field_name::g53;
          break;
        case 54:
          return field_name::g54;
          break;
        case 55:
          return field_name::g55;
          break;
        case 56:
          return field_name::g56;
          break;
        case 57:
          return field_name::g57;
          break;
        case 58:
          return field_name::g58;
          break;
        case 59:
          return field_name::g59;
          break;
      }
      break;
    case 60 ... 69:
      switch (char_code_value) {
        case 60:
          return field_name::g60;
          break;
        case 61:
          return field_name::g61;
          break;
        case 62:
          return field_name::g62;
          break;
        case 63:
          return field_name::g63;
          break;
        case 64:
          return field_name::g64;
          break;
        case 65:
          return field_name::g65;
          break;
        case 66:
          return field_name::g66;
          break;
        case 67:
          return field_name::g67;
          break;
        case 68:
          return field_name::g68;
          break;
        case 69:
          return field_name::g69;
          break;
      }
      break;
    case 70 ... 79:
      switch (char_code_value) {
        cas70:
          return field_name::g70;
          break;
        cas71:
          return field_name::g71;
          break;
        cas72:
          return field_name::g72;
          break;
        cas73:
          return field_name::g73;
          break;
        cas74:
          return field_name::g74;
          break;
        cas75:
          return field_name::g75;
          break;
        cas76:
          return field_name::g76;
          break;
        cas77:
          return field_name::g77;
          break;
        cas78:
          return field_name::g78;
          break;
        cas79:
          return field_name::g79;
          break;
      }
      break;
    case 80 ... 89:
      switch (char_code_value) {
        case 80:
          return field_name::g80;
          break;
        case 81:
          return field_name::g81;
          break;
        case 82:
          return field_name::g82;
          break;
        case 83:
          return field_name::g83;
          break;
        case 84:
          return field_name::g84;
          break;
        case 85:
          return field_name::g85;
          break;
        case 86:
          return field_name::g86;
          break;
        case 87:
          return field_name::g87;
          break;
        case 88:
          return field_name::g88;
          break;
        case 89:
          return field_name::g89;
          break;
      }
      break;
    case 90 ... 99:
      switch (char_code_value) {
        case 90:
          return field_name::g90;
          break;
        case 91:
          return field_name::g91;
          break;
        case 92:
          return field_name::g92;
          break;
        case 93:
          return field_name::g93;
          break;
        case 94:
          return field_name::g94;
          break;
        case 95:
          return field_name::g95;
          break;
        case 96:
          return field_name::g96;
          break;
        case 97:
          return field_name::g97;
          break;
        case 98:
          return field_name::g98;
          break;
        case 99:
          return field_name::g99;
          break;
      }
      break;
  }
}

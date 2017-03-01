#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include "cap_char_receiver.h"
#include "cap_file.h"
#include "message_printer.h"
#include "packet_header_printer.h"
#include "packet_separator.h"
#include "message_interpreter.h"
#include "message_subject.h"
#include "message_observer.h"
#include "Divmessage_observer.h"
#include "Modmessage_observer.h"
#include "message_header_printer.h"



using namespace std;
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using namespace std::literals::chrono_literals;
using std::this_thread::sleep_for;

string cursor = "> ";

void print_menu() {

  cout << endl;
  cout << "Menu" << endl;
  cout << "------------------------------" << endl;
  cout << "1) Tally file count." << endl;
  cout << "2) Break file into packets." << endl;
  cout << "3) Print message(s)." << endl;
  cout << "4) Print header(s)." << endl;
  cout << "5) Print message header(s)." << endl;
  cout << "q) Quit." << endl;
  cout << endl;
}

void tally() {

  cout << endl;
  string path;
  string confirm;
  cout << cursor << "Enter file path: ";
  while (true) {
    cin >> path;
    cout << cursor << "You entered: " << path << endl;
    cout << cursor << "Is this correct(y/n, or a to abort)? ";
    cin >> confirm;
    if (confirm == "a") return;
    if (confirm == "y") {
      cap_file cf(path);
      shared_ptr<cap_char_receiver> cpp(new cap_char_receiver());
      cf.set_client(cpp);
      time_point<Clock> start = Clock::now();
      cf.run();
      time_point<Clock> end = Clock::now();
      cout << endl;
      milliseconds diff = duration_cast<milliseconds>(end - start);
      cout << diff.count() << "ms" << endl;
      cout << cursor << "Chars: " << cpp->get_char_count() << endl;
      cout << cursor << "Packets: " << cpp->get_packet_count() << endl;
      cout << cursor << "Messages: " << cpp->get_message_count() << endl;
      cout << endl;
      return;
    }
  }
}

void break_down()
{
  cout << endl;
  string path;
  string confirm;
  cout << cursor << "Enter file path: ";
  while (true) {
    cin >> path;
    cout << cursor << "You entered: " << path << endl;
    cout << cursor << "Is this correct(y/n, or a to abort)? ";
    cin >> confirm;
    if (confirm == "a") return;
    if (confirm == "y") break;
  }
  string outputPath;
  cout << cursor << "Enter output path (must exist): ";
  while (true) {
    cin >> outputPath;
    cout << cursor << "You entered: " << outputPath << endl;
    cout << cursor << "Is this correct(y/n, or a to abort)? ";
    cin >> confirm;
    if (confirm == "a") return;
    if (confirm == "y") {
      cap_file cf(path);
      shared_ptr<packet_separator> psp(new packet_separator());
      psp->set_output_path(outputPath);
      cf.set_client(psp);
      cf.run();
      return;
    }
  }
}

void print_messages()
{
  cout << endl;
  string path;
  string confirm;
  cout << cursor << "Enter file path: ";
  while (true) {
    cin >> path;
    cout << cursor << "You entered: " << path << endl;
    cout << cursor << "Is this correct(y/n, or a to abort)? ";
    cin >> confirm;
    if (confirm == "a") return;
    if (confirm == "y") {
      cap_file cf(path);
      shared_ptr<message_printer> psp(new message_printer());
      cf.set_client(psp);
      cf.run();
      cout << endl;
      return;
    }
  }
}

void print_packet_header()
{
  cout << endl;
  string path;
  string confirm;
  cout << cursor << "Enter file path: ";
  while (true) {
    cin >> path;
    cout << cursor << "You entered: " << path << endl;
    cout << cursor << "Is this correct(y/n, or a to abort)? ";
    cin >> confirm;
    if (confirm == "a") return;
    if (confirm == "y") {
      cap_file cf(path);
      shared_ptr<packet_header_printer> php(new packet_header_printer());
      cf.set_client(php);
      cf.run();
      cout << endl;
      return;
    }
  }
}

void print_message_header()
{
  cout << endl;
  string path;
  string confirm;
  cout << cursor << "Enter file path: ";
  while (true) {
    cin >> path;
    cout << cursor << "You entered: " << path << endl;
    cout << cursor << "Is this correct(y/n, or a to abort)? ";
    cin >> confirm;
    if (confirm == "a") return;
    if (confirm == "y") {
      cap_file cf(path);
      // the client is message interpreter
      shared_ptr<message_interpreter> mip(new message_interpreter());
      cf.set_client(mip);
      // message interpreter has a observer called message_header_observer
      message_header_printer mhp(mip);

      cf.run();
      cout << endl;
      return;
    }
  }
}

int main()
{

  string command;
  cout << "STCap (m for menu)" << endl;
  cout << "------------------------------" << endl;
  cout << cursor;
  while (cin >> command && command != "q") {
    if (command == "m") print_menu();
    if (command == "1") tally();
    if (command == "2") break_down();
    if (command == "3") print_messages();
    if (command == "4") print_packet_header();
    if (command == "5") print_message_header();
    cout << cursor;
  }
}

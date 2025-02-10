#include <iostream>
#include <unistd.h>
#include "auth.h"
using namespace std;

int main() {
  cout << "OS is booting up..." << endl;
  sleep(1);
  cout << "..." << endl;
  sleep(1);
  cout << "..." << endl;

  authenticateUser();


  return 0;




}
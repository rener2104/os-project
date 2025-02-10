#include <string>
#include <iostream>
using namespace std;


void authenticateUser(){
    const string USER = "admin";
    const string PASS = "password";
    bool authenticated = false;
    int cont = 1;

    while(!authenticated){
        string username, password;
        cout << "Enter username:";
        cin >> username;
        cout << "Enter password:";
        cin >> password;

        if (username == USER && password == PASS){
          authenticated = true;
          cout << "Welcome!\n";
        } else {cout << "Authentication failed.\n\n";}
    }
}


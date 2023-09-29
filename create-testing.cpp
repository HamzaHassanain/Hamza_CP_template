#include <iostream>

using namespace std;

int main()
{

    string s;

    cin >> s;
    string command = "mkdir " + s;
    system(command.c_str());
    command = "cp -r /home/hamza/github/cp/testing-template/* " + s;
    system(command.c_str());
}
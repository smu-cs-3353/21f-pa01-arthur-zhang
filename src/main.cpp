#include "manager.h"
using namespace std;

int main(int argc, char** const argv) {

    if (argv[1] == NULL)
    {
//        catch
    }

    ifstream file_input(argv[1]);
    ofstream brute_force("test-bruteforce.txt");
    ofstream high_value("test-highvalue.txt");
    ofstream custom ("test-custom.txt");
    manager manage;
    manage.run(file_input, brute_force, high_value, custom);

    file_input.close();
    brute_force.close();
    high_value.close();
    custom.close();
    return 0;
}



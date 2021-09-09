#include "manager.h"
using namespace std;

int main(int argc, char** const argv) {

    if (argv[1] == NULL)
    {
//        catch
    }

    string filename = "test/";
    filename+=argv[1];
    ifstream file_input(filename);
    if(file_input.is_open())
    {
        ofstream brute_force("test-bruteforce.txt");
        ofstream high_value("test-highvalue.txt");
        ofstream custom ("test-custom.txt");
        manager manage;
        manage.run(file_input, brute_force, high_value, custom);

        file_input.close();
        brute_force.close();
        high_value.close();
        custom.close();
    }
    else
        cout<<"wrong file name"<<endl;
    return 0;
}



//directory
#include <sys/types.h>
#include <dirent.h>
#include <fstream>

#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

class Input{
private:
    string name;                    //name of file
    string absolute_path;           //absolute path
    string relative_path_to_INPUT;  //relative path
    string dir_path;                //directory path
public:
    Input();
    Input(string n,string ap,string rp,string dp);

    string get_name();
    string get_absolute_path();
    string get_relative_path_to_INPUT();
    string get_dir_path();
};

class Output{
private:
    Input* input1 = NULL;
    Input* input2 = NULL;
    int result = 0;                 //0 = inequal, 1 = equal
public:
    Output();
    Output(Input* i1,Input* i2);

    Input* get_input1();
    Input* get_input2();
    int get_result();
    void set_result(int r);
};

class Stdin_format{
private:
    int type;       //int = 1, string = 2, char = string(1,1)
    int left;
    int right;
public:
    Stdin_format();
    Stdin_format(int t,int l,int r);

    int get_type();
    int get_left();
    int get_right();
};

class Equminer{
private:
    Input* input1 = NULL;
    Input* input2 = NULL;
    Output* output = NULL;
    vector<Stdin_format*> stf;
public:
    Equminer();
    Equminer(Input* i1,Input* i2,Output* o,vector<Stdin_format*> &st);

    string random_case(int n);      //Generate random test samples
    void case_compare();            //Compare using test samples
};

/*
 *        File: texting.cc
 *      Author: Jonah Brautigam
 *        Date: 3/30/2021
 * Description: Change characters of a input file
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace std;

/**
 * Gets input and output file names
 * @param input_file reference parameter for input file name
 * @param output_file reference parameter for output file name
 * @return input_file and output_file
*/
string inputAndOuput (string &input_file, string &output_file);

/**
 * Opens up input and output files
 * @param input_file string for file name
 * @param output_file string for file name
 * @param ins inStream reference variable
 * @param outs outStream reference variable
*/
void openFile (string input_file, string output_file, ifstream &ins, ofstream &outs);

int main(int argc, char const *argv[]) {

    string input_file;
    string output_file;
    ifstream ins;
    ofstream outs;

    char ch;

    inputAndOuput (input_file, output_file);

    openFile (input_file, output_file, ins, outs);

    ins.get(ch);
    while (!ins.eof())
    {
        if (isalpha(ch))
        {
            ch = toupper(ch);
        }
        else if (isdigit(ch))
        {
            ch = '*';
        }
        outs << ch;

        ins.get(ch);
    }

    ins.close();
    outs.close();

    return 0;
}// main

string inputAndOuput (string &input_file, string &output_file)
{
    cout << "Enter input file name: ";
    cin >> input_file;

    cout << "\nEnter output file name: ";
    cin >> output_file;

    cout << "\nFile " << output_file << " was created." << endl;

    return input_file;
    return output_file;
}

void openFile (string input_file, string output_file, ifstream &ins, ofstream &outs)
{
    ins.open(input_file);
    if (ins.fail())
    {
        cout << "Error: File could not be open" << endl;
        exit(0);
    }

    outs.open(output_file);
    if (outs.fail())
    {
        cout << "Error: File could not be open" << endl;
        exit(0);
    }
}
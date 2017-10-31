// 2017 (c) Andrew Samuel

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include "infinity.hpp"

/*

    This a Infinity Lang for development smart.
    Criated by Andrew S.
    Compiler runtime, without compilation required.
    -----------------------------------------------
    Function how? Simple:
    The variable defined with: predefined load all time.
    in execution of file. this make a simple loop. the file 
    have a struction:
    print:
    something
    c:
    eu
    the runtime run, stop in somenthing and calls a function.
    -----------------------------------------------
    O Funcionamento da Infinity Lang e simples.
    --------------------------------------------------------
    Um Arquivo em Infl;
    
    print:
    legal
    
    c:
    isso e um commentario
    
    end_prog:
    
*/

// stoped in;
/* 
    Table of contents:
    1 = print
    2 = commentary
    3 = define var
*/


// Using std
using namespace std;

int stopedin;

// Espaços de memoria


// String (Comming Soon)
string space1;
string space2;
string space3;
string space4;
string space5;
string space6;
string space7;
string space8;
// Numbers (Comming Soon)
int number1;
int number2;
int number3;
int number4;
int number5;
int number6;
int number7;
int number8;

// Readed Lines
int linesRead;

// Bibliotecas de funçoes e alocaçoes

int printIn(string& printem) {
    cout << printem << endl;
    return 0;
}

// Verify a memory;

int clear_mem_space() {
    // Set all spaces to 0 or ""
    space1 = "null";
    space2 = "null";
    return 0;
}

int setTomemory_str(string& memSpace) {
    if(space1=="null") {
        space1 = memSpace;
    }
    else if(space2=="null") {
        space2 = memSpace;
    }
    else {
        cout << "Segmentation Fault." << endl;
    }
    return 0;
}

int endPrograms(string& endline) {
    string presskeyD;
    cout << endline << endl;
    cout << "Press a key for continue..." << endl;
    cin >> presskeyD;
}

int ilegalInstrution(const char* error) {
    cout << "FATAL: ILLEGAL INSTRUCTION. LINE(S): " << linesRead << endl;
    cout << error << endl;
    return 0;
}

int processorLang(string& instruction) {
    clear_mem_space();
    if(stopedin==1) { 
        // This print a word in screen
        printIn(instruction);
    }
    else if(stopedin==2) {
        stopedin = 0;
    }
    else if(stopedin==3) {
        setTomemory_str(instruction);
        stopedin = 0;
    }
    else if(stopedin==4) {
        endPrograms(instruction);
        stopedin = 0;
    }
    
    // This a after instruction;
    if(instruction=="print:") {
        stopedin = 1;
    }
    else if(instruction=="c:") {
        stopedin = 2;
    }
    else if(instruction=="defvar_str:") {
        stopedin = 3;
    }
    else if(instruction=="end_prog:") {
        stopedin = 4;
    }
    else if(instruction=="") {
        stopedin = 0;
    }
    return 0;
}


int main() {
    string file_to_run;
    cout << "Welcome to Infinity Lang Runtime." << endl;
    cout << "To exit, type: com.exit.process;" << endl;
    // This main a shell in running.
    int main;
    main = 1;
    while(main<100) { 
        std::cout << "File to run:. ";
        std::cin >> file_to_run;
        if(file_to_run=="com.exit.process") {
            break;
        }
        else if(file_to_run=="com.demos_infl.package") {
            demos_infinityLang();
        }
        // Now, this open a file with name.
        ifstream fileo;
        string lines;
        string operation;
        // Define a file;
        fileo.open(file_to_run);
        // Verify if file exist...
        if(fileo.is_open()) {
            // This clear all buffer;
            system("clear"); // Yes, this function only in linux.
            // Get all instructions to memory.
            while(getline(fileo,lines)) {
                operation = lines;
                processorLang(operation);
                linesRead = linesRead + 1;
            }
            //cout << "com.infinitylang.process: closing a files..." << endl;
            fileo.close();
        }
        else {
            cout << "This file not exist. Using this how a (illegal instruction)" << endl;
        }
        //cout << "Script: " << endl;
        //cout << operation << endl;
    }
    return 0;
}

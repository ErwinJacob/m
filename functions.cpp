#include "functions.h"
#include <iostream>

using namespace std;

void help(){
    cout << "Use \"CALCULATE\" to start calculating" << endl;
    cout << "Use \"HISTORY\" to show history of search" << endl;
    cout << "Use \"EXIT\" to stop the program" << endl;
}

void history(Fences fences){
    if (fences.list.empty()){
        cout << "History empty" << endl;
        return;
    }
    cout << "Previous searches:" << endl;
    for (int i = fences.list.size() - 1; i >= 0; i--) {
        cout << i+1 << ". Fence length: " << fences.list[i].length << " Max size: " << fences.list[i].maxSize << endl;
    }
}

void run(){
    cout << "Use \"START\" to start :)" << endl;

    bool start = false;
    string cmd;

    while (!start){
        cin >> cmd;
        if (cmd == "START"){
            start = true;
        }
        else{
            cout << "I can't recognize your command, try again" << endl;
            cout << "Use \"START\" to start :)" << endl;
        }
    }

    Fences fences;

    bool exit = false;
    help();

    while(!exit){

        cout << endl << "w8ing for your command" << endl;
        cin >> cmd;
        if (cmd == "CALCULATE"){
            Fence a = Fence();
            a.calc();
            a.info();
            fences.list.push_back(a);
        }
        else if (cmd == "EXIT"){

            cout << "Bye! :)" << endl;
            exit = true;
        }
        else if (cmd == "HISTORY"){
            history(fences);
        }
        else if (cmd == "HELP"){
            help();
        }
        else{
            cout << "I can't recognize your command, try again" << endl;
            cout << "Use \"HELP\" for list of commands" << endl;
        }
    }

    cout << endl;

}

#include "fence.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;



Fence::Fence(){
    cout << "How many meters of fence do we have?" << endl;

    double l = 1.5;

    bool ready = false;

    while (!ready) {
        cout << "Remember to use integer numbers only" << endl;
        cout << "3 is minimum length of fence we need" << endl;

        if(l == int(l) and l>=3){
            ready = true;
            continue;
        }

        cin >> l;

        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

    }

    length = int(l);
}

void Fence::calc() {

    vector<int> biggerB;
    int a, b;

    for (int i = 2; i < length; i++) {
        b = length - i;
        a = i;

        //checking if a/2 is still integer
        double check = a;
        check = check / 2;

        if (check != int(check)) {
            continue;
        } else {
            a = a / 2;
            cout << "a = " << a << ", b = " << b << endl;
            cout << a << " + " << b << " + " << a << " = " << length << endl;
            cout << a << " * " << b << " = " << a * b << endl << endl;

            if (maxSize <= a * b) {
                maxSize = a * b;
                biggerB.push_back(b);
            }
        }

    }

    for (int i = 0; i < biggerB.size(); ++i) {
        if (maxSize == (biggerB[i] * (length - biggerB[i]) / 2)) {
            bestB.push_back(biggerB[i]);
        }
    }
}

void Fence::info(){
    if (maxSize == 0){
        cout << "Calculation not made yet" << endl;
        return;
    }

    cout << "With fence length = " << length << endl;

    for (int i = 0; i < bestB.size(); ++i) {
        cout << "Maximum area of his farm can be achieved with:" << endl;
        cout << "a = " << (length-bestB[i])/2 << ", b = " << bestB[i] << endl;

    }
    cout << "Miximum area of his farm could be " << maxSize << endl;
};

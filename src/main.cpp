
#include "BaseRobot.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main(int argc, char** argv) {
    int i;
    cout << "Ingrese 1 para encender el robot:"<<endl;
    cin >> i;
    if (i == 1){
        BaseRobot *robot1;
        robot1= new BaseRobot(0, true, "168.10.14.77");
    }
    else {
        return 0;
    }
}

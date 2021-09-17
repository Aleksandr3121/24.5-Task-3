#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdint>

using namespace std;

int main() {
    time_t t1 = time(nullptr);
    tm local = *localtime(&t1);
    cin >> get_time(&local, "%M:%S");
    //предполагается что в вводе минут и секунд меньше 60
    int sec = (local.tm_min * 60) + local.tm_sec;
    t1 = time(nullptr);
    time_t t2 = time(nullptr);
    int timer = difftime(t2, t1);
    cout << setfill('0');
    cout << setw(2) << timer / 60 << ':' << setw(2) << timer % 60 << endl;
    while (timer < sec) {
        if (difftime(time(nullptr), t2) < 1)continue;
        timer = difftime(time(nullptr), t1);
        t2 = time(nullptr);
        cout << setfill('0');
        cout << setw(2) << timer / 60 << ':' << setw(2) << timer % 60 << endl;
    }
    cout<<"DING!DING!DING!";
    return 0;
}

#include <iostream>
#include <string>
//#include <random>
#include <stdlib.h>
using namespace std;

class IP {
    string a;
    string b;
    string c;
    string d;
    public:

        IP() {
            a = "";
            generate_IP();
        }   

        void generate_IP() {
            int a1 = rand() % 999;
            a = "";
            a.append(to_string(a1));
            int b1 = rand() % 999;
            b = "";
            b.append(to_string(b1));
            int c1 = rand() % 999;
            c = "";
            c.append(to_string(c1));
            int d1 = rand() % 999;
            d = "";
            d.append(to_string(d1));
        }

        string get_IP() {
            return "" + a + ":" +  b + ":" +  c + ":" +  d;
        }
};
/**
 * @file IP.cpp 
 * This file implements the IP generation required for generating random addresses for requests.
 */

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

        /// This is the default constructor, which generates a random IP.
        IP() {
            a = "";
            generate_IP();
        }   

        /// This generates random values for each section of the IP.
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

        /// This function returns a string version of the IP.
        string get_IP() {
            return "" + a + ":" +  b + ":" +  c + ":" +  d;
        }
};
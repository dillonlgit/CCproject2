#include <string>
#include "IP.cpp"
using namespace std;

class Request {
    private:
        string IpIn;
        string IpOut;
        int time;
    
    public:

        // default constructor
        Request() {
            IpIn = "";
            IpOut = "";
            time = 0;
        }

        Request(string IP1, string IP2, int t) {
            IpIn = IP1;
            IpOut = IP2;
            time = t;
        }

        void randomize(int maxRequestDuration) {
            IP in, out = IP();
            IpIn = in.get_IP();
            IpOut = out.get_IP();
            time = rand() % maxRequestDuration + 1;
        }

        int getTime() {
            return time;
        }
};
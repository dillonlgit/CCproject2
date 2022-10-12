#include <string>
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

        int getTime() {
            return time;
        }
};
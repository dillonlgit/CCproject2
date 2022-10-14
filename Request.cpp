/**
 * @file Request.cpp 
 * This file implements the Request class, which manages an IP in, out, and a duration for the request.
 */

#include <string>
#include "IP.cpp"
using namespace std;

class Request {
    private:
        string IpIn;
        string IpOut;
        int time;
    
    public:

        /// default constructor
        Request() {
            IpIn = "";
            IpOut = "";
            time = 0;
        }

        /// @brief This constructor takes as input the parameters to set to create the request.
        /// @param IP1 A string of an IP for input
        /// @param IP2 A string of an IP for output
        /// @param t An integer representing the amount of time the request needs to complete
        Request(string IP1, string IP2, int t) {
            IpIn = IP1;
            IpOut = IP2;
            time = t;
        }

        /// @brief The randomize function takes in a maximum duration and creates a random duration and random IP's.
        /// @param maxRequestDuration This is the max duration.
        void randomize(int maxRequestDuration) {
            IP in, out = IP();
            IpIn = in.get_IP();
            IpOut = out.get_IP();
            time = rand() % maxRequestDuration + 1;
        }

        /// getTime returns the time.
        int getTime() {
            return time;
        }

        /// @brief toString returns a readable version of the request for logging purposes.
        /// @return returns the log entry.
        string toString() {
            return "request from IP " + IpIn + " to IP " + IpOut + " with duration " + to_string(time);
        }
};
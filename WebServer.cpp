/**
 * @file WebServer.cpp 
 * This is the file which holds the class for each WebServer object.
 */

#include "Request.cpp"
#include <iostream>

class WebServer {
    private:
        /// Each WebServer has a request to process for a given time.
        Request req = Request();
        /// This variable stores the system time at which the request started being processed.
        int reqStartTime = 0;
    public:
        /// addRequest adds a new request and updates the reqStartTime
        void addRequest(Request newReq, int time) {
            req = newReq;
            reqStartTime = time;
        }

        /// This function checks if the current request has been completed
        bool available (int time) {
            return reqStartTime + req.getTime() <= time;
        }

        /// This function returns the Request object. 
        Request finishRequest() {
            return req; 
        }

};
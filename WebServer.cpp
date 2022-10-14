#include "Request.cpp"
#include <iostream>

class WebServer {
    private:
        Request req = Request();
        int reqStartTime = 0;
    public:
        // We currently assume that the LoadBalancer is correctly distributing requests.
        void addRequest(Request newReq) {
            req = newReq;
        }

        // check if request has completed
        bool available (int time) {
            return reqStartTime + req.getTime() <= time;
        }

        Request finishRequest() {
            return req; 
        }

};
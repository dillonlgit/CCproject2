#include "Request.cpp"

class WebServer {
    private:
        Request req;
        int uptime;
        int reqStartTime;
    public:
        bool addRequest(Request newReq) {
            // check if current request complete
            if(uptime > reqStartTime + req.getTime()) {
                // TODO: add something for finishing a request
                req = newReq;
                return true;
            } else {
                return false;
            }
        }

        void updateTime(int time) {
            uptime = time;
        }
};
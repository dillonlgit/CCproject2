#include <iostream>
#include "WebServer.cpp"
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
// TODO: make this into a proper LoadBalancer class

class LoadBalancer {
    private:
        queue<Request> RequestQueue;
        int time;

    public:
        LoadBalancer() {
            time = 0;
        }

        int getTime() {
            return time;
        }

        void addTime() {
            time++;
        }

        void pushRequest(Request req) {
            RequestQueue.push(req);
            addTime();
        }

        Request popRequest() {
            if (!RequestQueue.empty()) {
                Request req = RequestQueue.front();
                RequestQueue.pop();
                return req;
            }
        }
};
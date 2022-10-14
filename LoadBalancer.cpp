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
        int maxQueueSize = 10;

    public:
        LoadBalancer() {
            time = 0;
        }

        LoadBalancer(int queueSize) {
            time = 0;
            maxQueueSize = queueSize;
        }

        int getTime() {
            return time;
        }

        void addTime() {
            time++;
        }

        void pushRequest(Request req) {
            RequestQueue.push(req);
            cout << "DEBUGGING: RequestQueue size after push: " << RequestQueue.size() << endl;
        }

        Request popRequest() {
            Request req = RequestQueue.front();
            RequestQueue.pop();
            cout << "DEBUGGING: RequestQueue size after pop: " << RequestQueue.size() << endl;
            return req;
        }

        bool queueIsFull() {
            return RequestQueue.size() >= maxQueueSize;
        }

        bool queueIsEmpty() {
            return RequestQueue.size() <= 0;
        }

        bool queueSize() {
            return RequestQueue.size();
        }
};
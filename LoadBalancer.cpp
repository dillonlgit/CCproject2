/**
 * @file LoadBalancer.cpp 
 * This is the file which implements the functionality of the load balancer.
 * It holds the class LoadBalancer which holds a RequestQueue, queue size, and queue functions.
 */


#include <iostream>
#include "WebServer.cpp"
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;


class LoadBalancer {
    private:
        /// This queue holds requests for the loadbalancer to process.
        queue<Request> RequestQueue;
        /// time represents the overall system time for the program.
        int time;
        /// maxQueueSize denotes the cutoff amount available in the queue.
        int maxQueueSize = 10;

    public:
        /**
         * This is the default constructor for LoadBalancer.
         */
        LoadBalancer() {
            time = 0;
        }

        /**
         * This is the constructor given a maximum queue size for LoadBalancer.
         */
        LoadBalancer(int queueSize) {
            time = 0;
            maxQueueSize = queueSize;
        }

        /**
         * This function returns the current time as an integer.
         */
        int getTime() {
            return time;
        }

        /**
         * This function adds 1 to the overall system time for LoadBalancer.
         */
        void addTime() {
            time++;
        }

        /**
         * This function pushes a request to the request queue.
         */
        void pushRequest(Request req) {
            RequestQueue.push(req);
            cout << "DEBUGGING: RequestQueue size after push: " << RequestQueue.size() << endl;
        }
        /**
         * This function gets and pops the first in the request queue.
         */
        Request popRequest() {
            Request req = RequestQueue.front();
            RequestQueue.pop();
            cout << "DEBUGGING: RequestQueue size after pop: " << RequestQueue.size() << endl;
            return req;
        }

        /**
         * This function returns whether the queue is full or not.
         */
        bool queueIsFull() {
            return RequestQueue.size() >= maxQueueSize;
        }

        /**
         * This fucntion returns whether the queue is empty or not.
         */
        bool queueIsEmpty() {
            return RequestQueue.size() <= 0;
        }

        /**
         *  This function returns the size of the queue, for the purpose of printing the final size at the end.
         */
        bool queueSize() {
            return RequestQueue.size();
        }
};
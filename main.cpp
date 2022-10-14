#include "LoadBalancer.cpp"

int main () {
    int numServers = 0;
    int runTime = 0;
    cout << "Enter the number of servers: ";
    cin >> numServers;
    cout << "Enter the amount of clock cycles you'd like to run: ";
    cin >> runTime;
    runTime = 10000;
    // hyperparameters, not currently as user input, maybe it should be?
    int queueSize = numServers * 2;
    int maxRequestDuration = 75;
    float chanceToAddRequest = 0.6; // Every clock cycle, determine whether to add a request

    srand(time(NULL));
    LoadBalancer lb = LoadBalancer(); 

    // full queue at t=0
    for  (int i = 0; i < queueSize; i++) {
        Request req = Request();
        req.randomize(maxRequestDuration);
        lb.pushRequest(req);
    }

    // need numServers many WebServers, using array
    WebServer servers [numServers];

    // main loop
    while (lb.getTime() < runTime) {
        //cout << "DEBUGGING: Current time: " << lb.getTime() << endl;
        bool serversBusy = false;
        // Try to add a request to a webserver
        for (int i = 0; i < numServers; i++) {
            // This means the webserver is available
            if (servers[i].available(lb.getTime())) {
                // If the current request took more than 0 time (it's a request), print out it's finished information.
                if (servers[i].finishRequest().getTime() > 0) {
                    cout << "Finished " << servers[i].finishRequest().toString() << " on server " << to_string(i) << " at time " << lb.getTime() << endl;
                    lb.addTime();
                }
                // If queue is empty, continue!
                if (lb.queueIsEmpty()) {
                    continue;
                }
                // Add a request to webserver
                Request newRequest = lb.popRequest();
                servers[i].addRequest(newRequest, lb.getTime());
                cout << "Started " << newRequest.toString() << " on server " << to_string(i) << " at time " << lb.getTime() << endl;
                serversBusy = true;
                lb.addTime();
                break;
            } else {
                // If one of the servers is still running
                serversBusy = true;
            }
        }

        if (serversBusy == false && lb.queueIsEmpty()) {
            // If none of the servers are busy, and the queue is empty,
            // the queue is empty and all requests have complete. Finish program.
            cout << "FINISHED: Queue is empty at time: " << lb.getTime() << endl;
            break;
        }

        // Randomly add more requests to the queue (simulation)
        if (!lb.queueIsFull()) {
            if(rand() % 100 < chanceToAddRequest * 100) {
                //cout << "DEBUGGING: We're randomly adding to queue" << endl;
                Request req = Request();
                req.randomize(maxRequestDuration);
                lb.pushRequest(req);
            }
        } else  {
            cout << "DEBUGGING: Queue is full at time: " << lb.getTime() << endl;
        }

        lb.addTime();
    }
    if (lb.getTime() >= runTime) {
        cout << "RUNTIME FINISHED: exited program at time: " << lb.getTime() << endl;
    }
    cout << "Starting Queue Size: " << queueSize << endl;
    cout << "Task Time Duration Range: 0 to " << maxRequestDuration << endl; 
    cout << "Ending Queue Size: " << lb.queueSize() << endl;
}
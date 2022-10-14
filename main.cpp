#include "LoadBalancer.cpp"

int main () {
    int numServers = 0;
    int runTime = 0;
    cout << "Enter the number of servers: ";
    //cin >> numServers;
    numServers = 3;
    cout << "Enter the time you'd like to run: ";
    //cin >> runTime;
    runTime = 19;
    // hyperparameters, not currently as user input, maybe it should be?
    int queueSize = numServers * 2;
    int maxRequestDuration = 5;


    LoadBalancer lb = LoadBalancer(); 

    // full queue at t=0
    for  (int i = 0; i < queueSize; i++) {
        Request req = Request();
        req.randomize(maxRequestDuration);
        lb.pushRequest(req);
    }

    // need numServers many WebServers, using array
    WebServer servers [numServers];
    





    cout << "the end" << endl;

}
#include "LoadBalancer.cpp"
#include "IP.cpp"

int main () {
    int numServers = 0;
    int runTime = 0;
    cout << "Enter the number of servers: ";
    cin >> numServers;
    cout << "Enter the time you'd like to run: ";
    cin >> runTime;

    int queueSize = numServers * 2;

    LoadBalancer lb 
}
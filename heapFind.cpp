// C++ code to demonstrate the working of 
// make_heap(), front()
#include<queue> 
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct comparator
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};


void heapInit(priority_queue<int, vector<int>, comparator>* minHeap, vector<int>& v1)
{
    // minHeap->push(12);
    // minHeap->push(8);
    // minHeap->push(15);
    // minHeap->push(2);
    // minHeap->push(3);
    // minHeap->push(9);

    for(int i = 0; i < v1.size(); i++){
        minHeap->push(v1[i]);
    }

    // while (!minHeap->empty())
    // {
    //     cout<<minHeap->top()<<" ";
    //     minHeap->pop();
    // }
}

void findSlot (priority_queue<int, vector<int>, comparator>* minHeap, int endPoint){
  
    //TODO: keyword import
    int currentSlot = 2;
    
    cout << "Slot # | X | Y \n";

    while(currentSlot <= endPoint){

        // if(!minHeap->empty()){
        //     int lastPop = minHeap->pop();
        // }

        int lastPop = minHeap->top();
        minHeap->pop();
        int currentTop = minHeap->top();

        if(currentTop - lastPop == 1){
            continue;
        }
        
        int currentX = lastPop + 1;
        int currentY = currentX + currentSlot;

        minHeap->push(currentX);
        minHeap->push(currentY);

        cout << currentSlot << "          " << currentX << " - " << currentY << "\n";

        currentSlot++;
    }


}

int main(int argc, char *argv[]){
    /*
    collect the desired slot number from command line
    initialize the min heap with the base case of "slot 1"
    run the main loop, finding incrementally higher slot numbers until we reach the desired slot number
    print to terminal the resulting x and y coords
    */

   int endPoint;

    if(argc == 1){
        endPoint = 10;
        cout << "No endpoint detected, defaulting to 10... \n";
    }
    else if(argc == 2){
        string arg = argv[1];
        endPoint = stoi(arg);
        cout << "Endpoint of " << endPoint << " detected...\n";
    }

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);


    priority_queue<int, vector<int>, comparator> minHeap;

    heapInit(&minHeap, v1);

    findSlot(&minHeap, endPoint);

return 0;
}

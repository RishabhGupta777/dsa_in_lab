#include <iostream>
#include <algorithm>

using namespace std;
struct Item {
    int profit;
    int weight;
    float ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio; 
}

void knapsack(int n, int capacity, int pt[], int wt[]) {

    Item items[n];

for (int i = 0; i < n; i++) {
    items[i]  = {pt[i], wt[i], (float)pt[i] / wt[i]};  
}

sort(items, items + n, compare);

float maxProfit = 0.0;
int remainingCapacity = capacity;

for (int i = 0; i < n; i++) {
    if (items[i].weight <= remainingCapacity) {
   
        maxProfit =maxProfit+ items[i].profit;
        remainingCapacity = remainingCapacity- items[i].weight;
    } else {
       
        maxProfit =maxProfit +items[i].ratio * remainingCapacity;
        break; 
    }
}

cout << "Maximum Profit: " << maxProfit << endl;


}

using namespace std;
int main(){
    int n=3;
    int capacity = 50; 
int pt[3]={100,60,120};
int wt[3]={20,10,30};
float PtByWt[3]; 

knapsack(n, capacity, pt, wt);
return 0;
}
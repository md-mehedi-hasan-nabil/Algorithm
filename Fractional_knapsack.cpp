#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int price;
    int weight;
};

Item arr[] =
{
    {10, 4}, {20, 10}, {12, 3}
};

int numberOfItem = sizeof(arr) / sizeof(arr[0]);
int totalWeight = 8;
float profit = 0;

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.price / (double)a.weight;
    double r2 = (double)b.price / (double)b.weight;
    return r1 > r2;
}

void fractional_knapsack_RB()
{
    sort(arr, arr + numberOfItem, cmp);

    for (int i = 0; i < numberOfItem; i++)
    {
        if (arr[i].weight <= totalWeight)
        {
            totalWeight = totalWeight - arr[i].weight;
            profit = profit + arr[i].price;
        }
        else
        {
            int unitPrice = arr[i].price / arr[i].weight;
            profit = profit + totalWeight * unitPrice;
            totalWeight = 0;
        }
    }

    cout << "Total profit: " << profit << endl;

    //for (int i = 0; i < numberOfItem; ++i)
    //cout << arr[i].P << " ";
}

int main()
{
    fractional_knapsack_RB();
}

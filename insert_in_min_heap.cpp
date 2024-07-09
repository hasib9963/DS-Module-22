#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v; // Vector to store heap elements
    int n;         // Number of elements to be inserted
    cin >> n;      // Read the number of elements

    // Loop to read each element and insert into the heap
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;                   // Read the next element
        v.push_back(x);             // Add the element to the heap
        int cur_idx = v.size() - 1; // Index of the newly added element

        // Bubble up to maintain the min-heap property
        while (cur_idx != 0)
        {
            int parent_idx = (cur_idx - 1) / 2; // Calculate parent index
            if (v[parent_idx] > v[cur_idx])
                swap(v[parent_idx], v[cur_idx]); // Swap if parent is greater
            else
                break;            // If parent is smaller, heap property is satisfied
            cur_idx = parent_idx; // Update current index to parent index
        }
    }

    // Print the heap elements
    for (int val : v)
        cout << val << " ";

    return 0;
}

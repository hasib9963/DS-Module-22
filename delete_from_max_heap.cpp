#include <bits/stdc++.h>
using namespace std;

// Function to insert an element into the max-heap
void insert_heap(vector<int> &v, int x)
{
    v.push_back(x); // Add the new element at the end of the vector
    int cur_idx = v.size() - 1; // Get the index of the newly added element
    // Bubble up to maintain the max-heap property
    while (cur_idx != 0)
    {
        int parent_idx = (cur_idx - 1) / 2; // Calculate the parent index
        if (v[parent_idx] < v[cur_idx]) // If the parent is smaller than the current element
            swap(v[parent_idx], v[cur_idx]); // Swap them
        else
            break; // If the parent is larger or equal, stop bubbling up
        cur_idx = parent_idx; // Update the current index to the parent index
    }
}

// Function to delete the root element from the max-heap
void delete_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1]; // Replace the root with the last element
    v.pop_back(); // Remove the last element
    int cur = 0; // Start from the root
    // Bubble down to maintain the max-heap property
    while (true)
    {
        int left_idx = cur * 2 + 1; // Calculate the left child index
        int right_idx = cur * 2 + 2; // Calculate the right child index
        int last_idx = v.size() - 1; // Get the last index of the vector
        if (left_idx <= last_idx && right_idx <= last_idx) // If both children exist
        {
            if (v[left_idx] >= v[right_idx] && v[left_idx] > v[cur]) // If the left child is greater or equal to the right child and greater than the current element
            {
                swap(v[left_idx], v[cur]); // Swap the left child with the current element
                cur = left_idx; // Update the current index to the left child index
            }
            else if (v[right_idx] >= v[left_idx] && v[right_idx] > v[cur]) // If the right child is greater or equal to the left child and greater than the current element
            {
                swap(v[right_idx], v[cur]); // Swap the right child with the current element
                cur = right_idx; // Update the current index to the right child index
            }
            else
            {
                break; // If both children are smaller or equal, stop bubbling down
            }
        }
        else if (left_idx <= last_idx) // If only the left child exists
        {
            if (v[left_idx] > v[cur]) // If the left child is greater than the current element
            {
                swap(v[left_idx], v[cur]); // Swap the left child with the current element
                cur = left_idx; // Update the current index to the left child index
            }
            else
            {
                break; // If the left child is smaller or equal, stop bubbling down
            }
        }
        else
        {
            break; // If no children exist, stop bubbling down
        }
    }
}

// Function to print the elements of the heap
void print_heap(const vector<int>& v)
{
    for (int val : v) // Iterate through each element in the vector
        cout << val << " "; // Print the element followed by a space
    cout << endl; // Print a newline character at the end
}

int main()
{
    int n;
    cin >> n; // Read the number of elements
    vector<int> v; // Create a vector to store the heap elements
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x; // Read the next element
        insert_heap(v, x); // Insert the element into the heap
    }
    delete_heap(v); // Delete the root element from the heap
    print_heap(v); // Print the heap after the first deletion
    delete_heap(v); // Delete the root element again
    print_heap(v); // Print the heap after the second deletion

    return 0;
}

//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
       data[size] = idx; // the data size will represent
        size++; // increases the size of the the heap
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()


 // data[idx] = weightArr[idx];
                //pusedo-code: remove last node fomr tree
               //  size--;
               //  downheap(idx);
               //  return 0;

        //call down heap function to fix tree node positions
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if (pos == 0) return;
    int parent = (pos - 1) / 2;
    if (weightArr[data[pos]] < weightArr[data[parent]]) {
    swap(data[pos], data[parent]);
        upheap(parent, weightArr);

    }






    //while last node in array < to its parent node
        //swap the nodes positions
        //do until node in all parent node < its child nodes

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        // after node deletion/pop function()
        //
    }
};

#endif
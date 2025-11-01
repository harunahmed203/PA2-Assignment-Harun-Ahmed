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
        if (size == 0) return -1;

        int idx = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);
        return idx;

        if (size == 0) return -1;
        return idx;



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
        int left = 2 * pos + 1; // left child
        int right = 2 * pos + 2; // rigth child
        int parent = pos; // the smallest will be the parent since its on top 1 -> 2,3

        if (left < size && weightArr[data[left]] < weightArr[data[right]]) {
            parent = left;
        }
        if (right < size && weightArr[data[parent]] < weightArr[data[right]]) {
            parent = right;
        }
        if (parent != pos){
            swap(data[pos], data[parent]);
            downheap(parent, weightArr);
        }
    }
};


#endif
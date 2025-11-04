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

       // insert index at end of heap, restore order using upheap()
        data[size] = idx; // the data size will represent
        size++; // increases the size of the the heap
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) return -1;
        int idx = data[0];
        data[0] = data[size - 1];
        size--;
        if (size > 0)
            downheap(0, weightArr);
        return idx;
    }

    // data[idx] = weightArr[idx];
    //pusedo-code: remove last node fomr tree
    //  size--;
    //  downheap(idx);
    //  return 0;

    //call down heap function to fix tree node positions

    void upheap(int pos, int weightArr[]) {
        // swap child upward while smaller than parent
        if (pos == 0) return;
        int parent = (pos - 1) / 2;
      //  if (weightArr[data[pos]] < weightArr[data[parent]] ||
      //      (weightArr[data[pos]] == weightArr[data[parent]]
      //          && data[pos] < data[parent]))  {
     //       swap(data[pos], data[parent]);
      //      upheap(parent, weightArr);
            if (weightArr[data[pos]] < weightArr[data[parent]] ||
        (weightArr[data[pos]] == weightArr[data[parent]] && data[pos] < data[parent])) {
                swap(data[pos], data[parent]);
                upheap(parent, weightArr);

        swap(data[pos], data[parent]);
         upheap(parent, weightArr);
        }

        //while last node in array < to its parent node
        //swap the nodes positions
        //do until node in all parent node < its child nodes

    }

    void downheap(int pos, int weightArr[]) {
        // swap parent downward while larger than any child
        // after node deletion/pop function()
        int left = 2 * pos + 1; // left child
        int right = 2 * pos + 2; // rigth child

        int smallest = pos; // the smallest will be the parent since its on top 1 -> 2,3

        //  if (left < size && weightArr[data[left]] < weightArr[data[smallest]]
        //     || (weightArr[data[left] == weightArr[data[smallest]]]
        //     && data[left] < data[smallest]))
        if (left < size &&
               (weightArr[data[left]] < weightArr[data[smallest]] ||
                (weightArr[data[left]] == weightArr[data[smallest]] && data[left] < data[smallest]))) {
        smallest = left;
    }
      //  if (right < size && weightArr[data[right]] < weightArr[data[smallest]]
      //      || (weightArr[data[right] == weightArr[data[smallest]]]
      //      && data[right] < data[smallest]))
        //versions i sucked at
        if (right < size &&
               (weightArr[data[right]] < weightArr[data[smallest]] ||
                (weightArr[data[right]] == weightArr[data[smallest]] && data[right] < data[smallest]))) {
            smallest = right;
        }
        if (smallest != pos) {
            swap(data[pos], data[smallest]);
            downheap(smallest, weightArr);
        }


    }
};


#endif
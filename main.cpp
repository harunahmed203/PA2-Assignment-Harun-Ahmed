//
// Created by Manju Muralidharan on 10/19/25.
//
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "heap.h"
using namespace std;

// Global arrays for node information
const int MAX_NODES = 64;
int weightArr[MAX_NODES];
int leftArr[MAX_NODES];
int rightArr[MAX_NODES];
char charArr[MAX_NODES];

// Function prototypes

//string filename = "C:/Users/aharun459/Desktop/input.txt";
void buildFrequencyTable(int freq[], const string& filename );

//const string& filename
int createLeafNodes(int freq[], const string& filname);

int buildEncodingTree(int nextFree) ;


void generateCodes(int root, string codes[]);

void encodeMessage(const string& filename, string codes[]);

    int main() {
        int freq[26] = {0};

        string filename ;
        cout << "Please enter the filename to be encoded: ";
        cin >> filename;
        // Step 1: Read file and count letter frequencies
        buildFrequencyTable(freq, filename);

        // Step 2: Create leaf nodes for each character with nonzero frequency
        int nextFree = createLeafNodes(freq, filename);

        // Step 3: Build encoding tree using your heap
        int root = buildEncodingTree(nextFree);

        // Step 4: Generate binary codes using an STL stack
        string codes[26];
        generateCodes(root, codes);

        // Step 5: Encode the message and print output
        encodeMessage(filename, codes);
        //imput.txt

        return 0;
    }

    /*------------------------------------------------------
        Function Definitions (Students will complete logic)
      ------------------------------------------------------*/

    // Step 1: Read file and count frequencies
    void buildFrequencyTable(int freq[], const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: could not open " << filename << "\n";
            exit(1);
        }

        char ch;
        while (file.get(ch)) {
         //   cout << ch;
            // Convert uppercase to lowercase
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';

            // Count only lowercase letters
            if (ch >= 'a' && ch <= 'z')
                freq[ch - 'a']++;
        }
        file.close();


    }

    // Step 2: Create leaf nodes for each character
    int createLeafNodes(int freq[], const string& filename) {
        int nextFree = 0;
        bool used[26] = {false};

        ifstream file(filename);

        char ch;
       // for (int i = 0; i < 26; ++i) {
          //  if (freq[i] > 0) {
        while (file.get(ch)) {
            if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
            if (ch >= 'a' && ch <= 'z' && freq[ch-'a'] > 0 && !used[ch-'a']) {
                charArr[nextFree] = ch;
                // weightArr[nextFree] = freq[i];
                weightArr[nextFree] = freq[ch-'a'];
                leftArr[nextFree] = -1;
                rightArr[nextFree] = -1;
                used[ch-'a'] = true;
                nextFree++;
            }
            }


    file.close();
    return nextFree;

     }

    //Step 3: Build encoding tree using your heap
    int buildEncodingTree(int nextFree) {

        // 1. Create a MinHeap object.
        MinHeap heap;
        // 2. Push all leaf node indices into the heap.
        for (int i = 0; i < nextFree; i++)
            heap.push(i, weightArr);
        // I used a for loop so it can do continously

        // 3. While the heap size is greater than 1:
        while (heap.size > 1) {
            int i1 = heap.pop(weightArr); //smallest node idx
            int i2 = heap.pop(weightArr); //smallest node idx besides i1
            //    - Pop two smallest node

            weightArr[nextFree] = weightArr[i1] + weightArr[i2];
            leftArr[nextFree] = i1;
            rightArr[nextFree] = i2;
            charArr[nextFree] = '*';
            //    - Create a new parent node with combined weight
            heap.push(nextFree, weightArr);
            nextFree++;
        }
        //    - Set left/right pointers
        //    - Push new parent index back into the heap
        return heap.size == 1 ? heap.pop(weightArr): -1;
        // 4. Return the index of the last remaining node (root)
        return -1; // placeholder
    }

    // Step 4: Use an STL stack to generate codes
    void generateCodes(int root, string codes[]) {
        if (root == -1)  return;

        stack<pair<int , string>> stack;
        stack.push({root, ""}); //empty root
        // Use stack<pair<int, string>> to simulate DFS traversal.
        while (!stack.empty()) {
            auto [node, code] = stack.top();
            stack.pop();

            // Left edge adds '0', right edge adds '1'.
            if (leftArr[node] == -1 && rightArr[node] == -1 && codes && charArr[node]
                >= 'a' && charArr[node] <= 'z') {
                codes[charArr[node] - 'a']  = code;
            } else {
                if (leftArr[node] != -1)
                {
                    stack.push({leftArr[node], code + "0"});

                }
                if (rightArr[node] != -1) {
                    stack.push({rightArr[node], code + "1"});

                }
            }



        }

        // Left edge adds '0', right edge adds '1'.


        // Record code when a leaf node is reached.
    }

    // Step 5: Print table and encoded message
    void encodeMessage(const string& filename, string codes[]) {
        cout << "\nCharacter : Code\n";
        for (int i = 0; i < 26; ++i) {
            if (!codes[i].empty())
                cout << char('a' + i) << " : " << codes[i] << "\n";
        }

        cout << "\nEncoded message:\n";

        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: could not open " << filename << "\n";
            exit(1);
        }
        cout << "Opened file " << filename << "\n";
        char ch;
        while (file.get(ch)) {
          //  cout << ch;
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
            if (ch >= 'a' && ch <= 'z')
                cout << codes[ch - 'a'];
        }
        cout << "\n";
        file.close();
    }